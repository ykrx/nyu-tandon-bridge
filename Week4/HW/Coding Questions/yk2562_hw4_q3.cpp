#include <iostream>
using namespace std;

int main() {
    int input = -1; // initialized to -1 to trigger positive integer check loop
    // unsigned long long ints to represent larger input numbers
    unsigned long long int decimalNumber, binaryNumber = 0;
    unsigned long long int remainder;
    unsigned long long int multiplier = 1;

    /* Input (loop to check for positive input) */
    while (input < 0) {
        cout << "Enter decimal number:";
        cout << endl;
        cin >> input;
    }

    /* Calculations */
    decimalNumber = input;

    while (decimalNumber != 0) {
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * multiplier;
        multiplier *= 10; // to move on to the next multiple of 10 and handle proper binary representation order
    }

    /* Output */
    cout << "The binary representation of " << input << " is " << binaryNumber;

    return 0;
}
