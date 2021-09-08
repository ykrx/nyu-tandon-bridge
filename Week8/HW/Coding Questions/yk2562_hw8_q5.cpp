/*
 * Yulian Kraynyak
 * yk2562
 * HW8
 * Question 5
 *
 * Name formatter.
*/

#include <iostream>
#include <string>

using namespace std;

/* Function Prototypes */
string formatName(string firstName, string middleName, string lastName);

/* Main */
int main() {
    string firstName, middleName, lastName;

    cout << "Please enter your name (First, Middle, Last):\n";
    cin >> firstName >> middleName >> lastName;
    cout << formatName(firstName, middleName, lastName);
    return 0;
}

/* Functions */
string formatName(string firstName, string middleName, string lastName) {
    string formattedName, middleInitial;

    middleInitial = middleName.substr(0, 1);
    formattedName += lastName + ", " + firstName + " " + middleInitial + ".";
    return formattedName;
}