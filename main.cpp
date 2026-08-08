#include <iostream>
#include "Library/String/MAIN/String.h"
int main() {
    String str;
    std::cout << "Enter Str: ";
    std::cin >> str;
    std::cout << str.Get();
    return 0;
}