#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10000;

template <class T>
struct Node {
    T value;
    Node<T>* next;
    
    Node(T value_ = T(), Node<T>* next_ = nullptr) : value(value_), next(next_) {}
    ~Node() = default;
    friend ostream& operator<<(ostream& of, const Node& n) {
        of << n.value;
        return of;
    }
    friend istream& operator>>(istream& is, Node& n) {
        is >> n.value;
        return is;
    }
};

template <class T>
class List {
protected:
    Node<T>* head;
public:
    class Iterator {
    protected:
        Node<T>* pointer;
        Node<T>* previous_pointer;
    public:
        Iterator(Node<T>* head_ = nullptr, size_t index = 0) : pointer(head_), previous_pointer(nullptr) {
            for (int i = 0; i < index; i++) {
                if (pointer == nullptr) {
                    throw out_of_range("IMPOSSIBLE");
                }
                previous_pointer = pointer;
                pointer = pointer->next;
            }
        }
        
        ~Iterator() {}
        
        T& current() {
            return pointer->value;
        }
        const T& current() const {
            return pointer->value;
        }
        
        bool hasNext() const {
            return pointer->next != nullptr;
        }
        bool isAtList() const {
            return pointer != nullptr;
        }
        void toNext() {
            if (pointer == nullptr) {
                throw out_of_range("LOL");
            }
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        void toPrevious() {
            if (previous_pointer == nullptr) {
                throw out_of_range("LOL");
            }
            pointer = previous_pointer;
            previous_pointer = nullptr;
        }
        void operator++(int) {
            toNext();
        }
        void operator--(int) {
            toPrevious();
        }
        
        void push(const T& value) {
            if (pointer == nullptr) {
                throw out_of_range("CANT PUSH");
            }
            pointer->next = new Node<T>(value, pointer->next);
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        void pop() {
            if (pointer == nullptr || previous_pointer == nullptr) {
                throw -1;
            }
            previous_pointer->next = pointer->next;
            delete pointer;
            pointer = previous_pointer;
            previous_pointer = nullptr;
        }
    };
    List(size_t sz = 0) : head(nullptr) {
        if (sz < 0 && sz > MAX_SIZE) {
            throw out_of_range("NEGATIVE OR GREATER THAN MAX VALUE");
        }
        if (sz == 0) {
            head = nullptr;
        }
        else {
            Node<T>* pointer = head = new Node<T>;
            for (size_t i = 1; i < sz; i++) {
                pointer = pointer->next = new Node<T>;
            }
        }

    }
    List(const List& s) {
        Iterator iS = s.begin();
        head = new Node<T>(iS.current(), nullptr);
        Iterator i = begin();
        iS++;
        for (; iS.isAtList(); iS++) {
            i.push(iS.current());
        }
    }
    List(List&& s) : head(s.head) {
        s.head = nullptr;
    }
    ~List() {
        Node<T>* current = head;
        Node<T>* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    List operator=(const List& s) {
        if (head == s.head) {
            return *this;
        }
        this->~List();
        Iterator iS = s.begin();
        head = new Node<T>(iS.current(), nullptr);
        Iterator i = begin();
        iS++;
        for (; iS.isAtList(); iS++) {
            i.push(iS.current());
        }
        return *this;
    }
    List operator=(List&& s) {
        if (head == s.head) {
            return *this;
        }
        this->~List();
        head = s.head;
        s.head = nullptr;
        return *this;
    }
    
    size_t size() const {
        Node<T>* current = head;
        size_t sz = 0;
        while (current != nullptr) {
            current = current->next;
            sz++;
        }
        return sz;
    }
    
    void push_back(const T& value) {
        head = new Node<T>(value, head);
    }
    void pop_back() {
        if (head == nullptr) {
            throw -1;
        }
        Node<T>* temp = head->next;
        head->next = nullptr;
        delete head;
        head = temp;
    }
    
    Iterator begin() const { Iterator itr(head, 0); return itr; }
    Iterator atIndex(size_t i) const { Iterator itr(head, i); return itr; }
    
    T& top() {
        if (head == nullptr) {
            throw out_of_range("e");
        }
        return head->value;
    }
    
    T& operator[](size_t ind) {
        if (ind < 0 || ind >= size()) {
            throw -1;
        }
        Iterator itr(head, ind);
        return itr.current();
    }
    const T& operator[](size_t ind) const {
        if (ind < 0 || ind >= size()) {
            throw -1;
        }
        Iterator itr(head, ind);
        return itr.current();
    }
    
    friend ostream& operator<<(ostream& os, const List& s) {
        Node<T>* current = s.head;
        while (current->next != nullptr) {
            os << current->value << " + ";
            current = current->next;
        }
        os << current->value;
        return os;
    }
    
    friend istream& operator>>(istream& is, List& s) {
        Node<T>* current = s.head;
        while (current != nullptr) {
            is >> current->value;
            current = current->next;
        }
        return is;
    }
};
