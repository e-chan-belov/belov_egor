﻿#include <iostream>
#include <string>
#include "postfix.h"
#include "stack.h"
using namespace std;

int main()
{
    //Calc c("12-2)*34+2");
    Calc c("(12-2)+34*2");
    try{
        std::cout << c.postfixed() << "\n";
        std::cout <<c.calculate();

    } 
    catch(string a){
        std::cout << a;
    }
}