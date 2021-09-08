#include <iostream>
#include <cmath>
using namespace std;

const int NO_REAL_SOLUTION = 0;
const int ONE_REAL_SOLUTION = 1;
const int TWO_REAL_SOLUTIONS = 2;
const int INFINITE_SOLUTIONS = 3;

int main() {
    double a, b, c;
    double discriminant;
    double x1, x2;
    int solutionsCase;

    /* Input */
    cout << "Please enter value of a: ";
    cin >> a;

    cout << "Please enter value of b: ";
    cin >> b;

    cout << "Please enter value of c: ";
    cin >> c;

    /* Calculations */
    discriminant = (b * b) - 4 * a * c;

    if (a == 0 && b == 0 && c == 0) {
        // infinite number of solutions
        solutionsCase = INFINITE_SOLUTIONS;
    }else if (discriminant > 0) {
        // roots are real & different
        solutionsCase = TWO_REAL_SOLUTIONS;

        x1 = (-b + (sqrt(discriminant))) / 2 * a;
        x2 = (-b - (sqrt(discriminant))) / 2 * a;
    }else if (discriminant == 0) {
        // roots are real & equal
        solutionsCase = ONE_REAL_SOLUTION;

        x1 = -b / (2 * a);
    }else {
        // discriminant less than zero, roots are not real
        solutionsCase = NO_REAL_SOLUTION;
    }

    /* Output */
    switch (solutionsCase) {
        case NO_REAL_SOLUTION:
            cout << "This equation has no real solution";
            break;
        case ONE_REAL_SOLUTION:
            cout << "This equation has one real solution " << "x=" << x1;
            break;
        case TWO_REAL_SOLUTIONS:
            cout << "This equation has two real solutions " << "x=" << x1 << " x=" << x2;
            break;
        case INFINITE_SOLUTIONS:
            cout << "This equation has an infinite number of solutions";
            break;
        default:
            break;
    }

    return 0;
}
