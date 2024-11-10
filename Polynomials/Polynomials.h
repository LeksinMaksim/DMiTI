#ifndef __Polynomials__
#define __Polynomials__

#include<iostream>
#include<string>
#include "../Rationals/Rationals.h"
#include "../NaturalNumbers/NaturalNumbers.h"

class Node
{
    public:
        Node(Rationals multiplier, Integer degree);
        Rationals getNodeMultiplier();
        Integer getNodeDegree();
        Node* getNext();
        Node* getPrev();
        void setNodeMultiplie(Rationals multiplier);
        void setNodeDegree(Integer degree);
        void setNext(Node* next);
        void setPrev(Node* prev);
    private:
        Rationals multiplier;
        Integer degree;
        Node* next;
        Node* prev;
};

class Polynomials
{
    public:
        Polynomials();
        void insertElem(Rationals multiplier, Integer degree);
        void popElem(Integer degree);
        Node* getElem(Integer degree);
        Node* getHead();
        void setHead(Node* root);
        size_t getSize();
        Integer getMaxDegree();
        std::string getStrReference();
    private:
        Node* head;
        size_t size;
        Integer maxDegree;
};

#endif //__Polynomials__