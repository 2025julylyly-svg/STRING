#pragma once
#include <exception>
#include <stdexcept>

class IndexOutOfRange : public std::out_of_range
{
public:
    explicit IndexOutOfRange();
};