#include <iostream>
using namespace std;


const size_t STANDART_QUEUE_SIZE = 10;
const size_t MAX_QUEUE_SIZE = 1000000;


template <class T>
class Queue {
protected:
    T* frame;
    T* head;
    T* tail;
    size_t MemLen;
    
    void resize(size_t s) {
        if (s <= 0 || s > MAX_QUEUE_SIZE - MemLen) {
            throw "NO";
        }
        T* temp = new T[MemLen + s];
        if (head >= tail) {
            memcpy(temp + (tail - frame), tail, sizeof(T) * size());
            tail = temp + (tail - frame);
        }
        else {
            memcpy(temp, frame, sizeof(T) * (head - frame));
            memcpy(temp + s + (tail - frame), tail, sizeof(T) * (MemLen - (tail - frame)));
            tail = temp + s + (tail - frame);
        }
        head = temp + (head - frame);
        delete[] frame;
        frame = temp;
        MemLen += s;
    }
public:
    Queue(size_t s = STANDART_QUEUE_SIZE) : MemLen(s) {
        if (s <= 0 || s > MAX_QUEUE_SIZE) {
            throw "NO";
        }
        head = tail = frame = new T[s];
    }
    Queue(const Queue& q) : MemLen(q.MemLen) {
        frame = new T[MemLen];
        memcpy(frame, q.frame, MemLen * sizeof(T));
        head = frame + (q.head - q.frame);
        tail = frame + (q.tail - q.frame);
    }
    Queue(Queue&& q) : MemLen(q.MemLen) {
        frame = q.frame;
        tail = q.tail;
        head = q.head;
        
        q.frame = nullptr;
        q.tail = nullptr;
        q.head = nullptr;
    }
    
    ~Queue() { delete[] frame; }
    
    size_t size() const {
        if (head >= tail) {
            return head - tail;
        }
        return MemLen + head - tail;
    }
    
    T top() const {
        return *tail;
    }
    
    void pop() {
        if (size() == 0) {
            throw "BAD!";
        }
        tail = (tail - frame + 1) % MemLen + frame;
    }
    
    void push(T val) {
        if (size() == MemLen - 1) {
            resize(STANDART_QUEUE_SIZE);
        }
        *head = val;
        head = (head - frame + 1) % MemLen + frame;
    }
};
