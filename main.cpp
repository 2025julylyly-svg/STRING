#include <iostream>
#include "Library/String/MAIN/String.h"

int main() {
    String str;
    str += "hello";
    std::cout << str.substr( 0, 2 );
    return 0;
}