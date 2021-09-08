#include <iostream>

double eApprox(int n);

int main() {
    std::cout.precision(30);

    for (int n = 1; n <= 15; n++) {
        std::cout << "n = " << n << '\t' << eApprox(n) << std::endl;
    }

    return 0;
}

double eApprox(int n) {
    double e = 1;
    double factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        e += 1.0 / factorial;
    }

    return e;
}