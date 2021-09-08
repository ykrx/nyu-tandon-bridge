#include <iostream>
using namespace std;

int main() {
    string name;
    int gradYear, currentYear, difference;
    string status;

    /* Input */
    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    cin >> gradYear;

    cout << "Please enter current year: ";
    cin >> currentYear;

    /* Calculations */
    difference = gradYear - currentYear;

    if (difference > 4) {
        status = "Not in college yet";
    }else if (difference == 4) {
        status = "Freshman";
    }else if (difference == 3) {
        status = "Sophomore";
    }else if (difference == 2) {
        status = "Junior";
    }else if (difference == 1) {
        status = "Senior";
    }else if (difference <= 0) {
        status = "Graduated";
    }

    /* Output */
    cout << name << ", you are a " << status;

    return 0;
}
