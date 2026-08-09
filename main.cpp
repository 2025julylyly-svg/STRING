#include <iostream>
#include "Library/String/MAIN/String.h"

int main() {
    String str("hello world");
    std::cout <<str[-1];
    return 0;
}