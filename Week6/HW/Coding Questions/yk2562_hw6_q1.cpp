#include <iostream>

int fib(int n);

int main() {
    int num = 0;

    while (num < 1) {
        std::cout << "Please enter a positive integer: ";
        std::cin >> num;
    }

    std::cout << fib(num);

    return 0;
}

/* Returns n-th element of the Fibonacci sequence */
int fib(int n) {
    int fn; // Next element in sequence
    int f0 = 1; // fn - 2 element of sequence
    int f1 = 0; // fn - 1 element of sequence

    for (int i = 0; i < n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }

    return fn;
}
