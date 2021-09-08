#include <iostream>
#include <string>

using namespace std;

template<class T>
class LList;
template<class T>
class LListItr;

template<class T>
class LListNode {
    T data;
    LListNode<T>* next;
    LListNode<T>* prev;
  public:
    LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) : data(newdata), next(newnext), prev(newprev) {}
    friend class LList<T>;
    friend class LListItr<T>;
};
class EmptyListError {
};

template<class S>
class LListItr {
    LListNode<S>* ptr;
  public:
    LListItr(LListNode<S>* newptr = nullptr) : ptr(newptr) {}
    S& operator *() { return ptr->data; }
    S operator *() const { return ptr->data; }
    LListItr operator ++(int);
    LListItr& operator ++();
    LListItr operator --(int);
    LListItr& operator --();
    bool operator ==(const LListItr<S>& rhs) const { return ptr == rhs.ptr; }
    bool operator !=(const LListItr<S>& rhs) const { return ptr != rhs.ptr; }
    friend class LList<S>;
};

template<class T>
class LList {
    LListNode<T>* head;
    LListNode<T>* tail;
    int numElements;
  public:

    LListItr<T> begin() { return head->next; }
    LListItr<T> end() { return tail; }
    bool isEmpty() const { return numElements == 0; }
    LList();
    virtual ~LList();
    void push_front(const T& newdata);
    void push_back(const T& newdata) { insertAfter(newdata, tail->prev); }
    int size() const { return numElements; }
    void clear();
    LList(const LList<T>& rhs);
    LList& operator =(const LList& rhs);
    T pop_front() { if (!isEmpty()) { return removeNode(head->next); }else { throw EmptyListError(); }}
    T pop_back() { if (!isEmpty()) { return removeNode(tail->prev); }else { throw EmptyListError(); }}

    void insertAfter(const T& newdata, LListItr<T> itr);
    T removeNode(LListItr<T> itr);
};
template<class T>
LListItr<T> LListItr<T>::operator --(int) {
    LListItr<T> temp = *this;
    if (ptr->prev != nullptr) {
        ptr = ptr->prev;
    }
    return temp;
}
template<class T>
LListItr<T>& LListItr<T>::operator --() {
    if (ptr->prev != nullptr) {
        ptr = ptr->prev;
    }
    return *this;
}

template<class T>
LListItr<T> LListItr<T>::operator ++(int) {
    LListItr<T> temp = *this;
    if (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    return temp;
}
template<class T>
LListItr<T>& LListItr<T>::operator ++() {
    if (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    return *this;
}
template<class T>
T LList<T>::removeNode(LListItr<T> itr) {
    LListNode<T>* toDelete = itr.ptr;
    T retval = toDelete->data;
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    delete toDelete;
    numElements--;
    return retval;
}

template<class T>
void LList<T>::insertAfter(const T& newdata, LListItr<T> itr) {
    LListNode<T>* temp = itr.ptr;
    numElements++;
    temp->next = new LListNode<T>(newdata, temp->next, temp);
    temp->next->next->prev = temp->next;


    /*LListNode<T>* newnode = new LListNode<T>;
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
    */

}
template<class T>
LList<T>& LList<T>::operator =(const LList<T>& rhs) {
    if (this == &rhs) {
        return *this;
    }
    clear();

    for (LListNode<T>* temp = rhs.head->next; temp != rhs.tail; temp = temp->next) {
        push_back(temp->data);
    }
    return *this;
}
template<class T>
LList<T>::LList(const LList<T>& rhs) {
    numElements = 0;
    head = new LListNode<T>(T(), new LListNode<T>); //create two dummy nodes.
    tail = head->next;
    tail->prev = head;
    *this = rhs;
}
template<class T>
void LList<T>::clear() {
    while (!isEmpty()) {
        removeNode(head->next);
    }
}
template<class T>
void LList<T>::push_front(const T& newdata) {
    insertAfter(newdata, head);
}
template<class T>
LList<T>::~LList() {
    clear();
    delete head;
    delete tail;
}
template<class T>
LList<T>::LList() {
    numElements = 0;
    head = new LListNode<T>(T(), new LListNode<T>); //create two dummy nodes.
    tail = head->next;
    tail->prev = head;
}


int main() {
    LList<int> l1;
    for (int i = 0; i < 10; i++) {
        l1.push_back(i * 10);
    }

    LList<int> l2 = l1;

    for (LListItr<int> i = l2.begin(); i != l2.end(); i++) {
        cout << *i << endl;
    }

    for (int& val : l2) {
        cout << val << endl;
    }
}