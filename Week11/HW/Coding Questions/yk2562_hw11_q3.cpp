/*
 * Yulian Kraynyak
 * yk2562
 * HW11
 * Question 3
 *
 * Recursive algorithms to find minimum in an entire array, and in a range.
*/

#include <iostream>
using namespace std;

/* Function Prototypes */
int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

/* Main */
int main() {
    int arr[10] = {9, -2, 14, 1, 3, 0, 2, 1, -9, -15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << " " << res2 << endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
    cout << res3 << " " << res4 << endl; //should both be 3
    return 0;
}

/* Functions */
int minInArray1(int arr[], int arrSize) {
    if (arrSize == 1) {
        // BASE CASE: One element in array
        //  * The min of one number is the number itself.
        return arr[arrSize - 1];
    }else {
        // RECURSIVE CASE: Two or more numbers in array
        //   1. Call self with arrSize - 1, and save result.
        int min = minInArray1(arr, arrSize - 1);
        //   2. Check if current number is smaller than previous number.
        //      If so, return current number (used as the next min
        //      in the next recursion down the stack), otherwise,
        //      the previous number remains the min.
        if (arr[arrSize - 1] < min) {
            return arr[arrSize - 1];
        }else {
            return min;
        }
    }
}

int minInArray2(int arr[], int low, int high) {
    if (high - low == 1) {
        // BASE CASE: ending index - starting index == 1, ie: one number
        //  * The min of one number is the number itself.
        return arr[low];
    }else {
        // RECURSIVE CASE: ending index - starting index > 1
        //   1. Call self with high - 1, and save result.
        //      (high - 1 means we're moving backwards through
        //      the range of numbers; similar to arrSize - 1)
        int min = minInArray2(arr, low, high - 1);
        //   2. Then, if the number at ending index is less than
        //      the previous number (min), return current number,
        //      otherwise, return previous number.
        if (arr[high - 1] < min) {
            return arr[high - 1];
        }else {
            return min;
        }
    }
}