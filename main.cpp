#include <iostream>
#include "Library/String/MAIN/String.h"

int main() {
    String str("hello world");
    std::cout << str << std::endl;
    str.Clear();
    str += "hello";
    std::cout <<str << std::endl;
    return 0;
}