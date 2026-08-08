#pragma once
#include <array>
#include <iostream>
#include "../Error/IndexOutofReangeError/IndexOutofrange.h"

class String
{
private:
    std::size_t CharacterNumber;
    std::size_t capacity;
    char* text;
    char* AuxiliaryText;
    static std::size_t LengthOfConstChar(const char*);
public:
    explicit String();
    explicit String(const std::size_t&);
    [[nodiscard]] char* begin() const;
    [[nodiscard]] char* end() const;
    void Resize();
    void Clear();
    [[nodiscard] ] bool IsEmpty() const;
    [[nodiscard]] bool IsFull() const;
    void Copy(const String&);
    // operators
    String& operator=(const char*);
    String& operator=(const String&);
    char operator[] (int) const;
};