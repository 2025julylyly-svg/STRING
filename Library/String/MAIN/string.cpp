#include "string.h"

#include <cstring>
String::String() : CharacterNumber( 0 ), capacity( 10 ), text( new char[capacity] ) {}

String::String(const std::size_t& CAPACITY) : CharacterNumber( 0 ), capacity( CAPACITY ), text( new char[capacity] ) {}

void String::Free() {
    delete[] text;
}

std::size_t String::LengthOfConstChar(const char* str) {
    if (str == nullptr) {
        return static_cast<std::size_t>(0);
    }
    std::size_t LengthCounter = 0;
    for (; str[LengthCounter] != '\0'; ++LengthCounter);
    return LengthCounter;
}

char* String::begin() const {
    return text;
}

char* String::end() const {
    return static_cast<char*>(text + CharacterNumber);
}

bool String::IsEmpty() const {
    return CharacterNumber == 0;
}

bool String::IsFull() const {
    return CharacterNumber == capacity;
}

void String::Resize() {}

void String::Clear() {}

void String::Copy(const String& other) {}

String& String::operator=(const char* InputString) {

}

String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }
    this->Free();
    this->CharacterNumber = other.CharacterNumber;
    this->capacity = other.capacity;
    this->text = new char[this->capacity];
    char other_char = *(other.text + 0);
    int ThisIndexCounter = 0;
    while (other_char != '\0' && ThisIndexCounter < this->CharacterNumber) {
        *(this->text + ThisIndexCounter++) = other_char;
        other_char = *(other.text + ThisIndexCounter);
    }
    return *this;
}

char String::operator[](const int index) const {
    try {
        if (index < 0 or index >= CharacterNumber) {
            throw IndexOutOfRange();
        }
        return static_cast<char>(*(text + index));
    } catch (const IndexOutOfRange& e) {
        std::cerr << "Error: " << e.what();
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr <<"Error: " << e.what();
        std::cout << std::endl;
    }
    return '\0';
}