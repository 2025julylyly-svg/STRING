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
    explicit String(const char*);
    explicit String(const std::size_t&);
    [[nodiscard]] char* begin() const;
    [[nodiscard]] char* end() const;
    void Resize();
    void Clear();
    [[nodiscard] ] bool IsEmpty() const;
    [[nodiscard]] bool IsFull() const;
    void Copy(const String&);
    [[nodiscard]] std::size_t Capacity() const;
    [[nodiscard]] std::size_t Length() const;
    [[nodiscard]] const char* Get() const;
    // operators
    String& operator+=(const char);
    String& operator+=(const char*);
    String& operator+=(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    char operator[](int) const;
    ~String();
};

inline std::istream& operator>>(std::istream& is, String& str) {
    char ch;
    while (is.get(ch)) {
        str += ch;
        if (ch == '\n') {
            break;
        }
    }
    return is;
}