#ifndef INTEGER_HEADER
#define INTEGER_HEADER

#include <iostream>
#include <vector>

class Integer{
	private:
		bool sign;
		size_t size;
		std::vector<size_t> digits;
	public:
		Integer(int number);
		Integer(const Integer& otherNumber);
		bool getSign();
		size_t getSize();
		void setSize(size_t newSize);
		std::vector<size_t> getDigits();
		size_t getDigit(size_t position);
		void setDigit(size_t digit, size_t position);
		void Integer::setDigits(std::vector<size_t> newDigits);
		void setSign(bool newSign);
		Integer& operator=(const Integer& number);
};

#endif
