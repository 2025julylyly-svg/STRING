#pragma once
#include <exception>
#include <stdexcept>

class IndexOutOfRange final : public std::out_of_range
{
public:
    explicit IndexOutOfRange();
};