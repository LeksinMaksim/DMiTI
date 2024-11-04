#ifndef INTEGER_HEADER
#define INTEGER_HEADER

#include <iostream>
#include <vector>
#include "StatusCode.h"

class Integer{
	private:
		bool sign;
		size_t size;
		std::vector<size_t> digits;
	public:
		Integer();
		Integer(int number);
		Integer(const Integer& otherNumber);
		bool getSign();
		size_t getSize();
		void setSize(size_t newSize);
		std::string getStrReference();
		std::vector<size_t> getDigits();
		std::pair<StatusCode, size_t> getDigit(size_t position);
		void setDigit(size_t digit, size_t position);
		void setDigits(std::vector<size_t> newDigits);
		void setSign(bool newSign);
		Integer& operator=(const Integer& number);
};

#endif
