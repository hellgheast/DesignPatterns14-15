#ifndef PEACH_H
#define PEACH_H

#include "Fruit.h"
class Peach : public Fruit
{
    public:
        Peach() {}
        virtual ~Peach() {}
        bool hasPip() const {return true;}
        void showFruit() const;
    protected:
    private:
};

#endif // PEACH_H
