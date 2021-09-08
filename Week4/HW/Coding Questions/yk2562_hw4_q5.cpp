#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n = -1; // initialized to -1 to trigger positive check loop
    int maxLines, maxAsterisksPerLine, asterisksPerLine, difference;
    int lineNumber = 1;
    string lineString;

    /* Input (loop to check for positive n input) */
    while (n < 1) {
        cout << "Please enter a positive integer: ";
        cin >> n;
    }

    maxLines = 2 * n;
    maxAsterisksPerLine = maxLines - 1;
    asterisksPerLine = maxAsterisksPerLine; // initialized to max for first line

    for (int i = 0; i < maxLines; i++, lineNumber++) {
        lineString = ""; // reset new line

        /* For rendering asterisks
         * Takes absolute value of asterisksPerLine to treat negative values as positive values
        */
        for (int j = 0; j < abs(asterisksPerLine); j++) {
            lineString += "*";
        }

        difference = maxAsterisksPerLine - asterisksPerLine;
        asterisksPerLine -= 2;

        /* For centering asterisks, ie: padding with ' ' */
        if (difference != 0) {
            if (lineNumber <= (maxLines / 2)) {
                // Upper half of hourglass
                for (int k = 0; k < difference / 2; k++) {
                    lineString.insert(0, 1, ' '); // append space before asterisks
                    lineString.insert(lineString.length(), 1, ' '); // append space after asterisks
                }
            }else {
                // Lower half of hourglass
                for (int k = maxLines - 1; k > difference / 2; k--) {
                    lineString.insert(0, 1, ' '); // append space before asterisks
                    lineString.insert(lineString.length(), 1, ' '); // append space after asterisks
                }
            }
        }

        /* Output */
        cout << lineString;
        cout << endl;
    }

    return 0;
}
