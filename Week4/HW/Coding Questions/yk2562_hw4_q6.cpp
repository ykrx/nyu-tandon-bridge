#include <iostream>
using namespace std;

int main() {
    int n = -1; // initialized to -1 to trigger positive integer check loop
    int digit;
    int j;
    int evenCount, oddCount;

    /* Input (loop to check for positive n input) */
    while (n < 0) {
        cout << "Please enter a positive integer: ";
        cin >> n;
    }

    for (int i = 1; i <= n; i++) {
        evenCount = 0;
        oddCount = 0;

        j = i;

        // loop through j's digits to count total # of even/odd digits
        while (j > 0) {
            digit = j % 10;
            j /= 10;

            if (digit % 2) {
                // digit is odd
                oddCount++;
            } else {
                // digit is even
                evenCount++;
            }
        }

        /* Output */
        if (evenCount > oddCount) {
            cout << i;
            cout << endl;
        }
    }

    return 0;
}
