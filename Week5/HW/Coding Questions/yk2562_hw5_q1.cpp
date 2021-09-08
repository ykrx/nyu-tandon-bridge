#include <iostream>

int main() {
    int n = -1; // initialized to -1 to trigger positive integer check

    /* Input (loop to check for positive n input) */
    while (n < 0) {
        std::cout << "Please enter a positive integer: " << "\n";
        std::cin >> n;
    }

    /* Output */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << i * j << "\t";
        }

        std::cout << "\n";
    }

    return 0;
}
