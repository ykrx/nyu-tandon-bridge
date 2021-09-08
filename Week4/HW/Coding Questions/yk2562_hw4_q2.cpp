#include <iostream>
#include <string>
using namespace std;

const int M_VALUE = 1000;
const int D_VALUE = 500;
const int C_VALUE = 100;
const int L_VALUE = 50;
const int X_VALUE = 10;
const int V_VALUE = 5;
const int I_VALUE = 1;

int main() {
    int decimalNumber = -1; // initialized to -1 to trigger positive integer check loop
    int number;
    string romanNumeral;

    /* Input (loop to check for positive input) */
    while (decimalNumber < 1) {
        cout << "Enter decimal number:";
        cout << endl;
        cin >> decimalNumber;
    }

    /* Calculations */
    number = decimalNumber;

    while (number > 0) {
        if (number / M_VALUE > 0) {
            romanNumeral += "M";
            number -= M_VALUE;
        }else if (number / D_VALUE > 0) {
            romanNumeral += "D";
            number -= D_VALUE;
        }else if (number / C_VALUE > 0) {
            romanNumeral += "C";
            number -= C_VALUE;
        }else if (number / L_VALUE > 0) {
            romanNumeral += "L";
            number -= L_VALUE;
        }else if (number / X_VALUE > 0) {
            romanNumeral += "X";
            number -= X_VALUE;
        }else if (number / V_VALUE > 0) {
            romanNumeral += "V";
            number -= V_VALUE;
        }else if (number / I_VALUE > 0) {
            romanNumeral += "I";
            number -= I_VALUE;
        }
    }

    /* Output */
    cout << decimalNumber << " is " << romanNumeral;

    return 0;
}
