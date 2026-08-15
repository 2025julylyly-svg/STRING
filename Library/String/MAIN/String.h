#pragma once
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
    void AddNullChar();
    void CopyTextToAuxiliaryText() const;

public:
    explicit String();
    String(const String&);
    explicit String(String&&) noexcept;
    String(const char*);
    explicit String(const std::size_t&);
    [[nodiscard]] char* begin();
    [[nodiscard]] const char* begin() const;
    [[nodiscard]] char* end();
    [[nodiscard]] const char* end() const;
    void Resize();
    void Reserve(const int&&);
    void Reserve(const int&);
    void Clear();
    [[nodiscard] ] bool IsEmpty() const;
    [[nodiscard]] bool IsFull() const;
    void Copy(const String&);
    [[nodiscard]] String substr(const int& ,const int& ) const;
    [[nodiscard]] String substr(const int&& ,const int&& ) const;
    [[nodiscard]] std::size_t Capacity() const;
    [[nodiscard]] std::size_t Length() const;
    // operators
    bool operator==(const String&) const;
    String& operator+=(const char&);
    String& operator+=(const char&&);
    String& operator+=(const char*);
    String& operator+=(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    char operator[](int) const;
    ~String();
};

inline std::istream& operator>>(std::istream& is, String& str) {
    char ch;
    while (is.get( ch )) {
        if (ch == '\n') {
            break;
        }
        str += ch;
    }
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const String& str) {
    for (int counter = 0; counter < str.Length(); ++counter) {
        os << str[counter];
    }
    return os;
}