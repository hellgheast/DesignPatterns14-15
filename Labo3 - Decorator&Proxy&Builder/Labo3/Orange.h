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
#ifndef ORANGE_H
#define ORANGE_H

#include "Fruit.h"


class Orange : public Fruit
{
    public:
        Orange() {}
        virtual ~Orange() {}
        bool hasPip() const {return true;}
        void showFruit() const;
    protected:
    private:
};

#endif // ORANGE_H
