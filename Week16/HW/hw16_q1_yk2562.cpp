/*
 * Yulian Kraynyak
 * yk2562
 * HW16
 * Question 1
 *
 * Symbol balance checker for the Pascal programming language.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>

/* Function Prototypes */
void run(std::ifstream& pascalFile);
void openfile(std::ifstream& inFile);
bool isValid(std::ifstream& inFile);
bool hasSuffix(const std::string& str, const std::string& suffix);
char symbolPair(char symbol);
bool isBegin(std::string str, int i);
bool isEnd(std::string str, int i);
bool isOpeningSymbol(char symbol);
bool isClosingSymbol(char symbol);

/* Classes */
template<class T>
class Stack {
    std::list<T> data;
 public:
    Stack() { data = {}; }

    void push(T newItem) { data.push_front(newItem); }
    void pop() { return !isEmpty() ? data.pop_front() : void(); }
    T top() { return *data.begin(); }
    bool isEmpty() const { return data.size() == 0; }
    int size() const { return data.size(); }
    void clear() { data.clear(); }
};

/* Main */
int main() {
    std::ifstream pascalFile;

    run(pascalFile);
    return 0;
}

/* Functions */
void run(std::ifstream& pascalFile) {
    std::cout << "PASCAL SYNTAX VALIDATOR";
    std::cout << std::endl << std::endl;
    openfile(pascalFile);

    if (isValid(pascalFile)) {
        std::cout << "✓  Syntax valid!";
    }else {
        std::cout << "✕  Syntax invalid!";
    }
    std::cout << std::endl;
    pascalFile.close();
}

void openfile(std::ifstream& inFile) {
    std::string fileName;
    std::cout << "What's the filename? ";
    std::cin >> fileName;

    // for user-friendliness
    if (!hasSuffix(fileName, ".txt")) {
        fileName += ".txt";
    }
    inFile.open(fileName);

    while (!inFile) {
        std::cout << "ERROR: Failed to open \"" << fileName << "\"" << std::endl;
        std::cout << "What's the filename? ";
        std::cin >> fileName;

        // for user-friendliness
        if (!hasSuffix(fileName, ".txt")) {
            fileName += ".txt";
        }
        inFile.clear();
        inFile.open(fileName);
    }
}

bool isValid(std::ifstream& inFile) {
    Stack<char> stack;
    std::string line;

    while (inFile >> line) {
        for (int i = 0; i < line.length(); i++) {
            if (isBegin(line, i)) {
                stack.push(line[i]);
            }else if (isEnd(line, i)) {
                if (line[i] == symbolPair(stack.top())) {
                    stack.pop();
                }else {
                    // closing symbol doesn't match opening symbol
                    stack.push(line[i]);
                }
            }else if (isOpeningSymbol(line[i])) {
                stack.push(line[i]);
            }else if (isClosingSymbol(line[i])) {
                if (line[i] == symbolPair(stack.top())) {
                    stack.pop();
                }else {
                    // closing symbol doesn't match opening symbol
                    stack.push(line[i]);
                }
            }
        }
    }
    return stack.isEmpty();
}

bool hasSuffix(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

char symbolPair(char symbol) {
    switch (symbol) {
        case 'e':
            return 'b';
        case 'b':
            return 'e';
        case '{':
            return '}';
        case '[':
            return ']';
        case '(':
            return ')';
        case '}':
            return '{';
        case ']':
            return '[';
        case ')':
            return '(';
        default:
            break;
    }
}

bool isBegin(std::string str, int i) {
    return (str[i] == 'b' && str[i + 1] == 'e' && str[i + 2] == 'g' && str[i + 3] == 'i' && str[i + 4] == 'n');
}

bool isEnd(std::string str, int i) {
    return (str[i] == 'e' && str[i + 1] == 'n' && str[i + 2] == 'd');
}

bool isOpeningSymbol(char symbol) {
    return (symbol == '{' || symbol == '[' || symbol == '(');
}

bool isClosingSymbol(char symbol) {
    return (symbol == '}' || symbol == ']' || symbol == ')');
}