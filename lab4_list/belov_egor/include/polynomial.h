#include <iostream>
#include "list.h"

using namespace std;

class Term {
private:
    int a;
    unsigned int x;
    unsigned int y;
    unsigned int z;
public:
    Term(int a_ = 1, int x_ = 1, int y_ = 1, int z_ = 1) : a(a_), x(x_), y(y_), z(z_) {
        if (a == 0) {
            x = 0;
            y = 0;
            z = 0;
        }
    }
    
    Term& operator=(const Term& t) {
        a = t.a;
        x = t.x;
        y = t.y;
        z = t.z;
        return *this;
    }
    
    Term operator+(const Term& t) const {
        if (x != t.x || y != t.y || z != t.z) {
            throw "YOU CANT!";
        }
        Term temp(a + t.a, x, y, z);
        return temp;
    }
    Term operator-(const Term& t) const {
        if (x != t.x || y != t.y || z != t.z) {
            throw "YOU CANT!";
        }
        Term temp(a - t.a, x, y, z);
        return temp;
    }
    Term operator*(const Term& t) const {
        Term temp(a * t.a, x + t.x, y + t.y, z + t.z);
        return temp;
    }
    Term operator*(int c) const {
        Term temp(a * c, x, y, z);
        return temp;
    }
    
    bool operator==(const Term& t) const {
        return x == t.x && y == t.y && z == t.z;
    }
    bool operator!=(const Term& t) const {
        return x != t.x || y != t.y || z != t.z;
    }
    
    bool equalPower(const Term& t) const {
        return (x + y + z == t.x + t.y + t.z);
    }
    bool isEqual(const Term& t) const {
        return a == t.a && x == t.x && y == t.y && z == t.z;
    }
    
    bool operator>(const Term& t) const {
        return (x + y + z > t.x + t.y + t.z);
    }
    bool operator>=(const Term& t) const {
        return (x + y + z >= t.x + t.y + t.z);
    }
    bool operator<(const Term& t) const {
        return (x + y + z < t.x + t.y + t.z);
    }
    bool operator<=(const Term& t) const {
        return (x + y + z <= t.x + t.y + t.z);
    }
    
    friend ostream& operator<<(ostream& os, const Term& t) {
        os << t.a;
        if (t.x != 0) {
            os << "(x";
            if (t.x > 1) {
                os << "^" << t.x;
            }
            os << ")";
        }
        if (t.y != 0) {
            os << "(y";
            if (t.y > 1) {
                os << "^" << t.y;
            }
            os << ")";
        }
        if (t.z != 0) {
            os << "(z";
            if (t.z > 1) {
                os << "^" << t.z;
            }
            os << ")";
        }
        return os;
    }
    friend istream& operator>>(istream& is, Term& t) {
        is >> t.a >> t.x >> t.y >> t.z;
        return is;
    }
};


class Polynomial {
private:
    List<Term> polynom;
public:
    Polynomial(size_t sz = 0) : polynom(sz) {}
    Polynomial(const Polynomial& p) : polynom(p.polynom) {}
    ~Polynomial() = default;
    
    Polynomial operator=(const Polynomial& p) {
        polynom = p.polynom;
        return *this;
    }
    Polynomial operator=(Polynomial&& p) {
        polynom = p.polynom;
        return *this;
    }
    
    size_t size() const { return polynom.size(); }
    
    void push(const Term& value) {
        if (polynom.size() == 0) {
            polynom.push_back(value);
        }
        else if (value.isEqual(Term(0, 0, 0, 0))) {
            if (!polynom.top().isEqual(Term(0, 0, 0, 0))) {
                polynom.push_back(value);
            }
        }
        else if (polynom.top() == value) {
            if ((polynom.top() + value).isEqual(Term(0, 0, 0, 0))) {
                polynom.pop_back();
                if (polynom.size() == 0) {
                    polynom.push_back(Term(0, 0, 0, 0));
                }
            }
        }
        else {
            if (polynom.top().isEqual(Term(0, 0, 0, 0))) {
                polynom.pop_back();
            }
            for (List<Term>::Iterator iter = polynom.begin(); iter.isAtList(); iter++) {
                if (iter.current() == value) {
                    iter.current() = iter.current() + value;
                    if (iter.current().isEqual(Term(0, 0, 0, 0))) {
                        iter.pop();
                    }
                    return;
                }
                if (iter.current() > value) {
                    iter--;
                    iter.push(value);
                    return;
                }
                if (!iter.hasNext()) {
                    iter.push(value);
                    return;
                }
            }
        }
    }
    void push(int a, int x, int y, int z) {
        push(Term(a, x, y, z));
    }
    
    Polynomial operator*(int a) const {
        Polynomial temp;
        for (List<Term>::Iterator iter = polynom.begin(); iter.isAtList(); iter++) {
            temp.push(iter.current() * a);
        }
        return temp;
    }
    
    Polynomial operator+(const Term& t) const {
        Polynomial temp(*this);
        temp.push(t);
        return temp;
    }
    Polynomial operator+(const Polynomial& p) const {
        Polynomial temp(*this);
        for (List<Term>::Iterator iter = p.polynom.begin(); iter.isAtList(); iter++) {
            temp.push(iter.current());
        }
        return temp;
    }
    
    Polynomial operator-(const Term& t) const {
        Term temp = t * (-1);
        return *this - temp;
    }
    Polynomial operator-(const Polynomial& p) const {
        Polynomial temp = p * (-1);
        return *this - temp;
    }
    
    Polynomial operator*(const Term& t) const {
        Polynomial temp;
        for (List<Term>::Iterator iter = polynom.begin(); iter.isAtList(); iter++) {
            temp.push(iter.current() * t);
        }
        return temp;
    }
    Polynomial operator*(const Polynomial& p) const {
        Polynomial temp;
        for (List<Term>::Iterator iter1 = polynom.begin(); iter1.isAtList(); iter1++) {
            for (List<Term>::Iterator iter2 = p.polynom.begin(); iter2.isAtList(); iter2++) {
                Term term = iter1.current() * iter2.current();
                temp.push(term);
            }
        }
        return temp;
    }
    bool operator==(const Polynomial& p) const {
        if (size() != p.size()) {
            return false;
        }
        List<Term>::Iterator iter1 = polynom.begin();
        List<Term>::Iterator iter2 = p.polynom.begin();
        for (; iter1.isAtList(); iter1++, iter2++) {
            if (iter1.current() != iter2.current()) {
                return false;
            }
        }
        return true;
    }
    
    List<Term> getList() {
        return polynom;
    }
    
    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        os << p.polynom;
        return os;
    }
    friend istream& operator>>(istream& is, Polynomial& p) {
        is >> p.polynom;
        return is;
    }
};
