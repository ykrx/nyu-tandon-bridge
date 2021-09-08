/*
 * Yulian Kraynyak
 * yk2562
 * HW11
 * Question 2
 *
 * Recursive algorithms to find the sum-of-squares of an array, and to determine whether an array is sorted.
*/

#include <iostream>
using namespace std;

/* Constants */
const int SIZE_A = 5;
const int SIZE_B = 7;

/* Function Prototypes */
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
int square(int n);

/* Main */
int main() {
    int arrA[SIZE_A] = {2, 6, 8, 9, 0};
    int arrB[SIZE_B] = {1, 2, 3, 4, 4, 6, 10};

    cout << "PART A: " << sumOfSquares(arrA, SIZE_A) << endl;
    cout << "PART B: " << boolalpha << isSorted(arrB, SIZE_B);
    return 0;
}

/* Functions */
int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 1) {
        // BASE CASE: One number in array
        //  * Get square of single number
        return square(arr[arrSize - 1]);
    }else {
        // RECURSIVE CASE: Two or more numbers in array
        //  * Call self with n - 1 until base case is hit.
        //    Then, add the result of the base case to the
        //    square of the current number.
        return sumOfSquares(arr, arrSize - 1) + square(arr[arrSize - 1]);
    }
}

int square(int n) {
    return n * n;
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize == 2) {
        // BASE CASE: Two numbers in array
        //  * Check if first number is \leq than the second.
        return arr[arrSize - 2] <= arr[arrSize - 1];
    }else {
        // RECURSIVE CASE: Three or more numbers in array
        //  * Start checking if numbers are sorted, starting
        //    from first (n-1, n-2, ...until base case is hit).
        if (isSorted(arr, arrSize - 1)) {
            //  * Hit once base case is reached.
            return arr[arrSize - 2] <= arr[arrSize - 1];
        }
    }
}