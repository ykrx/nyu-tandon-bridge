#include <iostream>
#include <vector>
int main() {
    std::vector<int> a{2, 3, 4, 1, -2};
    int n = a.size();
    int p = 1;
    int i = 0;
    int j = n;

    int iCount = 0;
    int jCount = 0;
    int swapCount = 0;

    while (i < j) {
        while (i < j && a[i] < p) {
            i = i + 1;
            iCount++;
        }

        while (i < j && a[j] >= p) {
            j = j - 1;
            jCount++;
        }

        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            swapCount++;
        }
    }

    std::cout << "n: " << n << "\n";
    std::cout << "iCount: " << iCount << "\n";
    std::cout << "jCount: " << jCount << "\n";
    std::cout << "swapCount: " << jCount << "\n\n";

    for (int &it : a) {
        std::cout << " " << it;
    }

    return 0;
}