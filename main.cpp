#include <iostream>
#include "Library/String/MAIN/String.h"
int main() {
    String str1;
    String str2;
    str1 = "Hello";
    str2 = " World! i am peyman. how are you?";
    str1 += str2;
    for (const auto& ch : str1) {
        std::cout << ch;
    }
    return 0;
}