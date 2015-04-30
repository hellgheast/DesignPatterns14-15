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
#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"

class Banana : public Fruit
{
    public:
        Banana() {}
        virtual ~Banana() {}
        bool hasPip() const {return false;}
        void showFruit() const;
    protected:
    private:
};


#endif // BANANA_H
