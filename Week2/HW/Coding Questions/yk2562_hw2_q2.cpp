#include <iostream>
using namespace std;

const int NICKEL_VALUE = 5;
const int DIME_VALUE = 10;
const int QUARTER_VALUE = 25;
const int DOLLAR_VALUE = 100;

int main() {
    int dollars = -1, cents = 0; // Dollars initialized to -1 to trigger positive-integer check loop
    int quarters, dimes, nickels, pennies, valueInPennies;

    while (dollars < 0 || cents < 0) {
        cout<<"Please enter your amount in the format of dollars and cents separated by a space: "<<endl;
        cin>>dollars>>cents;
    }

    /* Calculations */
    valueInPennies = (dollars * DOLLAR_VALUE) + cents;
    quarters = valueInPennies / QUARTER_VALUE;
    dimes = (valueInPennies % QUARTER_VALUE) / DIME_VALUE;
    nickels = ((valueInPennies % QUARTER_VALUE) % DIME_VALUE) / NICKEL_VALUE;
    pennies = valueInPennies % NICKEL_VALUE;

    /* Output */
    cout<<dollars<<" dollars and ";
    cout<<cents<<" cents are: ";
    cout<<endl;

    cout<<quarters<<" quarters, ";
    cout<<dimes<<" dimes, ";
    cout<<nickels<<" nickels, and ";
    cout<<pennies<<" pennies";
    cout<<endl;

    return 0;
}
