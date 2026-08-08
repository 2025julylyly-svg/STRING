#include <iostream>
#include "Library/String/MAIN/String.h"

int main() {
    String str( "" );
    for (char ch = 'a'; ch <= 'z'; ch++) {
        str += static_cast<char>(ch - 32);
    }
    str += " | ";
    std::cout << str.Get() << std::endl;
    return 0;
}