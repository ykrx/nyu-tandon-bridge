/*
 * Yulian Kraynyak
 * yk2562
 * HW9
 * Question 3
 * 
 * Pass-by-pointer and pass-by-reference practice.
*/

#include <iostream>

using namespace std;

/* Constants */
const int ARR_SIZE = 6;

/* Function Prototypes */
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int arr[], int arrSize);

/* Main */
int main() {
    int arr[ARR_SIZE] = {3, -1, -3, 0, 6, 4};
    int outPosArrSize;
    int *posArr1, *posArr2, *posArr3, *posArr4;

    posArr1 = getPosNums1(arr, ARR_SIZE, outPosArrSize);
    cout << "getPosNums1:" << endl;
    printArray(posArr1, outPosArrSize);
    cout << "address: " << posArr1 << endl;
    cout << "outPosArrSize: " << outPosArrSize << endl;
    cout << endl;

    posArr2 = getPosNums2(arr, ARR_SIZE, &outPosArrSize);
    cout << "getPosNums2:" << endl;
    printArray(posArr2, outPosArrSize);
    cout << "address: " << posArr2 << endl;
    cout << "outPosArrSize: " << outPosArrSize << endl;
    cout << endl;

    cout << "getPosNums3:" << endl;
    getPosNums3(arr, ARR_SIZE, posArr3, outPosArrSize);
    printArray(posArr3, outPosArrSize);
    cout << "address: " << posArr3 << endl;
    cout << "outPosArrSize: " << outPosArrSize << endl;
    cout << endl;

    cout << "getPosNums4:" << endl;
    getPosNums4(arr, ARR_SIZE, &posArr4, &outPosArrSize);
    printArray(posArr4, outPosArrSize);
    cout << "address: " << posArr4 << endl;
    cout << "outPosArrSize: " << outPosArrSize << endl;
    cout << endl;

    delete [] posArr1;
    posArr1 = nullptr;
    delete [] posArr2;
    posArr2 = nullptr;
    delete [] posArr3;
    posArr3 = nullptr;
    delete [] posArr4;
    posArr4 = nullptr;
    return 0;
}

/* Functions */
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int* posArr = new int [arrSize];
    int posSize = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posSize++] = arr[i];
        }
    }
    outPosArrSize = posSize;
    return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int* posArr = new int [arrSize];
    int posSize = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posSize++] = arr[i];
        }
    }
    *outPosArrSizePtr = posSize;
    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    *outPosArrPtr = getPosNums2(arr, arrSize, outPosArrSizePtr);
}

void printArray(int arr[], int arrSize) {
    cout << "array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}