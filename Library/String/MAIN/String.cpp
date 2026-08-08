#include "String.h"

String::String() : CharacterNumber( 0 ), capacity( 10 ), text( new char[capacity] ), AuxiliaryText( nullptr ) {}

String::String(const char* str) : AuxiliaryText( nullptr ) {
    const std::size_t STR_LEN = String::LengthOfConstChar( str );
    this->CharacterNumber = STR_LEN;
    this->capacity = STR_LEN * 2;
    this->text = new char[this->capacity];
    for (int i = 0; i < this->CharacterNumber; ++i) {
        *(this->text + i) = *(str + i);
    }
}

String::String(const std::size_t& CAPACITY) : CharacterNumber( 0 ), capacity( CAPACITY ), text( new char[capacity] ), AuxiliaryText( nullptr ) {}

std::size_t String::LengthOfConstChar(const char* str) {
    if (str == nullptr) {
        return static_cast<std::size_t>(0);
    }
    std::size_t LengthCounter = 0;
    for (; str[LengthCounter] != '\0'; ++LengthCounter) {}
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

void String::Clear() {
    this->CharacterNumber = static_cast<std::size_t>(0);
    this->capacity = static_cast<std::size_t>(10);
    this->text = nullptr;
    delete[] text;
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

const char* String::Get() const {
    return this->text;
}

String& String::operator+=(const char character) {
    if (this->CharacterNumber + 1 >= this->capacity) {
        this->Resize();
    }
    *(this->text + this->CharacterNumber++) = character;
    return *this;
}

String& String::operator+=(const char* str) {
    const std::size_t STR_LEN = String::LengthOfConstChar( str );
    while (STR_LEN + this->CharacterNumber >= this->capacity) {
        this->Resize();
    }
    for (std::size_t i = 0; i < STR_LEN; ++i) {
        *(this->text + this->CharacterNumber++) = *(str + i);
    }
    return *this;
}

String& String::operator+=(const String& other) {
    const std::size_t STR_LEN = String::LengthOfConstChar( other.text );
    while (STR_LEN + this->CharacterNumber >= this->capacity) {
        this->Resize();
    }
    for (std::size_t i = 0; i < STR_LEN; ++i) {
        *(this->text + this->CharacterNumber++) = *(other.text + i);
    }
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
    return *this;
}

String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }
    this->Copy( other );
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
        if (index < 0 || index >= CharacterNumber) {
            throw IndexOutOfRange();
        }
        return this->text[index];
    } catch (const IndexOutOfRange& e) {
        std::cerr << "Error: " << e.what();
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what();
        std::cout << std::endl;
    }
    return '\0';
}

String::~String() = default;