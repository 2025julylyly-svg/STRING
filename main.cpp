#include <iostream>
#include "Library/String/MAIN/String.h"

int main() {
    String str("");
    for (int i =0;i < 10;++i) {
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            str += ch;
            str += static_cast<char> (ch + 32);
            str += ' ';
        }
        str += " | ";
    }
    std::cout << str.Get();
    return 0;
}