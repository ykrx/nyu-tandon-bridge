/*
 * Yulian Kraynyak
 * yk2562
 * HW10
 * Question 2
 *
 * Finds missing numbers in an integer array from 0 -> n.
*/

#include <iostream>

using namespace std;

/* Constants */
const int ARR_SIZE = 6;

//* Function Prototypes */
int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int arr[], int arrSize);

/* Main */
int main() {
    int arr[ARR_SIZE] = {3, 1, 3, 0, 6, 4};
    int* resArr;
    int resArrSize;

    resArr = findMissing(arr, 6, resArrSize);

    cout << "array: ";
    printArray(arr, ARR_SIZE);
    cout << "resArrSize: " << resArrSize << endl;
    cout << "missing numbers: ";
    printArray(resArr, resArrSize);

    delete [] resArr;
    resArr = nullptr;
    return 0;
}

/* Functions */
int* findMissing(int arr[], int n, int& resArrSize) {
    int* resArr = new int[ARR_SIZE];
    int comparisonArr[ARR_SIZE + 1];

    // Populate comparison array with { 0, ... to n }
    for (int i = 0; i < n + 1; i++) {
        comparisonArr[i] = 0;
    }
    // Log occurrences of each number
    for (int i = 0; i < ARR_SIZE; i++) {
        comparisonArr[arr[i]]++;
    }
    int index = 0;
    // Determine which numbers never occur
    for (int i = 0; i < ARR_SIZE + 1; i++) {
        if (comparisonArr[i] == 0) {
            resArr[index++] = i;
        }
    }
    resArrSize = index;
    return resArr;
}

void printArray(int arr[], int arrSize) {
    int lastIndex = arrSize - 1;

    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i];

        if (i != lastIndex) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}