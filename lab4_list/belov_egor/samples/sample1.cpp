// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
//
//
//
//
#include <iostream>
#include "polynomial.h"
using namespace std;


#ifndef SAMPLE1 //



int main() {
    Polynomial a, b, c;
    
    size_t n, m;
    cout << "Enter the size of the first polynom" << endl;
    cin >> n;
    cout << endl;
    
    cout << "Enter the fisrt polynomial" << endl;
    for (size_t i = 0; i < n; i++) {
        Term temp;
        cin >> temp;
        a.push(temp);
    }
    cout << endl;
    cout << a;
    cout << endl;
    
    cout << "Enter the size of the second polynom" << endl;
    cin >> m;
    cout << endl;
    
    cout << "Enter the second polynomial" << endl;
    for (size_t i = 0; i < m; i++) {
        Term temp;
        cin >> temp;
        b.push(temp);
    }
    cout << endl;
    cout << b;
    cout << endl;
    
    c = a * b;
    cout << c;
    
    return 0;
}
#endif
