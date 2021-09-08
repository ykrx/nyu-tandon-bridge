#include <iostream>
using namespace std;

const int NICKEL_VALUE = 5;
const int DIME_VALUE = 10;
const int QUARTER_VALUE = 25;
const int DOLLAR_VALUE = 100;

int main() {
    int quarters = -1, dimes = -1, nickels = -1, pennies = -1; // initialized to -1 to trigger positive-integer check loops
    int valueInPennies, dollars, cents;

    /* Input prompts */
    cout<<"Please enter number of coins: "<<endl;

    while (quarters < 0) {
        cout<<"# of quarters: ";
        cin>>quarters;
    }

    while (dimes < 0) {
        cout<<"# of dimes: ";
        cin>>dimes;
    }

    while (nickels < 0) {
        cout<<"# of nickles: ";
        cin>>nickels;
    }

    while (pennies < 0) {
        cout<<"# of pennies: ";
        cin>>pennies;
    }

    /* Calculations */
    valueInPennies = (quarters * QUARTER_VALUE) + (dimes * DIME_VALUE) + (nickels * NICKEL_VALUE) + pennies;
    dollars = valueInPennies / DOLLAR_VALUE;
    cents = valueInPennies % DOLLAR_VALUE;

    /* Output */
    cout<<"The total is ";
    cout<<dollars<<" dollars"<<" and ";
    cout<<cents<<" cents";
    cout<<endl;

    return 0;
}
