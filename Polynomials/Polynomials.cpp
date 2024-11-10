#include "Polynomials.h"

//Node

Node::Node(Rationals multiplier, Integer degree)
{
    this->multiplier = multiplier;
    this->degree = degree;
    this->next = nullptr;
    this->prev = nullptr;
}
Rationals Node::getNodeMultiplier()
{
    return this->multiplier;
}
Integer Node::getNodeDegree()
{
    return this->degree;
}
Node* Node::getNext()
{
    return this->next;
}
Node* Node::getPrev()
{
    return this->prev;
}
void Node::setNodeDegree(Integer degree)
{
    this->degree = degree;
}
void Node::setNodeMultiplie(Rationals multiplier)
{
    this->multiplier = multiplier;
}
void Node::setNext(Node* next)
{
    this->next = next;
}
void Node::setPrev(Node* prev)
{
    this->prev = prev;
}

//Node end

//Linked List

Polynomials::Polynomials()
{
    this->head = nullptr;
    this->size = 0;
    this->maxDegree = Integer(-10000);
}
void Polynomials::insertElem(Rationals multiplier, Integer degree)
{
    if(degree > this->maxDegree)
        this->maxDegree = degree;
    if(multiplier.getStrReference().compare(0,1,"0"))
        this->size++;
    Node* newNode = new Node(multiplier, degree);
    if(this->head == nullptr)
    {
        this->head = newNode;
        return;
    }
    Node* current = this->head;
    while(current->getNext() != nullptr && degree > current->getNodeDegree())
        current = current->getNext();
    if(degree > current->getNodeDegree())
    {
        newNode->setPrev(current);
        current->setNext(newNode);
    }
    else if(current->getNodeDegree() == degree)
    {
        current->setNodeDegree(degree);
    }
    else if(current->getNodeDegree() > degree)
    {
        newNode->setNext(current);
        if(this->head != current)
            current->getPrev()->setNext(newNode);
        else
            this->head = newNode;
        newNode->setPrev(current->getPrev());
        current->setPrev(newNode);
    }
}
void Polynomials::popElem(Integer degree)
{
    if(this->head == nullptr)
        return;
    Node* current = this->head;
    while(current->getNext() != nullptr && degree > current->getNodeDegree())
        current = current->getNext();
    if(current->getNodeDegree() == degree)
    {
        this->size--;
        if(current->getNodeDegree() == this->maxDegree)
        {
            if(current->getPrev() != nullptr)
                this->maxDegree = current->getPrev()->getNodeDegree();
        }
        if(this->head == current)
        {
            this->head = current->getNext();
            current->setPrev(nullptr);
            return;
        }
        current->getPrev()->setNext(current->getNext());
        if(current->getNext() != nullptr)
            current->getNext()->setPrev(current->getPrev());
    }
    return;
}
Node* Polynomials::getElem(Integer degree)
{
    Node* current = this->head;
    if(this->head == nullptr)
        return nullptr;
    while(current->getNext() != nullptr && degree > current->getNodeDegree())
        current = current->getNext();
    if(current == nullptr)
        return nullptr;
    if(current->getNodeDegree() == degree)
        return current;
    return nullptr;
}
Node* Polynomials::getHead()
{
    return this->head;
}
void Polynomials::setHead(Node* head)
{
    this->head = head;
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
    if(this->head == nullptr)
        return "Nothing";
    Node* current = this->head;
    std::string result = "";
    while(current != nullptr)
    {
        if(current->getNodeMultiplier().getStrReference().compare(0,1,"0"))
        {
            if(current->getNodeMultiplier().getSign() == Positive && current != this->head)
            result += '+';
            if(current->getNodeDegree().getStrReference().compare("0"))
                result += current->getNodeMultiplier().getStrReference() + "x^" + current->getNodeDegree().getStrReference();
            else
                result += current->getNodeMultiplier().getStrReference();
            
        }
        current = current->getNext();
    }
    if(!result.compare(""))
        return "Nothing";
    return result;
}
// Linked List end