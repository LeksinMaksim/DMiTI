#ifndef RATIONALS_HEADER
#define RATIONALS_HEADER

#include "../Integers/Integer.h"
#include "../NaturalNumbers/NaturalNumbers.h"
#include "SignStatus.h"

class Rationals{
    private:
        Integer numerator;
        NaturalNumbers denominator;
        SignStatus sign;
        size_t numeratorSize;
        size_t denominatorSize;
    public:
        Rationals(); 
        Rationals(int numerator, size_t denominator = 1);
        Rationals(Integer numerator, NaturalNumbers denominator = NaturalNumbers(1));
        SignStatus getSign();
        Integer getNumerator();
        NaturalNumbers getDenominator();
        size_t getNumeratorSize();
        size_t getDenominatorSize();
        std::vector<size_t> getNumeratorDigits();
        std::vector<size_t> getDenominatorDigits();
        std::string getStrReference();
        void setSign(SignStatus newSign);
        void setNumerator(Integer newNumerator);
        void setNumerator(int newNumerator);
        void setDenominator(NaturalNumbers newDenominator);
        void setDenominator(size_t newDenominator);
        Rationals& operator=(const Rationals& fractionOther);
};

#endif