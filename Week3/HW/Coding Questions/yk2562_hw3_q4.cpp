#include <iostream>
using namespace  std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double realNumber, rounded;
    int roundingMethod;

    /* Input */
    cout << "Please enter a Real number:" << endl;
    cin >> realNumber;
    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> roundingMethod;

    /* Calculations */
    switch (roundingMethod) {
        case FLOOR_ROUND:
            // casts realNumber to int, which effectively floor rounds it. Subtracts 1 if realNumber is < 0
            if (realNumber < 0) {
                rounded = -int(-realNumber) - 1;
            }else {
                rounded = int(realNumber);
            }

            break;
        case CEILING_ROUND:
            // same as for floor round, but adds 1 to realNumber first to round to one integer higher
            if (realNumber + 1 < 0) {
                rounded = -int(-realNumber + 1) - 1;
            }else {
                rounded = int(realNumber + 1);
            }

            break;
        case ROUND:
            // adding 0.5 ensures numbers are rounded off instead of the decimal part just being truncated
            rounded = (int)(realNumber + 0.5);

            break;
        default:
            break;
    }

    /* Output */
    cout << rounded;

    return 0;
}
