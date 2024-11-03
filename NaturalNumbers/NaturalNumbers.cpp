#include "NaturalNumbers.h"


NaturalNumbers::NaturalNumbers(size_t number){
	while (number > 0){
		this->digits.insert(this->digits.begin(), number % 10);
		number /= 10;
		this->size = this->digits.size();
	}			
}

NaturalNumbers::NaturalNumbers(const NaturalNumbers& otherNumber){
	this->size = otherNumber.size;
	this->digits = otherNumber.digits;
}

std::vector<size_t> NaturalNumbers::getDigits(){
	return this->digits;
}
		
size_t NaturalNumbers::getSize(){
	return this->size;
}
		
std::string NaturalNumbers::getStrReference(){
	std::string result;
	for (size_t digit : this->digits){
		result += std::to_string(digit);
	}
	return result;	
}
