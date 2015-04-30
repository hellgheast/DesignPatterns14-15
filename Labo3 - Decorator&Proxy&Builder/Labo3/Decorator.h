#ifndef DECORATOR_H
#define DECORATOR_H

#include "Fruit.h"
class Decorator
{
    public:
        Decorator(Fruit * fruit);
        virtual ~Decorator();
    protected:
    private:
        Fruit* fruit;
};

#endif // DECORATOR_H
