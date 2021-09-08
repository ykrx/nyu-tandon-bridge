#include <iostream>
using namespace std;

const int HOURS_IN_DAY = 24;
const int MINUTES_IN_HOUR = 60;

int main() {
    /* Initialized to -1 to trigger positive-integer check loops */
    int daysJohn = -1, daysBill = -1, hoursJohn = -1;
    int hoursBill = -1, minutesJohn = -1, minutesBill = -1;
    int totalMinutesJohn, totalMinutesBill, totalMinutes;
    int days, hours, minutes;

    /* John prompts */
    while (daysJohn < 0) {
        cout<<"Please enter the number of days John has worked: ";
        cin>>daysJohn;
    }

    while (hoursJohn < 0) {
        cout<<"Please enter the number of hours John has worked: ";
        cin>>hoursJohn;
    }

    while (minutesJohn < 0) {
        cout<<"Please enter the number of minutes John has worked: ";
        cin>>minutesJohn;
    }

    /* Bill prompts */
    while (daysBill < 0) {
        cout<<endl;
        cout<<"Please enter the number of days Bill has worked: ";
        cin>>daysBill;
    }

    while (hoursBill < 0) {
        cout<<"Please enter the number of hours Bill has worked: ";
        cin>>hoursBill;
    }

    while (minutesBill < 0) {
        cout<<"Please enter the number of minutes Bill has worked: ";
        cin>>minutesBill;
    }

    /* Calculations */
    totalMinutesJohn = (daysJohn * HOURS_IN_DAY * MINUTES_IN_HOUR) + (hoursJohn * MINUTES_IN_HOUR) + minutesJohn;
    totalMinutesBill = (daysBill * HOURS_IN_DAY * MINUTES_IN_HOUR) + (hoursBill * MINUTES_IN_HOUR) + minutesBill;
    totalMinutes = totalMinutesJohn + totalMinutesBill;

    days = totalMinutes / MINUTES_IN_HOUR / HOURS_IN_DAY;
    hours = ((totalMinutes / MINUTES_IN_HOUR) % HOURS_IN_DAY);
    minutes = (totalMinutes % MINUTES_IN_HOUR);

    /* Output */
    cout<<endl;
    cout<<"The total time both of them worked together is: ";
    cout<<days<<" days, ";
    cout<<hours<<" hours, ";
    cout<<minutes<<" minutes.";
    cout<<endl;

    return 0;
}