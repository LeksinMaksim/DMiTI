#include "ADD_NN_N.h"

NaturalNumbers ADD_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
    if(COM_NN_D(firstNumber, secondNumber) == 1)
        std::swap(firstNumber, secondNumber);

    std::vector<size_t>first = firstNumber.getDigits();
    std::vector<size_t>second = secondNumber.getDigits();
    std::reverse(first.begin(), first.end());
    std::reverse(second.begin(), second.end());

    size_t k = 0;
    size_t highDigit = 0;

    while(k < second.size()){
        highDigit = (first[k] + second[k]) / 10; 
        first[k] = (first[k] + second[k]) % 10;
        k++;
        if(k < second.size())
            first[k] += highDigit;
    }
    if(highDigit){
        while(k < first.size() && first[k] > 8){
            first[k] = 0;
            k++;
        }
        if(k == first.size()) 
            first.push_back(highDigit);
        else
            first[k] += highDigit;
    }
    std::reverse(first.begin(), first.end());
    NaturalNumbers newNumber = {0};
    newNumber.setDigits(first);
    return newNumber;
}
