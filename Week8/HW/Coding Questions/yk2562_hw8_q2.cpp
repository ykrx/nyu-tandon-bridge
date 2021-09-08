/*
 * Yulian Kraynyak
 * yk2562
 * HW8
 * Question 2
 *
 * Determines whether a word is a palindrome.
*/

#include <iostream>
#include <string>

using namespace std;

/* Function Prototypes */
bool isPalindrome(string str);

/* Main */
int main() {
    string word;

    cout << "Please enter a word: ";
    cin >> word;

    if (isPalindrome(word)) {
        cout << word << " is a palindrome";
    }else {
        cout << word << " is not a palindrome";
    }
    return 0;
}

/* Functions */
bool isPalindrome(string str) {
    bool allMatch = true;

    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            allMatch = false;
        }
    }
    return allMatch;
}