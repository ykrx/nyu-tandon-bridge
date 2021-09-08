/*
 * Yulian Kraynyak
 * yk2562
 * HW10
 * Question 1
 *
 * Splits sentence into array of words.
*/

#include <iostream>
#include <string>

using namespace std;

/* Constants */
const char SPACE = ' ';

/* Function Prototypes */
string* createWordsArray(string sentence, int& outWordsArrSize);
int countWords(string str);
int countSpaces(string str);
void getSpaceIndices(string str, int arr[]);
void printWords(string arr[], int arrSize);

/* Main */
int main() {
    string sentence;
    string* outWordsArr;
    int outWordsArrSize;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    outWordsArr = createWordsArray(sentence, outWordsArrSize);
    cout << "outWordsArrSize: " << outWordsArrSize << endl;
    printWords(outWordsArr, outWordsArrSize);

    delete [] outWordsArr;
    outWordsArr = nullptr;
    return 0;
}

/* Functions */
string* createWordsArray(string sentence, int& outWordsArrSize) {
    int numberOfWords = countWords(sentence);
    string* wordsArray = new string[numberOfWords];
    string word;
    int numberOfSpaces = countSpaces(sentence);
    int spacesArr[numberOfSpaces];

    getSpaceIndices(sentence, spacesArr);

    int currentIndex = 0;
    int wordIndex = 0;

    for (int i = 0; i < numberOfWords; i++) {
        if (i == numberOfWords - 1) {
            // Last word
            int startIndex = numberOfSpaces > 0 ? currentIndex + 1 : currentIndex; // handle case where there's only one word
            word = sentence.substr(startIndex, sentence.length());
            wordsArray[wordIndex] = word;
        }else {
            // Ternary logic to trim leading/trailing spaces from "middle words"
            // (words which aren't in the first or last position in the
            // sentence) */
            word = sentence.substr(currentIndex > 0 ? currentIndex + 1 : currentIndex, currentIndex > 0 ? spacesArr[i] - currentIndex - 1 : spacesArr[i] - currentIndex);
            currentIndex = spacesArr[i];
            wordsArray[wordIndex++] = word;
        }
    }
    outWordsArrSize = numberOfWords;
    return wordsArray;
}

void getSpaceIndices(string str, int arr[]) {
    int currentIndex = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == SPACE) {
            arr[currentIndex++] = i;
        }
    }
}

int countSpaces(string str) {
    int count = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == SPACE) {
            count++;
        }
    }
    return count;
}

int countWords(string str) {
    return countSpaces(str) + 1;
}

void printWords(string arr[], int arrSize) {
    int lastIndex = arrSize - 1;

    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << "\"" << arr[i] << "\"";

        if (i != lastIndex) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}