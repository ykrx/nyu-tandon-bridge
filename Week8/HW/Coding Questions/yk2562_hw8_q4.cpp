/*
 * Yulian Kraynyak
 * yk2562
 * HW8
 * Question 4
 * 
 * Dynamic authentication system.
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/* Settings */
const int NUMBER_OF_DIGITS = 10;
const int PIN_LENGTH = 5;
const string CORRECT_PIN = "21389";

/* Function Prototypes */
void generateHash(int *numDigits);
void printPinDigits();
void printNumDigits(int numDigits[]);
void authenticate(string pin, int *numDigits);
int find(int arr[], int length, int element);
string hashPin(string pin, int num[]);

/* Main */
int main() {
    int numDigits[NUMBER_OF_DIGITS];
    string pin;

    generateHash(numDigits);

    cout << "Please enter your PIN according to the following mapping: \n";
    printPinDigits();
    printNumDigits(numDigits);
    cin >> pin;

    authenticate(pin, numDigits);
}

void printPinDigits() {
    cout << "PIN:\t";
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        cout << i << " ";
    }
    cout << endl;
}

void authenticate(string pin, int *numDigits) {
    if (pin == hashPin(CORRECT_PIN, numDigits)) {
        cout << "Your PIN is correct";
    }else {
        cout << "Your PIN is not correct";
    }
}

void printNumDigits(int numDigits[]) {
    cout << "NUM:\t";
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        cout << numDigits[i] << " ";
    }
    cout << "\n";
}

/* Generates random number assignment (1-3) and assigns it to numDigits */
void generateHash(int *numDigits) {
    srand(time(0)); // generate rand seed, NOLINT
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        int randomValue = (rand() % 3) + 1; //NOLINT
        numDigits[i] = randomValue;
    }
}

/* Hashes pin according to numDigits */
string hashPin(string pin, int numDigits[]) {
    int pinDigits[NUMBER_OF_DIGITS];
    string hashedPin;

    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        pinDigits[i] = i;
    }
    for (int i = 0; i < PIN_LENGTH; i++) {
        int pinDigit = (int)pin[i] - '0'; // convert character number to int
        int digitIndex = find(pinDigits, NUMBER_OF_DIGITS, pinDigit);
        int hashDigit = numDigits[digitIndex];
        hashedPin += to_string(hashDigit);
    }
    return hashedPin;
}

/* Helper function to find index of an element in an array */
int find(int arr[], int length, int element) {
    int index = -1;
    for (int i = 0; i < length; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}