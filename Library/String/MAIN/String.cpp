#include "String.h"

String::String() : CharacterNumber( 0 ), capacity( 10 ), text( new char[capacity] ), AuxiliaryText( nullptr ) {}

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
        return static_cast<std::size_t>(0);
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
    delete[] text;
    this->text = nullptr;
    this->AuxiliaryText = nullptr;
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

char* String::Get() const {
    return this->begin();
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

String& String::operator+=(char character) {
    if (this->CharacterNumber + 1 >= this->capacity) {
        this->Resize();
    }
    *(this->text + this->CharacterNumber++) = character;
    this->AddNullChar();
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
    this->AddNullChar();
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
        if (const int IndexCheck = 0 - static_cast<int>(CharacterNumber); index >= IndexCheck || index < this->CharacterNumber) {
            if (index < 0) {
                return this->text[CharacterNumber + index];
            }
            return this->text[index];
        }
        else {
            throw IndexOutOfRange();
        }
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