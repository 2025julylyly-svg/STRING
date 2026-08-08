#include <iostream>
#include "Library/String/MAIN/String.h"

int main() {
    String str ("hello");
    std::cout << str << std::endl;
    str += " world";
    std::cout << str << std::endl;
    return 0;
}