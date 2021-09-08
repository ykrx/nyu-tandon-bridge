/*
 * Yulian Kraynyak
 * yk2562
 * HW16
 * Question 2
 *
 * Queue implementation using a vector.
 */

#include <iostream>
#include <vector>

/* Class Forward-Declarations */
template<class T>
class Queue;

/* Function Prototypes */
template<class T>
void tester(Queue<T>& queue);

/* Classes */
template<class T>
class Queue {
    std::vector<T> data;
    int startIndex;
 public:
    Queue() {
        data = {};
        startIndex = 0;
    };

    void enqueue(T item); // for single item
    void enqueue(std::vector<T> items); // for multiple items
    T dequeue();
    T top() const;
    bool isEmpty() const { return size() == 0; }
    int size() const { return data.size() - startIndex; }
    void reset_startIndex() { startIndex = 0; }
    void clear() { data.clear(); }
    void print();
    void printInfo();
};

/* Main */
int main() {
    Queue<int> queue;

    tester(queue);
    return 0;
}

/* Functions */
template<class T>
void Queue<T>::enqueue(T item) {
    data.push_back(item);
    std::cout << "> enqueue: " << item << std::endl << std::endl;
}

template<class T>
void Queue<T>::enqueue(std::vector<T> items) {
    std::cout << "> enqueue: { ";

    for (int i = 0; i < items.size(); i++) {
        data.push_back(items[i]);
        std::cout << items[i];

        if (i < items.size() - 1) {
            std::cout << ", ";
        }else {
            std::cout << " }" << std::endl << std::endl;
        }
    }
}

template<class T>
T Queue<T>::top() const {
    if (!isEmpty()) {
        return data[startIndex];
    }else {
        return 0;
    }
}

template<class T>
T Queue<T>::dequeue() {
    if (!isEmpty()) {
        std::cout << "> dequeue: " << data[startIndex] << std::endl << std::endl;
        return data[startIndex++];
    }else {
        clear();
        reset_startIndex();
    }
}

template<class T>
void Queue<T>::print() {
    std::cout << "{ ";
    for (int i = startIndex; i < data.size(); i++) {
        std::cout << data[i];
        if (i < data.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

template<class T>
void Queue<T>::printInfo() {
    std::cout << "stack: ";
    print();
    std::cout << "size: " << size() << std::endl;
    std::cout << "top: " << top() << std::endl;
    std::cout << std::endl;
}

template<class T>
void tester(Queue<T>& queue) {
    queue.printInfo();

    queue.enqueue({ 1, 2, 3, 4, 5, 6 });
    queue.printInfo();

    queue.dequeue();
    queue.printInfo();

    queue.dequeue();
    queue.printInfo();

    queue.dequeue();
    queue.printInfo();

    queue.enqueue(10);
    queue.printInfo();

    queue.dequeue();
    queue.printInfo();

    queue.dequeue();
    queue.printInfo();

    queue.dequeue();
    queue.printInfo();

    queue.dequeue();
    queue.printInfo();
}