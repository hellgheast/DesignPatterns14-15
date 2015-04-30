#include "Decorator.h"

Decorator::Decorator(Fruit* fruit)
{
    this->fruit = fruit;
}

Decorator::~Decorator()
{
    //dtor
}
