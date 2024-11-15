#ifndef __Polynomials__
#define __Polynomials__

#include<iostream>
#include<string>
#include "../../Rationals/Source/Rationals.h"
#include "../../NaturalNumbers/Source/NaturalNumbers.h"


class Elem
{
    public:
        Elem(Rationals multiplier, Integer degree);
        Elem(Elem& other);
        Rationals getNodeMultiplier();
        Integer getNodeDegree();
        void setNodeMultiplie(Rationals multiplier);
        void setNodeDegree(Integer degree);
        Elem& operator=(const Elem& other);
    private:
        Rationals multiplier;
        Integer degree;
};

class Polynomials
{
    public:
        Polynomials();
        Polynomials(std::string input);
        Polynomials(Polynomials& other);
        void insertElem(Rationals multiplier, Integer degree);
        void popElem(Integer degree);
        Elem* getElem(Integer degree);
        std::vector<Elem*> getElems();
        void setElems(std::vector<Elem*> elems);
        size_t getSize();
        Integer getMaxDegree();
        std::string getStrReference();
        Polynomials& operator=(const Polynomials& other);
    private:
        std::vector<Elem*>elems;
        size_t size;
        Integer maxDegree;
};

#endif //__Polynomials__