#include <iostream>
#include <string>
#include <iomanip> // To round costOfCall to 2 decimal points
using namespace std;

const double WEEKDAY_REGULAR_RATE = 0.40;
const double WEEKDAY_DISCOUNT_RATE = 0.25;
const double WEEKEND_RATE = 0.15;

int main() {
    double costOfCall = 0;
    string dayOfTheWeek;
    char c; // empty variable to help parse hours:mins input
    int hourStarted, minuteStarted, numberOfMinutes = -1; // -1 to trigger positive integer check

    /* Input */
    cout << "Enter day of the week (in 2 characters, ex: Monday = Mo): ";
    cin >> dayOfTheWeek;

    cout << "Enter time the call started (in 24hr, HH:MM): ";
    cin >> hourStarted >> c >> minuteStarted;

    // loop to check for positive integer input
    while (numberOfMinutes < 0) {
        cout << "Enter the length of the call (in minutes): ";
        cin >> numberOfMinutes;
    }

    /* Calculations */
    if (dayOfTheWeek == "Mo" || dayOfTheWeek == "Tu" || dayOfTheWeek == "We" || dayOfTheWeek == "Th" || dayOfTheWeek == "Fr" ) {
        // Call started on Monday through Friday
        if (hourStarted >= 8 && hourStarted <= 18) {
            // Between 8:00 AM and 6:00 PM
            costOfCall = numberOfMinutes * WEEKDAY_REGULAR_RATE;
        }else if (hourStarted < 8 || hourStarted > 18) {
            // Before 8:00 AM or after 6:00 PM
            costOfCall = numberOfMinutes * WEEKDAY_DISCOUNT_RATE;
        }
    }else if (dayOfTheWeek == "Sa" || dayOfTheWeek == "Su") {
        // Call started on Saturday or Sunday
        costOfCall = numberOfMinutes * WEEKEND_RATE;
    }else {
        // Input not valid
    }

    /* Output */
    cout << "The cost of the call is: ";
    cout << "$" << fixed << setprecision(2) << costOfCall; // cost of call, rounded to 2 decimal points

    return 0;
}
