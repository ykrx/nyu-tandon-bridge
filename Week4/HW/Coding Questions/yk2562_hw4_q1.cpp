#include <iostream>
using namespace std;

int main() {
    int inputA = -1, inputB = -1; // initialized to -1 to trigger positive integer check loops
    int j = 0;
    int outputA = 2, outputB = 2; // initialized to first positive even number, ie: 2

    /*
     * Section A: for-loop Implementation
    */

    cout << "section a" << endl;

    /* Input A (loop to check for positive input) */
    while (inputA < 1) {
        cout << "Please enter a positive integer: ";
        cin >> inputA;
    }

    /* Output A */
    for (int i = 0; i < inputA; i++) {
        cout << outputA;
        cout << endl;

        outputA += 2;
    }

    /*
     * Section B: while-loop Implementation
    */

    cout << "section b" << endl;

    /* Input B (loop to check for positive input) */
    while (inputB < 1) {
        cout << "Please enter a positive integer: ";
        cin >> inputB;
    }

    /* Output B */
    while (j < inputB) {
        cout << outputB;
        cout << endl;

        outputB += 2;
        j++;
    }

    return 0;
}
