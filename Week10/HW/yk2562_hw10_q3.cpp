/*
 * Yulian Kraynyak
 * yk2562
 * HW10
 * Question 3
 *
 * Occurrences search implementations using array and vector.
*/

#include <iostream>
#include <vector>

using namespace std;

/* Constants */
const int DEFAULT_SIZE = 5;
const int STOP_TRIGGER = -1;
const int ZERO_INDEX_OFFSET = 1;

/* Function Prototypes - Part A */
void main1();
void handleArrayInput(int number, int numbersCount, int &size, int *&numbersPtr);
void handleArraySearch(int *arr, int arrSize);
void resizeArray(int*& arr, int& arrSize);
int countOccurrencesInArray(int number, int *arr, int arrSize);

/* Function Prototypes - Part B */
void main2();
void handleVectorInput(int number, vector<int> &numbers);
void handleVectorSearch(vector<int> vect);
int countOccurrencesInVector(int number, vector<int> vect);

/* Main */
int main() {
    main1(); // Part A
    cout << endl;
    main2(); // Part B
    return 0;
}

void main1() {
    int size = DEFAULT_SIZE;
    int* numbersPtr = new int[size];
    int number = 0;
    int numbersCount = 0;

    handleArrayInput(number, numbersCount, size, numbersPtr);
    handleArraySearch(numbersPtr, size);

    delete [] numbersPtr;
    numbersPtr = nullptr;
}

void main2() {
    int number = 0;
    vector <int> numbers;

    handleVectorInput(number, numbers);
    handleVectorSearch(numbers);
}

/* Functions */
void handleArrayInput(int number, int numbersCount, int &size, int *&numbersPtr) {
    cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    cout << "End your input by typing " << STOP_TRIGGER << ".\n";

    while (number != STOP_TRIGGER) {
        cin >> number;

        if (numbersCount == size) {
            resizeArray(numbersPtr, size);
        }
        numbersPtr[numbersCount] = number;
        numbersCount++;
    }
}

void resizeArray(int*& arr, int& arrSize) {
    int newSize = arrSize * 2;
    int* tempPtr = new int[newSize];

    // Copy original array
    for (int i = 0; i < arrSize; i++) {
        tempPtr[i] = arr[i];
    }
    arrSize = newSize;

    delete[] arr;
    arr = tempPtr;
}

void handleArraySearch(int *arr, int arrSize) {
    int number;
    int occurrences;
    int count = 0;

    cout << "Please enter a number you want to search.\n";
    cin >> number;

    occurrences = countOccurrencesInArray(number, arr, arrSize);
    if (occurrences > 0) {
        cout << number << " shows in lines ";

        for (int i = 0; i < arrSize; i++) {
            if (arr[i] == number) {
                cout << i + ZERO_INDEX_OFFSET;
                count++;

                if (count < occurrences) {
                    cout << ", ";
                }else {
                    cout << ".";
                }
            }
        }
    }else {
        cout << number << " does not show in sequence.";
    }
    cout << endl;
}

int countOccurrencesInArray(int number, int *arr, int arrSize) {
    int count = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == number) {
            count++;
        }
    }
    return count;
}

void handleVectorInput(int number, vector<int> &numbers) {
    cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    cout << "End your input by typing " << STOP_TRIGGER << ".\n";

    while (number != STOP_TRIGGER) {
        cin >> number;
        if (number != STOP_TRIGGER) {
            numbers.push_back(number);
        }
    }
}

void handleVectorSearch(vector<int> vect) {
    int number;
    int occurrences;
    int count = 0;

    cout << "Please enter a number you want to search.\n";
    cin >> number;

    occurrences = countOccurrencesInVector(number, vect);
    if (occurrences > 0) {
        cout << number << " shows in lines ";

        for (int i = 0; i < vect.size(); i++) {
            if (vect[i] == number) {
                cout << i + ZERO_INDEX_OFFSET;
                count++;

                if (count < occurrences) {
                    cout << ", ";
                }else {
                    cout << ".";
                }
            }
        }
    }else {
        cout << number << " does not show in sequence.";
    }
    cout << endl;
}

int countOccurrencesInVector(int number, vector<int> vect) {
    int count = 0;

    for (int i : vect) {
        if (i == number) {
            count++;
        }
    }
    return count;
}