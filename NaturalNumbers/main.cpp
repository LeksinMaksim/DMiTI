#include "MUL_NN_N.h"
#include "NaturalNumbers.h"

int main(){
    size_t num,num1;
    std::cin>>num;
    std::cin>>num1;

    NaturalNumbers number(num);
    NaturalNumbers number1(num1);
    NaturalNumbers num2 = MUL_NN_N(number, number1);
    std::cout<<num2.getStrReference()<<std::endl;
}