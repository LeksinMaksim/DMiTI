#include "Integer.h"

Integer::Integer()
{
    this->sign = NullStatus;
    this->size = 0;
}

Integer::Integer(int number)
{
    this->sign = number >= 0 ? Positive : Negative;
    if (number == 0)
    {
        this->digits.resize(1);
        this->digits.at(0) = 0;
        this->size = 1;
        this->setSign(NullStatus);
    }
    if (this->sign == false) number = -number;
    while (number > 0)
    {
        this->digits.insert(this->digits.begin(), number % 10);
        number /= 10;
        this->size = this->digits.size();
    }
}

Integer::Integer(const Integer& otherNumber)
{
    this->sign = otherNumber.sign;
    this->size = otherNumber.size;
    this->digits = otherNumber.digits;
}

SignStatus Integer::getSign() { return this->sign; }

size_t Integer::getSize() { return this->size; }

void Integer::setSize(size_t newSize) { this->size = newSize; }

std::string Integer::getStrReference()
{
    if (this->getSize() == 0) return "";
    if (this->getSize() == 1 && this->getDigit(0).second == 0) return "0";
    std::string result = (this->getSign() == Positive) ? "" : "-";
    for (size_t digit : this->digits)
    {
        result += std::to_string(digit);
    }
    return result;
}

std::vector<size_t> Integer::getDigits() { return this->digits; }

std::pair<StatusCode, size_t> Integer::getDigit(size_t position)
{
    if (position >= this->size)
    {
        return { Fail, 0 };
    }
    return { Successfull, this->digits.at(position) };
}

void Integer::setDigit(size_t digit, size_t position)
{
    if (position >= this->size || digit >= 10) return;
    this->digits.at(position) = digit;
}

void Integer::setDigits(std::vector<size_t> newDigits)
{
    this->digits.clear();
    this->digits = newDigits;
    this->setSize(newDigits.size());
}

void Integer::setSign(SignStatus newSign) { this->sign = newSign; }

Integer& Integer::operator=(const Integer& number)
{
    if (&number != this)
    {
        this->setSign(number.sign);
        this->digits.clear();
        this->setDigits(number.digits);
    }
    return *this;
}

Integer::Integer(std::string input)
{
    this->size = input.size();
    if (input[0] == '-')
    {
        this->sign = Negative;
        input = input.substr(1, input.size() - 1);
    }
    else
        this->sign = Positive;
    for (const char i : input) this->digits.push_back(i - '0');
}
bool Integer::operator>(const Integer& other)
{
    if (this->sign == Positive && other.sign == Negative)
        return true;
    else if (this->sign == Negative && other.sign == Positive)
        return false;
    else if (this->sign == Positive && this->size > other.size)
        return true;
    else if (this->sign == Positive && this->size < other.size)
        return false;
    else if (this->sign == Negative && this->size > other.size)
        return false;
    else if (this->sign == Negative && this->size < other.size)
        return true;
    else
    {
        std::vector<size_t> first = this->digits;
        std::vector<size_t> second = other.digits;
        // std::reverse(first.begin(), first.end());
        // std::reverse(second.begin(), second.end());
        if (this->sign == Positive)
        {
            size_t equal = 0;
            size_t i = 0;
            while (i < this->size)
            {
                if (first[i] > second[i]) return true;
                if (first[i] == second[i])
                    equal++;
                else
                    return false;
                i++;
            }
            if (equal == i) return false;
            return true;
        }
        else if (this->sign == Negative)
        {
            size_t equal = 0;
            size_t i = 0;
            while (i < this->size)
            {
                if (first[i] < second[i]) return true;
                if (first[i] == second[i])
                    equal++;
                else
                    return false;
                i++;
            }
            if (equal == i) return false;
            return true;
        }
        return false;
    }
}
bool Integer::operator==(const Integer& other)
{
    if (this->sign != other.sign || this->size != other.size) return false;
    for (size_t i = 0; i < this->size; i++)
    {
        if (this->digits[i] != other.digits[i]) return false;
    }
    return true;
}
