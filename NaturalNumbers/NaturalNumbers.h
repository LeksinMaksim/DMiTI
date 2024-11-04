#ifndef NATURAL_NUMBERS_HEADER
#define NATURAL_NUMBERS_HEADER

#include <iostream>
#include <vector>

class NaturalNumbers{
	private:
		size_t size;
		std::vector<size_t> digits;
	public:
		NaturalNumbers();
		NaturalNumbers(size_t number);
		NaturalNumbers(const NaturalNumbers& otherNumber);
		std::vector<size_t> getDigits();
		size_t getSize();
		std::string getStrReference();
		void setSize(size_t size);
		void setDigit(size_t Digit, size_t position);
		void setDigits(std::vector<size_t> newDigits);
		size_t getDigit(size_t position);
};

#endif
