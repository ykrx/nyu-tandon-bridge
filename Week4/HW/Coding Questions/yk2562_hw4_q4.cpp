#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int lengthA = -1; // initialized to -1 to trigger positive integer check
    int lengthB = 0;
    int i = 0;
    int inputA, inputB;
    int sequenceAProduct = 1, sequenceBProduct = 1;
    double geometricMeanA, geometricMeanB;

    /*
     * Section A: Sequence Length Implementation
    */

    cout << "section a" << endl;

    /* Input A (loop to check for positive length input) */
    while (lengthA < 1) {
        cout << "Please enter the length of the sequence: ";
        cin >> lengthA;
    }

    cout << "Please enter your sequence:";
    cout << endl;

    /* Calculation A */
    while (i < lengthA) {
        cin >> inputA;
        sequenceAProduct *= inputA;
        i++;
    }

    geometricMeanA = pow((sequenceAProduct), (1.0 / lengthA));

    /* Output A */
    cout << "The geometric mean is: " << geometricMeanA;
    cout << endl;

    /*
     * Section B: Sequence '-1' Termination Implementation
    */

    cout << "section b" << endl;

    /* Input B */
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:";
    cout << endl;

    /* Calculation B */
    while (cin >> inputB, inputB != -1) {
        sequenceBProduct *= inputB;
        lengthB++;
    }

    geometricMeanB = pow((sequenceBProduct), (1.0 / lengthB));

    /* Output B */
    cout << "The geometric mean is: " << geometricMeanB;

    return 0;
}
