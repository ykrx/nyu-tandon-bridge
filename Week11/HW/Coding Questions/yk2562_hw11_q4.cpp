/*
 * Yulian Kraynyak
 * yk2562
 * HW11
 * Question 4
 *
 * Sum of path finder using recursion.
*/

#include <iostream>
using namespace std;

/* Constants */
const int SIZE = 8;
const int STARTING_COLUMN = 0;

/* Function Prototypes */
int findSumOfPath(int *arr, int arrSize);

/* Main */
int main() {
    int arr[SIZE] = { 0, 50, 51, 52, 53, 54, 55, 56 } ;

    cout << findSumOfPath(arr, SIZE);
    return 0;
}

/* Functions */
int findSumOfPath(int *arr, int arrSize) {
    if (arrSize == 1) {
        // BASE CASE: One number in array
        //  * Return first number as "sum", ie: 0
        //    (One number means we're on the starting column)
        return arr[arrSize - 1];
    }else {
        int current = arr[arrSize - 1];
        int previous = arr[arrSize - 2];
        // RECURSIVE CASE: Two or more numbers in array
        //  * If CURRENT number is greater than the PREVIOUS number,
        //    call self with arrSize - 2 (looking back two numbers
        //    since we now know that the previous number is good),
        //    and add it to the PREVIOUS number.
        //  * Also: If arrSize is original size (aka final square) -> add
        //    the current square to the sum.
        if (previous < current) {
            if (arrSize == SIZE) {
                return findSumOfPath(arr, arrSize - 2) + previous + current;
            }else {
                return findSumOfPath(arr, arrSize - 2) + previous;
            }
        }else {
            //  * If current number is smaller than the previous number,
            //    call self with arrSize - 1 (looking back one number),
            //    and add it to the CURRENT number.
            return findSumOfPath(arr, arrSize - 1) + current;
        }
    }
}