#include "Integer.h"

Integer::Integer(){
	this->sign = true;
	this->size = 0;
}

Integer::Integer(int number){
	this->sign = number >= 0 ? true : false;
	if (number == 0){
		this->digits.resize(1);
		this->digits.at(0) = 0;
		this->size = 1;
	}
	while (number > 0){
		this->digits.insert(this->digits.begin(), number % 10);
		number /= 10;
		this->size = this->digits.size();
	}
}
		
Integer::Integer(const Integer& otherNumber){
	this->sign = otherNumber.sign;
	this->size = otherNumber.size;
	this->digits = otherNumber.digits;
}	

bool Integer::getSign(){
	return this->sign;
}

size_t Integer::getSize(){
	return this->size;
}

void Integer::setSize(size_t newSize){
	this->size = newSize;
}

std::vector<size_t> Integer::getDigits(){
	return this->digits;
}

size_t Integer::getDigit(size_t position){
	if (position >= this->size){
		return 0;
	}
	return this->digits.at(position);
}

void Integer::setDigit(size_t digit, size_t position){
	if (position >= this->size || digit >= 10) return;
	this->digits.at(position) = digit;
}

void Integer::setDigits(std::vector<size_t> newDigits){
	this->digits.clear();
	this->digits = newDigits;
	this->setSize(newDigits.size());
}

void Integer::setSign(bool newSign){
	this->sign = newSign;
}

Integer& Integer::operator=(const Integer& number){
	if (&number != this){
		this->setSign(number.sign);
		this->digits.clear();
		this->setDigits(number.digits);
	}
	return *this;
}
