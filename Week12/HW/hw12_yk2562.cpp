/* Yulian Kraynyak
 * yk2562
 * HW12
 *
 * Checkbook system implementation using classes and inheritance.
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

/* Constants */
const int CENTS_IN_DOLLAR = 100;
const char PERIOD_SYMBOL = '.';
const char SPACE_SYMBOL = ' ';
const char DOLLAR_SYMBOL = '$';
const int PERIOD_SYMBOL_OFFSET = 1;
const int DOLLAR_SYMBOL_OFFSET = 1;
const int SPACE_SYMBOL_OFFSET = 1;

/* Classes */
class Money {
public:
    Money(long dollars, int cents) { all_cents = dollars * CENTS_IN_DOLLAR + cents; };
    Money(long dollars) { all_cents = dollars * CENTS_IN_DOLLAR; };
    Money() { all_cents = 0; };

    double get_value() const;
    friend Money operator +(const Money& amount1, const Money& amount2) {
        return Money(0, CENTS_IN_DOLLAR * amount1.get_value() + CENTS_IN_DOLLAR * amount2.get_value());
    };
    friend Money operator -(const Money& amount1, const Money& amount2) {
        return amount1.get_value() - amount2.get_value();
    };
    friend bool operator ==(const Money& amount1, const Money& amount2) {
        return amount1.get_value() == amount2.get_value();
    };
    friend bool operator <(const Money& amount1, const Money& amount2);
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, Money& amount) {
        outs << "$" << amount.get_value();
        return outs;
    };
private:
    long all_cents;
};

double Money::get_value() const {
    return (double)all_cents / CENTS_IN_DOLLAR;
}

class Check {
public:
    Check(int number, Money amount, const string& wasCashed) {
        this->number = number;
        this->amount = amount;
        this->wasCashed = wasCashed == "yes" || wasCashed == "YES" || wasCashed == "y" || wasCashed == "Y";
    };

    friend ostream& operator <<(ostream& outs, Check& check) {
        outs << check.get_amount().get_value() << " :: check #" << check.get_number();
        return outs;
    };
    int get_number() const;
    Money get_amount() const;
    bool get_wasCashed() const;
private:
    int number;
    Money amount;
    bool wasCashed;
};

int Check::get_number() const {
    return number;
}

Money Check::get_amount() const {
    return amount;
}

bool Check::get_wasCashed() const {
    return wasCashed;
}

/* Function Prototypes */
void handleInput(vector<Money>& deposits, vector<Check>& checks, Money& balanceOld, Money& balanceNew);
void handleDepositsInput(Money& balanceOld, Money& balanceNew, vector<Money>& deposits);
void handleCheckInput(vector<Check>& checks, int& number, Money& amount, string& wasCashed);
Money stringToMoney(string str);
void calculateBalance(const vector<Money>& deposits, const vector<Check>& checks, Money balanceOld);
void printChecks(const vector<Check>& checks);
void processDepositsString(string depositsString, vector<Money>& deposits);

/* Main */
int main() {
    vector<Check> checks;
    vector<Money> deposits;
    Money balanceOld;
    Money balanceNew;

    handleInput(deposits, checks, balanceOld, balanceNew);
    calculateBalance(deposits, checks, balanceOld);
//    printChecks(checks);
    return 0;
}

void handleInput(vector<Money>& deposits, vector<Check>& checks, Money& balanceOld, Money& balanceNew) {
    int number = -1;
    Money amount;
    string wasCashed;

    cout << "CHECKBOOK" << endl;
    cout << "Hints:\n- Amounts can be entered as $x.xx, x.xx, $x or x\n- Questions can be answered as yes/no or y/n" << endl;
    cout << endl;

    handleDepositsInput(balanceOld, balanceNew, deposits);
    handleCheckInput(checks, number, amount, wasCashed);
}

void handleDepositsInput(Money& balanceOld, Money& balanceNew, vector<Money>& deposits) {
    string balanceOldString;
    string depositsString;
    string balanceNewString;

    cout << "Enter old balance: ";
    getline(cin, balanceOldString);
    balanceOld = stringToMoney(balanceOldString);

    cout << "Enter new deposits (separated by a space): ";
    getline(cin, depositsString);
    processDepositsString(depositsString, deposits);
}

void processDepositsString(string depositsString, vector<Money>& deposits) {
    vector<string> stringVector;
    int currentIndex = 0;
    int length = depositsString.length();

    for (int i = 0; i < depositsString.length(); i++) {
        if (i == length - 1) {
            // Last item
            stringVector.push_back(depositsString.substr(currentIndex, length));
        }else {
            if (depositsString[i] == SPACE_SYMBOL) {
                stringVector.push_back(depositsString.substr(currentIndex, i - currentIndex));
                currentIndex = i + SPACE_SYMBOL_OFFSET;
            }
        }
    }
    for (const string& i : stringVector) {
        deposits.push_back(stringToMoney(i));
    }
}

