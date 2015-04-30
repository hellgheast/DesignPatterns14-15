/*
	Design Patterns
	Labo3 : Panier de fruits avec State, Composite, Decorator
	Authors :
        - Karim Luy
        - Nicolas Gonin
        - Mathieu Bandelier
	Equipe1
************************************************************************
*/
#ifndef APPLE_H
#define APPLE_H

#include "Fruit.h"


class Apple : public Fruit
{
    public:
        Apple() {}
        virtual ~Apple() {}
        bool hasPip() const {return true;}
        void showFruit() const;
    protected:
    private:
};

#endif // APPLE_H
