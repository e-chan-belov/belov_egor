#include <iostream>
using namespace std;



template <class T>
class Cell {
public:
    Cell<T>* left;
    Cell<T>* right;
    T value;
    int priority;

    Cell(T value_, int priority_) : left(nullptr), right(nullptr),
    value(value_), priority(priority_) {}
    Cell(Cell<T>* q_pointer, Cell<T>* pointer) : value(q_pointer->value), priority(q_pointer->priority) {
        if (pointer != nullptr) {
            pointer->right = this;
        }
        left = pointer;
        right = nullptr;
    }
    ~Cell() {
        if (right != nullptr) {
            right->left = left;
        }
        if (left != nullptr) {
            left->right = right;
        }
    }
    
    void push(Cell<T>* pointer) {
        while (pointer->left != nullptr && pointer->priority < priority) {
            pointer = pointer->left;
        }
        if (pointer->priority < priority) { // вставка слева
            pointer->left = this;
            right = pointer;
            left = nullptr;
        }
        else { // вставка справа
            if (pointer->right != nullptr) {
                right = pointer->right;
                pointer->right->left = this;
            }
            else {
                right = nullptr;
            }
            pointer->right = this;
            left = pointer;
        }
    }
};

template <class T>
class Queue {
protected:
    Cell<T>* tail;
    Cell<T>* head;
    size_t sz;
    
    void toRightPointer(Cell<T>*& pointer) {
        if (pointer == nullptr || pointer->right == nullptr) {
            return;
        }
        else {
            pointer = pointer->right;
        }
    }
    void toLeftPointer(Cell<T>*& pointer) {
        if (pointer == nullptr || pointer->left == nullptr) {
            return;
        }
        else {
            pointer = pointer->left;
        }
    }
public:
    Queue() : tail(nullptr), head(nullptr), sz(0) {}
    Queue(const Queue& q) : sz(q.sz) {
        Cell<T>* q_pointer = q.tail;
        Cell<T>* pointer;
        if (q_pointer == nullptr) {
            pointer = nullptr;
        }
        else {
            pointer = new Cell<T>(q_pointer, nullptr);
            q_pointer = q_pointer->right;
        }
        tail = pointer;
        while (q_pointer != nullptr) {
            pointer = new Cell<T>(q_pointer, pointer);
            q_pointer = q_pointer->right;
        }
        head = pointer;
    }
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    bool isEmpty() const { return tail == nullptr; }
    
    size_t size() const { return sz; }
    
    void push(T val, int priority = 1) {
        Cell<T>* temp = new Cell<T>(val, priority);
        Cell<T>* pointer = head;
        
        if (pointer == nullptr) {
            head = tail = temp;
            sz++;
            return;
        }
        
        temp->push(pointer);
        
        toRightPointer(head);
        toLeftPointer(tail);
        
        sz++;
    }
    T top() {
        if (tail == nullptr) {
            throw out_of_range("lol");
        }
        
        return tail->value;
    }
    void pop() {
        if (tail == nullptr) {
            throw out_of_range("lol");
        }
        
        Cell<T>* temp;
        if (tail->right == nullptr) {
            temp = head = nullptr;
        }
        else {
            temp = tail->right;
        }
        
        delete tail;
        tail = temp;
        
        sz--;
    }
};
