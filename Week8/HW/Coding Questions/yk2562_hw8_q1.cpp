/*
 * Yulian Kraynyak
 * yk2562
 * HW8
 * Question 1
 * 
 * Finds minimum number in an inputted array as well as its' index.
*/

#include <iostream>

using namespace std;

/* Constants */
const int ARR_SIZE = 20;

/* Function Prototypes */
int minInArray(int arr[], int arrSize);
void printMin(int arr[], int arrSize);

/* Main */
int main() {
    int arrSize = ARR_SIZE;
    int arr[arrSize];

    cout << "Please enter " << arrSize << " integers separated by a space:\n";

    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
    printMin(arr, arrSize);
    return 0;
}

/* Functions */
int minInArray(int arr[], int arrSize) {
    int min = arr[0];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void printMin(int arr[], int arrSize) {
    int min = minInArray(arr, arrSize);

    cout << "The minimum value is " << min << ", and it is located in the following indices: ";

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min) {
            cout << i << " ";
        }
    }
}