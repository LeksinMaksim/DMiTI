#include "Integer.h"

Integer::Integer(){
    sign = 0;
    size = 0;
}
Integer::Integer(const Integer& another_number){
    sign = another_number.sign;
    size = another_number.size;
    digits = another_number.digits;
}
Integer::Integer(int number){
    if (number<0){
        sign = 1;
        number = -number;
    }else{
        sign = 0;
    }
    while (number>0){
        digits.insert(digits.begin(),number%10);
        number = number/10;
    }
    size = digits.size();
}
Integer::Integer(int new_sign, int new_size, std::vector<int> new_digits){
    sign = new_sign;
    size = new_size;
    digits = new_digits;
}
Integer Integer::operator=(Integer& another_number){
    sign = another_number.sign;
    size = another_number.size;
    digits = another_number.digits;
    return *this;
}