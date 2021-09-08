#include <iostream>
#include <cmath>
#include <string>

const int MINIMUM_INPUT_VALUE = 2;

void analyzeDivisors(int num, int& outCountDivs, int & outSumDivs);
bool isPerfect(int num);
void amicableCheck(int x, int M, std::string &amicableNumbers);

int main() {
    int M = 0;
    std::string perfectNumbers, amicableNumbers;

    while (M < MINIMUM_INPUT_VALUE) {
        std::cout << "Please enter a positive integer >=" << MINIMUM_INPUT_VALUE << ": ";
        std::cin >> M;
    }

    for (int i = MINIMUM_INPUT_VALUE; i <= M; i++) {
        if (isPerfect(i)) {
            perfectNumbers += std::to_string(i) + "\n";
        }else {
            amicableCheck(i, M, amicableNumbers);
        }
    }

    std::cout << std::endl;
    std::cout << "Perfect numbers between " << MINIMUM_INPUT_VALUE << " and " << M << ":\n" << perfectNumbers << "\n";
    std::cout << "Amicable number pairs between " << MINIMUM_INPUT_VALUE << " and " << M << ":\n" << amicableNumbers;

    return 0;
}

void analyzeDivisors(int num, int &outCountDivs, int &outSumDivs) {
    // Reset counts
    outCountDivs = 0;
    outSumDivs = 0;

    double squareRoot = sqrt(num);

    for (int i = 1; i < squareRoot; i++) {
        if (num % i == 0) {
            // Step 1: Find the 1 to squareRoot divisors
            outSumDivs += i;
            outCountDivs++;

            // Step 2: Find the squareRoot to num divisors
            //  - prevent duplicate middle divisor
            //  - and skip num as a divisor (because then it wouldn't be a proper divisor)
            if (i != squareRoot && i != 1) {
                outSumDivs += num / i;
                outCountDivs++;
            }
        }
    }
}

bool isPerfect(int num) {
    int count = 0;
    int sum = 0;

    analyzeDivisors(num, count, sum);

    return num == sum;
}

void amicableCheck(int x, int M, std::string &amicableNumbers) {
    int xCount = 0;
    int xSum = 0;
    int yCount = 0;
    int ySum = 0;

    analyzeDivisors(x, xCount, xSum);
    analyzeDivisors(xSum, yCount, ySum);

    if (x == ySum && xSum <= M && x < xSum) {
        /* Only considered an amicable number if:
         * 1. x is equal to the sum of divisors of y.
         * 2. The sum of divisors of x is <= M (to not show amicable pairs when xSum is out of range of 2 to M).
         *
         * (Last condition to prevent duplicate amicable number pairs)
        */
        amicableNumbers += std::to_string(x) + ", " + std::to_string(xSum) + "\n";
    }
}