void handleCheckInput(vector<Check>& checks, int& number, Money& amount, string& wasCashed) {
    string amountString;
    string anotherCheck;
    bool active = true;
    int counter = 0;

    while (active) {
        cout << endl;
        if (counter == 0) {
            cout << "Entering a check?: ";
            cin >> anotherCheck;
            cout << endl;

            if (anotherCheck == "no" || anotherCheck == "NO" || anotherCheck == "n" || anotherCheck == "N") {
                break;
            }
        }
        counter++;

        cout << "Enter check number: ";
        cin >> number;

        cout << "Enter check amount: ";
        cin.ignore();
        getline(cin, amountString);
        amount = stringToMoney(amountString);

        cout << "Was this check cashed?: ";
        cin >> wasCashed;
        cout << endl;

        checks.push_back(Check(number, amount, wasCashed));

        cout << "Entering another check?: ";
        cin >> anotherCheck;

        if (anotherCheck == "no" || anotherCheck == "NO" || anotherCheck == "n" || anotherCheck == "N") {
            active = false;
        }
    }
}

Money stringToMoney(string str) {
    /*
     * Parses dollars and cents from string
     * and returns a Money object of that str.
     * ex: $1.23 = Money(1, 23)
     * Handles dollar signs '$', and missing periods '.'
    */

    long dollars = 0;
    int cents = 0;
    int startIndex = 0;
    bool periodExists = false;

    for (char i : str) {
        if (i == DOLLAR_SYMBOL) {
            startIndex = DOLLAR_SYMBOL_OFFSET;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == PERIOD_SYMBOL) {
            str += '0'; // pads with a '0' to address cases where input is something like '1.3'. Makes it '1.30'.
            periodExists = true;
            dollars = stoi(str.substr(startIndex, i));
            cents = stoi(str.substr(i + PERIOD_SYMBOL_OFFSET, 2));
        }
    }
    if (!periodExists) {
        dollars = stoi(str.substr(startIndex, str.length() - startIndex));
        cents = 0;
    }
    return {dollars, cents};
}

void calculateBalance(const vector<Money>& deposits, const vector<Check>& checks, Money balanceOld) {
    Money totalNewDeposits;
    Money totalInCashedChecks;
    Money totalInNotYetCashedChecks;
    Money diffBank;
    Money diffCustomer;
    Money difference;
    int cashedChecksCount = 0;
    int notYetCashedChecksCount = 0;

    cout << "SUMMARY:" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Old balance: " << balanceOld << endl;
    cout << endl;

    if (!deposits.empty()) {
        cout << "New deposits: " << endl;

        for (Money deposit : deposits) {
            totalNewDeposits = totalNewDeposits + deposit;
            cout << "+ " << deposit << endl;
        }
        cout << "Total new deposits: " << totalNewDeposits;
        cout << endl << endl;
    }else {
        cout << "No new deposits.";
        cout << endl << endl;
    }
    for (Check check : checks) {
        if (check.get_wasCashed()) {
            cashedChecksCount++;
        }else {
            notYetCashedChecksCount++;
        }
    }
    if (cashedChecksCount > 0) {
        cout << "Cashed checks: ";
        cout << endl;

        for (Check check : checks) {
            if (check.get_wasCashed()) {
                cashedChecksCount++;
                totalInCashedChecks = totalInCashedChecks + check.get_amount();
                cout << "- $" << check << endl;
            }
        }
        cout << "Total in cashed checks: " << totalInCashedChecks;
        cout << endl << endl;
    }else {
        cout << "No cashed checks.";
        cout << endl << endl;
    }
    if (notYetCashedChecksCount > 0) {
        cout << "Not-yet-cashed checks: ";
        cout << endl;
        for (Check check : checks) {
            if (!check.get_wasCashed()) {
                totalInNotYetCashedChecks = totalInNotYetCashedChecks + check.get_amount();
                cout << "  $" << check << endl;
            }
        }
        cout << "Total in not-yet-cashed checks: " << totalInNotYetCashedChecks;
        cout << endl << endl;
    }else {
        cout << "No not-yet-cashed checks.";
        cout << endl << endl;
    }

    // Customer balance is: old balance + deposits - checks written by the customer that were cashed
    diffCustomer = balanceOld + totalNewDeposits - totalInCashedChecks;
    // Bank balance is: old balance + deposits - checks written by the customer that were cashed + checks written by the customer that were NOT yet cashed (since bank does NOT know about them until they're cashed by the check recipient)
    diffBank = balanceOld + totalNewDeposits - totalInCashedChecks + totalInNotYetCashedChecks;
    // So the difference between the customer balance and bank balance is the total in checks written by the customer that were not yet cashed by recipients.
    difference = diffBank - diffCustomer;

    cout << "New balance (Customer): " << diffCustomer << endl;
    cout << "New balance (Bank): " << diffBank << endl;
    cout << "Difference (Net): $" << abs(difference.get_value()) << endl;
}