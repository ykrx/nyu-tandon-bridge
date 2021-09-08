#include <iostream>

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    int numberOfTriangles = 0;
    char symbol;

    while (numberOfTriangles < 1) {
        std::cout << "Enter number of triangles: ";
        std::cin >> numberOfTriangles;
    }

    std::cout << "Enter a symbol: ";
    std::cin >> symbol;
    std::cout << "\n";

    printPineTree(numberOfTriangles, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 0; i < n; i++) {
        // Margin from left
        for (int j = 0; j < m; j++) {
            std::cout << " ";
        }

        // Spaces before symbols
        for (int j = n - i; j > 1; j--) {
            std::cout << " ";
        }

        // Symbols per row
        for (int j = 0; j < 2 * i + 1; j++) {
            std::cout << symbol;
        }

        std::cout << "\n";
    }
}

void printPineTree(int n, char symbol) {
    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(2 + i - 1, n - i, symbol);
    }
}
