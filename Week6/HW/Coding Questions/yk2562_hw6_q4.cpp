#include <iostream>
#include <cmath>
#include <string>

void printDivisors(int num);

int main() {
    int num = 0;

    while (num < 2) {
        std::cout << "Please enter a positive integer >=2: ";
        std::cin >> num;
    }

    printDivisors(num);

    return 0;
}

void printDivisors(int num) {
    double squareRoot = sqrt(num);
    std::string firstDivisors; // divisors from 1 to squareRoot
    std::string lastDivisors; // divisors from squareRoot to num

    for (int i = 1; i <= squareRoot; i++) {
        if (num % i == 0) {
            // Step 1: Find the firstDivisors normally.
            firstDivisors += std::to_string(i) + " ";

            // Step 2: Find the lastDivisors by dividing num by each "first divisor",
            // and prefixing the resulting value to the lastDivisors string.
            if (i != squareRoot) { // to prevent duplicate middle divisor
                lastDivisors.insert(0, std::to_string(num / i) + " ");
            }
        }
    }

    std::cout << firstDivisors << lastDivisors;
}