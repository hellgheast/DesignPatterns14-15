#ifndef SHARP_H
#define SHARP_H

#include "Decorator.h"
class Sharp : public Decorator
{
    public:
        Sharp(Fruit * fruit);
        virtual ~Sharp();
        char getDecoration() const;
    protected:
    private:
};


#endif // EQUAL_H
