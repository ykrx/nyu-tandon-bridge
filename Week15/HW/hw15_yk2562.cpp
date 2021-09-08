/*
 * Yulian Kraynyak
 * yk2562
 * HW15
 *
 * Payroll processing system implemented using file inputs and a linked list.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* Class Forward-Declarations */
class Employee;
template<class T>
class LinkedList;
template<class T>
class Node;

/* Function Prototypes */
void openFile(ifstream& inFile, string type);
template<class T>
void printOutput(LinkedList<T> list);

/* Classes */
class Employee {
 private:
    string name;
    int id;
    double hourlyPayRate;
    int hoursWorked;
    double earnings;
 public:
    Employee() {
        name = "";
        id = 0;
        hourlyPayRate = 0.0;
        hoursWorked = 0;
        earnings = 0.0;
    }

    Employee(string name, int id, double hourlyPayRate) {
        this->name = name;
        this->id = id;
        this->hourlyPayRate = hourlyPayRate;
        this->hoursWorked = 0;
        this->earnings = 0.0;
    }

    string get_name() const { return name; }
    int get_id() const { return id; }
    double get_earnings() const { return earnings; }
    void set_hoursWorked(int hours) { hoursWorked += hours; }
    void calculateEarnings() { earnings = hoursWorked * hourlyPayRate; }
};

template<class T>
class Node {
 private:
    T data;
    Node<T>* next;
 public:
    Node(const T& data = T(), Node<T>* next = nullptr) : data(data), next(next) {}

    T& get_data() { return data; }
    Node<T>*& get_next() { return next; }
};

template<class T>
class LinkedList {
 private:
    Node<T>* head;
 public:
    LinkedList() : head(nullptr) {}

    Node<T>* get_head() { return head; }
    bool isEmpty() { return head == nullptr; }
    void addNode(T& data);
    void print();
    void sort();
    void swap(T& data1, T& data2);
};

/* Main */
int main() {
    LinkedList<Employee> list;
    ifstream file1, file2;
    string line;
    char letter;
    int id;
    double hourlyPayRate;

    // 1a. Read first file
    openFile(file1, "employees");

    // 1b. Add each employee to linked list
    while (file1 >> id) {
        string name;
        file1 >> hourlyPayRate;

        file1.get(letter);
        while (!file1.eof() && letter != '\n') {
            name += letter;
            file1.get(letter);
        }
        Employee employee(name, id, hourlyPayRate);
        list.addNode(employee);
    }
    file1.close();

    // 2a. Read second file
    int hoursWorked;
    Node<Employee>* current = list.get_head();

    openFile(file2, "hours worked");

    // 2b. Record number of hours worked for each employee
    while (file2 >> id) {
        file2 >> hoursWorked;
        file2.ignore(9999, '\n');

        while (current != nullptr) {
            if (current->get_data().get_id() == id) {
                current->get_data().set_hoursWorked(hoursWorked);
                current->get_data().calculateEarnings();

                break;
            }else {
                current = current->get_next();
            }
        }
        current = list.get_head(); // reset back to start of list
    }
    file2.close();

    // 3. Print output
    printOutput(list);
    return 0;
}

/* Functions */
template<class T>
void LinkedList<T>::addNode(T& data) {
    if (isEmpty()) {
        head = new Node<T>(data);
    }else {
        Node<T>* current = head;
        // 1. Find memory address of last node
        while (current->get_next() != nullptr) {
            current = current->get_next();
        }
        // 2. Insert node after last node
        current->get_next() = new Node<T>(data);
    }
}

template<class T>
void LinkedList<T>::print() {
    Node<T>* current = head;

    sort();
    while (current != nullptr) {
        cout << current->get_data().get_name() << ", $";
        cout << fixed << setprecision(2);
        cout << current->get_data().get_earnings() << endl;
        current = current->get_next();
    }
}

template<class T>
void LinkedList<T>::sort() {
    Node<T>* current = head;

    while (current != nullptr) {
        Node<T>* next = current->get_next();

        if (next != nullptr) {
            if (current->get_data().get_earnings() < next->get_data().get_earnings()) {
                swap(current->get_data(), next->get_data());
            }
        }
        current = next;
    }
}

template<class T>
void LinkedList<T>::swap(T& data1, T& data2) {
    T temp = data1;
    data1 = data2;
    data2 = temp;
}

// Checks if string is suffixed by another string
bool hasSuffix(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void openFile(ifstream& inFile, string type) {
    string fileName;
    cout << "What's the \"" << type << "\" filename? ";
    cin >> fileName;

    // for user-friendliness
    if (!hasSuffix(fileName, ".txt")) {
        fileName += ".txt";
    }

    inFile.open(fileName);
    while (!inFile) {
        cout << "ERROR: Failed to open file \"" << fileName << "\"";
        cout << endl;
        cout << "What's the \"" << type << "\" filename? ";
        cin >> fileName;

        // for user-friendliness
        if (!hasSuffix(fileName, ".txt")) {
            fileName += ".txt";
        }
        inFile.clear();
        inFile.open(fileName);
    }
}

template<class T>
void printOutput(LinkedList<T> list) {
    cout << endl;
    cout << "*********Payroll Information********" << endl;
    list.print();
    cout << "*********End payroll**************" << endl;
}