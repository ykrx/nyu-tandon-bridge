/*
 * Yulian Kraynyak
 * yk2562
 * HW9
 * Question 4
 * 
 * Orders array of numbers by keeping order of odds, flipping order of evens.
*/

#include <iostream>

using namespace std;

/* Constants */
const int ARR_SIZE = 6;

/* Function Prototypes */
void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void swap(int& element1, int& element2);
bool isEven(int num);
int countEvens(int arr[], int arrSize);

/* Main */
int main() {
    int arr[ARR_SIZE] = {5, 2, 11, 7, 6, 4};

    oddsKeepEvensFlip(arr, ARR_SIZE);
    printArray(arr, ARR_SIZE);
    return 0;
}

/* Functions */
void oddsKeepEvensFlip(int arr[], int arrSize) {
    int currentIndex = 0;

    // Create temporary array for even numbers
    int evensCurrentIndex = 0;
    int evensArrSize = countEvens(arr, arrSize);
    int evensArr[evensArrSize];

    for (int i = 0; i < arrSize; i++) {
        if (isEven(arr[i])) {
            evensArr[evensCurrentIndex++] = arr[i];
        }
    }
    // Sort odd numbers to the front
    for (int i = 0; i < arrSize; i++) {
        if (!isEven(arr[i])) {
            swap(arr[currentIndex], arr[i]);
            currentIndex++;
        }
    }
    // Sort temporary array, reversing order of elements
    for (int i = 0; i < evensArrSize / 2; i++) {
        swap(evensArr[i], evensArr[evensArrSize - i - 1]);
    }
    // Merge temporary array of even numbers back into original array
    for (int i = 0; i < evensArrSize; i++) {
        arr[currentIndex + i] = evensArr[i];
    }
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int& element1, int& element2) {
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

bool isEven(int num) {
    return num % 2 == 0;
}

int countEvens(int arr[], int arrSize) {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (isEven(arr[i])) {
            count++;
        }
    }
    return count;
}