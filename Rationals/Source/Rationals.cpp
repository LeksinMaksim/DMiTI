#include "Rationals.h"

Rationals::Rationals(){
    this->numerator = Integer(0);
    this->denominator = NaturalNumbers(1);
    this->sign = NullStatus;
    this->numeratorSize = 0;
    this->denominatorSize = 0;
}

Rationals::Rationals(int numerator, size_t denominator){
    this->numerator = Integer(numerator);
    this->denominator = NaturalNumbers(denominator);
    this->sign = this->numerator.getSign();
    this->numeratorSize = this->numerator.getSize();
    this->denominatorSize = this->denominator.getSize();
}

Rationals::Rationals(Integer numerator, NaturalNumbers denominator){
    this->numerator = numerator;
    this->denominator = denominator;
    this->sign = this->numerator.getSign();
    this->numeratorSize = this->numerator.getSize();
    this->denominatorSize = this->denominator.getSize();
}


SignStatus Rationals::getSign(){
    return this->sign;
}

Integer Rationals::getNumerator(){
    return this->numerator;
}

NaturalNumbers Rationals::getDenominator(){
    return this->denominator;
}

size_t Rationals::getNumeratorSize(){
    return this->numeratorSize;
}

size_t Rationals::getDenominatorSize(){
    return this->denominatorSize;
}

std::vector<size_t> Rationals::getNumeratorDigits(){
    return this->numerator.getDigits();
}

std::vector<size_t> Rationals::getDenominatorDigits(){
    return this->denominator.getDigits();
}

std::string Rationals::getStrReference(){
    return this->numerator.getStrReference() + "/" + this->denominator.getStrReference();
}

void Rationals::setSign(SignStatus newSign){
    this->sign = newSign;
    this->numerator.setSign(newSign);
}

void Rationals::setNumerator(Integer newNumerator){
    this->numerator = newNumerator;
    this->sign = newNumerator.getSign();
    this->numeratorSize = newNumerator.getSize();
}

void Rationals::setNumerator(int newNumerator){
    Integer newNumeratorInt = Integer(newNumerator);
    this->numerator = newNumeratorInt;
    this->sign = newNumeratorInt.getSign();
    this->numeratorSize = newNumeratorInt.getSize();
}

void Rationals::setDenominator(NaturalNumbers newDenominator){
    this->denominator = newDenominator;
    this->denominatorSize = newDenominator.getSize();
}

void Rationals::setDenominator(size_t newDenominator){
    NaturalNumbers newDenominatorNN = NaturalNumbers(newDenominator);
    this->denominator = newDenominatorNN;
    this->denominatorSize = newDenominatorNN.getSize();
}

Rationals& Rationals::operator=(const Rationals& fractionOther){
    if(&fractionOther != this){
        this->numerator = fractionOther.numerator;
        this->denominator = fractionOther.denominator;
        this->setSign(fractionOther.sign);
        this->numeratorSize = fractionOther.numeratorSize;
        this->denominatorSize = fractionOther.denominatorSize;
    }
    return *this;
}
