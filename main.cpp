#include <iostream>
#include "Library/String/MAIN/String.h"

int main() {
    String str ("Hello World!");
    str += " i am peyman, and i have a strong passion for C++.";
    std::cout << str.Get();
    return 0;
}