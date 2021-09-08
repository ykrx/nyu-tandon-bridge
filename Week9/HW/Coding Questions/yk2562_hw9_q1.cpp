/*
 * Yulian Kraynyak
 * yk2562
 * HW9
 * Question 1
 *
 * Counts letter occurrences in a sentence.
*/

#include <iostream>
#include <string>

using namespace std;

/* Constants */
const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
const char PERIOD = '.';
const char COMMA = ',';
const char SPACE = ' ';

/* Function Prototypes */
int countWords(string str);
bool containsWords(string str);
void convertToLowerCase(char& letter);
void printLetterOccurrences(string str);
bool isLetter(int i, string str);
bool isPeriod(int i, string str);
bool isComma(int i, string str);
bool isSpace(int i, string str);
bool notPrecededByStartOfLine(int i);
bool notFollowedByEndOfLine(int i, string str);
bool notPrecededByComma(int i, string str);
bool notFollowedByComma(int i, string str);
bool notPrecededByPeriod(int i, string str);
bool notFollowedByPeriod(int i, string str);
bool notPrecededBySpace(int i, string str);
bool notFollowedBySpace(int i, string str);

/* Main */
int main() {
    string str;

    cout << "Please enter a line of text:\n";
    getline(cin, str);

    cout << countWords(str) << "\t" << "words\n";
    printLetterOccurrences(str);
    return 0;
}

/* Functions */
void printLetterOccurrences(string str) {
    string alphabet[NUMBER_OF_LETTERS_IN_ALPHABET];
    int letterOccurrences[NUMBER_OF_LETTERS_IN_ALPHABET];

    // Populate alphabet array with letters and letterOccurrences array with 0's
    for (int i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++) {
        alphabet[i] = (char)i + 'a'; // + 97 to get letter representation of ASCII
        letterOccurrences[i] = 0;
    }
    for (int i = 0; i < str.length(); i++) {
        convertToLowerCase(str[i]);

        if (str[i] != SPACE) {
            letterOccurrences[str[i] - 'a']++;
        }
    }
    for (int i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++) {
        if (letterOccurrences[i] > 0) {
            cout << letterOccurrences[i] << "\t" << alphabet[i] << "\n";
        }
    }
}

/* Helper Functions */
int countWords(string str) {
    int count = 0;

    if (containsWords(str)) {
        count = 1;
        for (int i = 0; i < str.length(); i++) {
            if (isPeriod(i, str) || isComma(i, str) || isSpace(i, str)) {
                count++;
            }
        }
    }
    return count;
}

bool containsWords(string str) {
    // Checks whether string contains characters other than spaces, commas, or periods (ie: letters)
    for (int i = 0; i < str.length(); i++) {
        if (isLetter(i, str)) {
            return true;
        }
    }
}

bool isLetter(int i, string str) {
    return str[i] != SPACE && str[i] != COMMA && str[i] != PERIOD;
}

bool isPeriod(int i, string str) {
    return str[i] == PERIOD && notPrecededByStartOfLine(i) && notFollowedByEndOfLine(i, str);
}

bool isComma(int i, string str) {
    return str[i] == COMMA && notPrecededByStartOfLine(i) && notFollowedByEndOfLine(i, str);
}

bool isSpace(int i, string str) {
    return str[i] == ' ' && notPrecededByComma(i, str) && notFollowedByComma(i, str) && notPrecededByPeriod(i, str) && notFollowedByPeriod(i, str) && notPrecededBySpace(i, str) && notFollowedBySpace(i, str) && notPrecededByStartOfLine(i) && notFollowedByEndOfLine(i, str);
}

bool notPrecededByStartOfLine(int i) {
    return i - 1 >= 0;
}

bool notFollowedByEndOfLine(int i, string str) {
    return i + 1 < str.length();
}

bool notPrecededByComma(int i, string str) {
    return str[i - 1] != COMMA;
}

bool notFollowedByComma(int i, string str) {
    return str[i + 1] != COMMA;
}

bool notPrecededByPeriod(int i, string str) {
    return str[i - 1] != PERIOD;
}

bool notFollowedByPeriod(int i, string str) {
    return str[i + 1] != PERIOD;
}

bool notPrecededBySpace(int i, string str) {
    return str[i - 1] != SPACE;
}

bool notFollowedBySpace(int i, string str) {
    return str[i + 1] != SPACE;
}

void convertToLowerCase(char& letter) {
    if (letter < 'a') {
        letter += 'a' - 'A';
    }
}