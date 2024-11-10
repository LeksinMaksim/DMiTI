#ifndef NATURAL_NUMBERS_HEADER
#define NATURAL_NUMBERS_HEADER

#include <iostream>
#include <vector>

#include "StatusCode.h"

class NaturalNumbers
{
private:
    size_t size;
    std::vector<size_t> digits;

public:
    NaturalNumbers();
    NaturalNumbers(size_t number);
    NaturalNumbers(const NaturalNumbers& otherNumber);
    std::vector<size_t> getDigits();
    size_t getSize();
    void setSize(size_t newSize);
    std::string getStrReference();
    void setDigit(size_t Digit, size_t position);
    void setDigits(std::vector<size_t> newDigits);
    std::pair<StatusCode, size_t> getDigit(size_t position);
    NaturalNumbers& operator=(const NaturalNumbers& number);
};

#endif