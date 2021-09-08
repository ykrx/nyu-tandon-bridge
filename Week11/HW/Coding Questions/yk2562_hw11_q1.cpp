/*
 * Yulian Kraynyak
 * yk2562
 * HW11
 * Question 1
 *
 * Pattern printing using recursion.
*/

#include <iostream>
using namespace std;

/* Constants */
const char ASTERISK = '*';
const char DASH = '-';

/* Function Prototypes */
void partA(int input);
void partB(int input);
void partC(int input);
void handleInput(int& input);
void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

/* Main */
int main() {
    int input = -1;

    partA(input);
    partB(input);
    partC(input);
    return 0;
}

/* Functions */
void partA(int input) {
    cout << "PART A:\n";
    handleInput(input);
    printTriangle(input);
    cout << endl;
}

void partB(int input) {
    cout << "PART B:\n";
    handleInput(input);
    printOppositeTriangles(input);
    cout << endl;
}

void partC(int input) {
    cout << "PART C:\n";
    handleInput(input);
    printRuler(input);
    cout << endl;
}

void handleInput(int& input) {
    while (input < 1) {
        cout << "Enter a positive number: ";
        cin >> input;
    }
}

void printTriangle(int n) {
    if (n == 1) {
        // BASE CASE: n == 1
        cout << ASTERISK;
    }else {
        // RECURSIVE CASE: n > 1
        //  * Call self until base case is hit
        printTriangle(n - 1);
        //  * Then start printing incrementing rows of asterisks,
        //    (starting with the base case of 1)
        for (int i = 0; i < n; i++) {
            cout << ASTERISK;
        }
    }
    cout << endl;
}

void printOppositeTriangles(int n) {
    if (n == 1) {
        // BASE CASE: n == 1
        //  * Print smallest possible opposite triangles.
        //    (Both of size 1)
        cout << ASTERISK << endl;
        cout << ASTERISK << endl;
    }else {
        // RECURSIVE CASE: n > 1
        //   1. First print row of top triangle, with n asterisks.
        for (int i = 0; i < n; i++) {
            cout << ASTERISK;
        }
        cout << endl;
        //   2. Call self until base case is hit.
        printOppositeTriangles(n - 1);
        //  3. Once base case reached, print row of bottom triangle
        //     with n asterisks. (Which will increment as we move
        //     back down the stack to the "parent" function
        //     [which has an n of n + 1])
        for (int i = 0; i < n; i++) {
            cout << ASTERISK;
        }
        cout << endl;
    }
}

void printRuler(int n) {
    if (n == 1) {
        // BASE CASE: n == 1
        cout << DASH << endl;
    }else {
        // RECURSIVE CASE: n > 1
        //   1. First, call self until base case is hit.
        printRuler(n - 1);
        //   2. Then, print n dashes each recursion (increasing
        //      since we're starting from the base case of 1).
        for (int i = 0; i < n; i++) {
            cout << DASH;
        }
        cout << endl;
        //   3. Finally, call self again to "reverse" the print
        //      operation, printing the dashes in decreasing
        //      order, until the base case.
        printRuler(n - 1);
    }
}