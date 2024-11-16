#include "NaturalNumbers.h"

NaturalNumbers::NaturalNumbers() { this->size = 0; }

NaturalNumbers::NaturalNumbers(size_t number)
{
    if (number == 0)
    {
        this->digits.resize(1);
        this->digits.at(0) = 0;
        this->size = 1;
    }
    while (number > 0)
    {
        this->digits.insert(this->digits.begin(), number % 10);
        number /= 10;
        this->size = this->digits.size();
    }
}

NaturalNumbers::NaturalNumbers(const NaturalNumbers& otherNumber)
{
    this->size = otherNumber.size;
    this->digits = otherNumber.digits;
}

std::vector<size_t> NaturalNumbers::getDigits() { return this->digits; }

size_t NaturalNumbers::getSize() { return this->size; }

void NaturalNumbers::setSize(size_t newSize) { this->size = newSize; }

std::string NaturalNumbers::getStrReference()
{
    std::string result;
    for (size_t digit : this->digits)
    {
        result += std::to_string(digit);
    }
    return result;
}

void NaturalNumbers::setDigit(size_t digit, size_t position)
{
    if (position >= this->getSize()) return;
    this->digits.at(position) = digit;
}

void NaturalNumbers::setDigits(std::vector<size_t> newDigits)
{
    this->digits.clear();
    this->digits = newDigits;
    this->setSize(newDigits.size());
}

std::pair<StatusCode, size_t> NaturalNumbers::getDigit(size_t position)
{
    if (position >= this->getSize()) return { Fail, 0 };
    return { Successfull, this->digits.at(position) };
}

NaturalNumbers& NaturalNumbers::operator=(const NaturalNumbers& number)
{
    if (&number != this)
    {
        this->digits.clear();
        this->setDigits(number.digits);
    }
    return *this;
}

NaturalNumbers::NaturalNumbers(const std::string& number)
{
    this->size = 0;
    if (number.empty()) return;

    for (char c : number)
    {
        if (isdigit(c))
        {
            this->digits.push_back(c - '0');
        }
    }

    if (this->digits.empty())
    {
        this->digits.push_back(0);
    }

    this->size = this->digits.size();

    // Убираем ведущие нули
    while (this->size > 1 && this->digits[0] == 0)
    {
        this->digits.erase(this->digits.begin());
        this->size--;
    }
}
