#ifndef EQUAL_H
#define EQUAL_H

#include "Fruit.h"
#include "Decorator.h"
class Equal : public Decorator
{
    public:
        Equal(Fruit * fruit);
        virtual ~Equal();
        char getDecoration() const;
    protected:
    private:
};


#endif // EQUAL_H
