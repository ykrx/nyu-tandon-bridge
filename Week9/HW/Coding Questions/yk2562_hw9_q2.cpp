/*
 * Yulian Kraynyak
 * yk2562
 * HW9
 * Question 2
 *
 * Checks whether two strings are anagrams.
*/

#include <iostream>
#include <string>

using namespace std;

/* Constants */
const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
const char SPACE = ' ';

/* Function Prototypes */
bool isAnagram(string firstString, string secondString);
void convertToLowerCase(char& letter);
void countLetterOccurrences(string& str, int arr[]);

/* Main */
int main() {
    string firstString, secondString;

    cout << "Enter first string: ";
    getline(cin, firstString);
    cout << "Enter second string: ";
    getline(cin, secondString);

    if (isAnagram(firstString, secondString)) {
        cout << "\"" << firstString << "\" and \"" << secondString << "\" are anagrams";
    }else {
        cout << "\"" << firstString << "\" and \"" << secondString << "\" are NOT anagrams";
    }
    return 0;
}

/* Functions */
bool isAnagram(string firstString, string secondString) {
    int letterOccurrencesFirstString[NUMBER_OF_LETTERS_IN_ALPHABET];
    int letterOccurrencesSecondString[NUMBER_OF_LETTERS_IN_ALPHABET];
    bool match = true;

    // Populate arrays with initial letter occurrence counts of 0
    for (int i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++) {
        letterOccurrencesFirstString[i] = 0;
        letterOccurrencesSecondString[i] = 0;
    }
    countLetterOccurrences(firstString, letterOccurrencesFirstString);
    countLetterOccurrences(secondString, letterOccurrencesSecondString);

    for (int i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++) {
        if (letterOccurrencesFirstString[i] != letterOccurrencesSecondString[i]) {
            match = false;
            return match;
        }
    }
    return match;
}

void convertToLowerCase(char& letter) {
    if (letter < 'a' ) {
        letter += 'a' - 'A';
    }
}

void countLetterOccurrences(string& str, int arr[]) {
    for (int i = 0; i < str.length(); i++) {
        convertToLowerCase(str[i]);

        if (str[i] != SPACE) {
            arr[str[i] - 'a']++;
        }
    }
}