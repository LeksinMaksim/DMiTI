#include "Polynomials.h"

//Node

Elem::Elem(Rationals multiplier, Integer degree)
{
    this->multiplier = multiplier;
    this->degree = degree;
}
Elem::Elem(Elem& other)
{
    this->multiplier = other.multiplier;
    this->degree = other.degree;
}
Rationals Elem::getNodeMultiplier()
{
    return this->multiplier;
}
Integer Elem::getNodeDegree()
{
    return this->degree;
}
void Elem::setNodeDegree(Integer degree)
{
    this->degree = degree;
}
void Elem::setNodeMultiplie(Rationals multiplier)
{
    this->multiplier = multiplier;
}
Elem& Elem::operator=(const Elem& other)
{
    if(this != &other)
    {
        this->degree = other.degree;
        this->multiplier = other.multiplier;
    }
    return *this;
}

//Node end

//Linked List

Polynomials::Polynomials()
{
    this->elems = std::vector<Elem*>();
    this->size = 0;
    this->maxDegree = Integer(-10000);
}
Polynomials::Polynomials(std::string input)
{
    this->elems = std::vector<Elem*>();
    this->size = 0;
    this->maxDegree = Integer(0);
    Rationals multiplier = Rationals();
    Integer degree = Integer();

    Integer numinator = Integer();
    NaturalNumbers denominator = NaturalNumbers();
    size_t cnt = 0;
    int start = -1;
    bool flag = false;
    for(size_t i = 0; i < input.size(); i++)
    {
        if((input[i] >= '0' && input[i] <= '9') || (i == 0 && i == '-'))
        {
            if(start == -1)
                start = i;
            cnt++;
        }
        else if(input[i] == '/')
        {
            if(start == -1)
            {
                std::cout<<"Input Error!"<<std::endl;
                return;
            }
            numinator = Integer(input.substr(start, cnt));
            cnt = 0;
            start = -1;
            flag = true;
        }
        else if(input[i] == 'x')
        {
            if(flag && start != - 1)
            {
                denominator = NaturalNumbers(input.substr(start, cnt));
                multiplier = Rationals(numinator, denominator);
            }
            else
            {
                numinator = Integer(input.substr(start, cnt));
                multiplier = Rationals(numinator);
            }
            flag = false;
            cnt = 0;
            start = -1;
        }
        else if(input[i] == '+' || input[i] == '-')
        {
            if(input[i] != '-')
            {
                if(start == -1)
                    degree = Integer(1);
                else
                    degree = Integer(input.substr(start, cnt));
                this->insertElem(multiplier, degree);
            }
            if(input[i] == '-')
            {
                start = i;
                cnt = 1;
            }
            else
            {
                start = -1;
                cnt = 0;
            }
        }
        if(i == input.size() - 1)
        {
            degree = Integer(input.substr(start, cnt));
            this->insertElem(multiplier, degree);
        }
    }
}
Polynomials::Polynomials(Polynomials& other)
{
    std::vector<Elem*>elemsCopy;
    for(size_t i = 0; i < other.elems.size(); i++)
    {
        Elem* newElem = new Elem(*other.elems[i]);
        elemsCopy.push_back(newElem);
    }
    this->elems = elemsCopy;
    this->maxDegree = other.maxDegree;
    this->size = other.size;
}
void Polynomials::insertElem(Rationals multiplier, Integer degree)
{
    if(degree > this->maxDegree)
        this->maxDegree = degree;
    if(!multiplier.getStrReference().compare(0,1,"0"))
        return;
    this->size++;
    Elem* newNode = new Elem(multiplier, degree);
    size_t i = 0;
    while(i < this->elems.size() && degree > this->elems[i]->getNodeDegree())
        i++;
    if(i == this->elems.size())
        this->elems.push_back(newNode);
    else if(i == 0)
        this->elems.insert(this->elems.begin(), newNode);
    else if(i != this->elems.size() && degree > this->elems[i-1]->getNodeDegree())
        this->elems.insert(this->elems.begin() + i, newNode);
    else if(this->elems[i]->getNodeDegree() == degree)
        this->elems[i]->setNodeMultiplie(multiplier);
    else if(this->elems[i]->getNodeDegree() > degree)
        this->elems.insert(this->elems.begin() + i, newNode);
}
void Polynomials::popElem(Integer degree)
{
    size_t i = 0;
    while(i < this->elems.size() && degree > this->elems[i]->getNodeDegree())
        i++;
    if(i < this->elems.size() && this->elems[i]->getNodeDegree() == degree)
    {
        this->size--;
        if(this->elems[i]->getNodeDegree() == this->maxDegree)
        {
            if(i - 1 >= 0)
                this->maxDegree = elems[i-1]->getNodeDegree();
        }
        this->elems.erase(this->elems.begin() + i);
    }
}
Elem* Polynomials::getElem(Integer degree)
{
    size_t i = 0;
    while(i > this->elems.size() && degree > this->elems[i]->getNodeDegree())
        i++;
    if(i == this->elems.size())
        return nullptr;
    if(elems[i]->getNodeDegree() == degree)
        return elems[i];
    return nullptr;
}
std::vector<Elem*> Polynomials::getElems()
{
    return this->elems;
}
void Polynomials::setElems(std::vector<Elem*>elems)
{
    this->elems = elems;
    this->size = elems.size();
    this->maxDegree = elems.back()->getNodeDegree();
}
size_t Polynomials::getSize()
{
    return this->size;
}
Integer Polynomials::getMaxDegree()
{
    return this->maxDegree;
}
std::string Polynomials::getStrReference()
{
    if(this->elems.size() == 0)
        return "Nothing";
    size_t i = 0;
    std::string result = "";
    while(i < this->elems.size())
    {
        if(elems[i]->getNodeMultiplier().getStrReference().compare(0,1,"0"))
        {
            if(elems[i]->getNodeMultiplier().getSign() == Positive && i != 0)
                result += '+';
            if(!(elems[i]->getNodeDegree().getStrReference().compare("1")))
                result += elems[i]->getNodeMultiplier().getStrReference() + "x";
            else if(!(elems[i]->getNodeDegree().getStrReference().compare("0")))
                result += elems[i]->getNodeMultiplier().getStrReference();
            else
                result += elems[i]->getNodeMultiplier().getStrReference() + "x^" + elems[i]->getNodeDegree().getStrReference();
            
        }
        i++;
    }
    if(!result.compare(""))
        return "Nothing";
    return result;
}
Polynomials& Polynomials::operator = (const Polynomials& other)
{
    if(this != &other)
    {
        std::vector<Elem*>elemsCopy;
        for(size_t i = 0; i < other.elems.size(); i++)
        {
            Elem* newElem = new Elem(*other.elems[i]);
            elemsCopy.push_back(newElem);
        }
        this->elems = elemsCopy;
        this->maxDegree = other.maxDegree;
        this->size = other.size;
    }
    return *this;
}
