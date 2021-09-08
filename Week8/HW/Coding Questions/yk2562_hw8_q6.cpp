/*
 * Yulian Kraynyak
 * yk2562
 * HW8
 * Question 6
 *
 * String obfuscator.
*/

#include <iostream>
#include <string>

using namespace std;

/* Function Prototypes */
string processString(string str);
string obfuscate(string str);
bool isDigits(string str);
int wordCount(string str);

/* Main */
int main() {
    string str;

    cout << "Please enter a line of text:\n";
    getline(cin, str);
    cout << processString(str);
    return 0;
}

/* Functions */
string processString(string str) {
    string formattedString;
    string words[wordCount(str)];
    int wordIndex = 0;

    // Separate string into array of strings for each word, using spaces as delimiters
    for (char i : str) {
        if (i == ' ') {
            wordIndex++;
        }else {
            words[wordIndex] += i;
        }
    }
    // Obfuscate words composed of digits
    for (int i = 0; i <= wordIndex; i++) {
        if (isDigits(words[i])) {
            words[i] = obfuscate(words[i]);
        }
        formattedString += i < wordIndex ? words[i] + " " : words[i]; // add spaces back between words
    }
    return formattedString;
}

/* Replaces every character in string with 'x' */
string obfuscate(string str) {
    string obfuscatedString;

    for (int i = 0; i < str.length(); i++) {
        obfuscatedString += "x";
    }
    return obfuscatedString;
}

int wordCount(string str) {
    int count = 1;
    for (char i : str) {
        if (i == ' ') {
            count++;
        }
    }
    return count;
}

/* Checks if entire string is composed of digits */
bool isDigits(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}