#include "String.h"

#include <cstring>

String::String() : CharacterNumber( 0 ), capacity( 10 ), text( new char[capacity] ), AuxiliaryText( nullptr ) {
    this->AddNullChar();
}

String::String(const String& other) : AuxiliaryText( nullptr ) {
    this->CharacterNumber = other.CharacterNumber;
    this->capacity = other.capacity;
    this->text = new char[this->capacity];
    for (int i = 0; i < this->CharacterNumber; ++i) {
        this->text[i] = other.text[i];
    }
}

String::String(String&& other) noexcept {
    this->CharacterNumber = other.CharacterNumber;
    this->capacity = other.capacity;
    this->text = other.text;
    this->AuxiliaryText = other.AuxiliaryText;

    other.CharacterNumber = 0;
    other.capacity = 0;
    other.text = nullptr;
    other.AuxiliaryText = nullptr;
}

String::String(const char* str) : AuxiliaryText( nullptr ) {
    const std::size_t STR_LEN = String::LengthOfConstChar( str );
    if (STR_LEN == 0) {
        this->capacity = 10;
    } else {
        this->capacity = STR_LEN * 2;
    }
    this->CharacterNumber = STR_LEN;
    this->text = new char[this->capacity];
    for (int i = 0; i < this->CharacterNumber; ++i) {
        *(this->text + i) = *(str + i);
    }
    this->AddNullChar();
}

String::String(const std::size_t& CAPACITY) : CharacterNumber( 0 ), capacity( CAPACITY ), text( new char[capacity] ), AuxiliaryText( nullptr ) {}

std::size_t String::LengthOfConstChar(const char* str) {
    if (str == nullptr) {
        return 0;
    }
    std::size_t LengthCounter = 0;
    for (; str[LengthCounter] != '\0'; ++LengthCounter) {}
    return LengthCounter;
}

void String::AddNullChar() {
    if (this->IsFull()) {
        this->Resize();
    }
    *(this->text + this->CharacterNumber) = '\0';
}

void String::CopyTextToAuxiliaryText() const {
    for (std::size_t i = 0; i < this->CharacterNumber; ++i) {
        *(this->AuxiliaryText + i) = *(this->text + i);
    }
}

char* String::begin() {
    return this->text;
}

const char* String::begin() const {
    return text;
}

const char* String::end() const {
    return text + CharacterNumber;
}

char* String::end() {
    return (this->text + this->CharacterNumber);
}

bool String::IsEmpty() const {
    return CharacterNumber == 0;
}

bool String::IsFull() const {
    return CharacterNumber == capacity;
}

void String::Resize() {
    if (this->IsEmpty()) {
        return;
    }
    capacity *= 2;
    AuxiliaryText = new char[capacity];
    for (std::size_t i = 0; i < this->CharacterNumber; ++i) {
        *(AuxiliaryText + i) = *(this->text + i);
    }
    delete[] this->text;
    this->text = this->AuxiliaryText;
}

void String::Reserve(const int&& size) {
    this->capacity = this->CharacterNumber + size + 1;
    AuxiliaryText = new char[this->capacity];
    this->CopyTextToAuxiliaryText();
    delete[] text;
    text = AuxiliaryText;
}

void String::Reserve(const int& size) {
    this->capacity = this->CharacterNumber + size + 1;
    AuxiliaryText = new char[this->capacity];
    this->CopyTextToAuxiliaryText();
    delete[] text;
    text = AuxiliaryText;
}

void String::Clear() {
    delete[] text;
    this->text = nullptr;
    this->AuxiliaryText = nullptr;
    this->CharacterNumber = static_cast<std::size_t>(0);
    this->capacity = static_cast<std::size_t>(10);
    text = new char[capacity];
    AuxiliaryText = text;
    this->AddNullChar();
}

void String::Copy(const String& other) {
    this->Clear();
    this->CharacterNumber = other.CharacterNumber;
    this->capacity = other.capacity;
    this->text = new char[this->capacity];
    for (std::size_t i = 0; i < this->CharacterNumber; ++i) {
        *(this->text + i) = *(other.text + i);
    }
}

std::size_t String::Capacity() const {
    return this->capacity;
}

std::size_t String::Length() const {
    return this->CharacterNumber;
}

bool String::operator==(const String& other) const {
    if (this->CharacterNumber != other.CharacterNumber) {
        return false;
    }
    for (std::size_t i = 0; i < this->CharacterNumber; ++i) {
        if (*(this->text + i) != *(other.text + i)) {
            return false;
        }
    }
    return true;
}

String& String::operator+=(const char& character) {
    if (this->CharacterNumber + 1 >= this->capacity) {
        this->Resize();
    }
    *(this->text + this->CharacterNumber++) = character;
    this->AddNullChar();
    return *this;
}

String& String::operator+=(const char&& character) {
    if (this->CharacterNumber + 1 >= this->capacity) {
        this->Resize();
    }
    *(this->text + this->CharacterNumber++) = character;
    this->AddNullChar();
    return *this;
}

String& String::operator+=(const char* str) {
    const std::size_t STR_LEN = String::LengthOfConstChar( str );
    this->Reserve( static_cast<int>(STR_LEN) );
    for (std::size_t i = 0; i < STR_LEN; ++i) {
        *(this->text + this->CharacterNumber++) = *(str + i);
    }
    this->AddNullChar();
    return *this;
}

String& String::operator+=(const String& other) {
    const std::size_t STR_LEN = String::LengthOfConstChar( other.text );
    this->Reserve( static_cast<int>(STR_LEN) );
    for (std::size_t i = 0; i < STR_LEN; ++i) {
        *(this->text + this->CharacterNumber++) = *(other.text + i);
    }
    this->AddNullChar();
    return *this;
}

String& String::operator=(const char* InputString) {
    this->Clear();
    this->CharacterNumber = String::LengthOfConstChar( InputString );
    this->capacity = this->CharacterNumber * 2;
    this->text = new char[this->capacity];
    for (int i = 0; i < this->CharacterNumber; ++i) {
        *(this->text + i) = *(InputString + i);
    }
    this->AddNullChar();
    return *this;
}

String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }
    this->Copy( other );
    return *this;
}

char String::operator[](const int index) const {
    try {
        if (const int MaxNegativeInt = 0 - static_cast<int>(this->CharacterNumber); index < MaxNegativeInt || index >= static_cast<int>(this->CharacterNumber)) {
            throw IndexOutOfRange();
        }
        if (index < 0) {
            return *(this->text + (this->CharacterNumber + index));
        }
        return *(this->text + index);
    } catch (const IndexOutOfRange& e) {
        std::cerr << "Error: " << e.what();
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what();
        std::cout << std::endl;
    }
    return '\0';
}

String::~String() {
    delete[] this->text;
    text = nullptr;
}