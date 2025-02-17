#include <iostream>
#include "stack.h"
using namespace std;



template <class T>
class Queue {
public:
    Stack<T> left_s;
    Stack<T> right_s;
public:
    Queue() {}
    Queue(const Queue& q) : left_s(q.left_s), right_s(q.right_s) {}
    ~Queue() = default;
    
    Queue& operator=(const Queue& q) {
        left_s = q.left_s;
        right_s = q.right_s;
        return *this;
    }
    
    size_t size() const { return left_s.size() + right_s.size(); }
    
    void push(T val) { std::cerr << "push" << std::endl;left_s.push(val); }
    void pop() {
        std::cerr << "pop" << std::endl;
        if (right_s.empty() && left_s.empty()) {
            std::cerr << "Both stacks are empty, throwing exception" << std::endl;
            throw std::out_of_range("Queue is empty");
        }
        else if (right_s.empty()) {
            std::cerr << "Transferring elements from left_s to right_s" << std::endl;
            while (!left_s.empty()) {
                right_s.push(left_s.top());
                left_s.pop();
            }
        }
        std::cerr << "Popping from right_s" << std::endl;
        right_s.pop();
    }
    T top() {
        if (right_s.empty() && left_s.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        if (right_s.empty()) {
            while (!left_s.empty()) {
                right_s.push(left_s.top());
                left_s.pop();
            }
        }
        return right_s.top();
    }
};
