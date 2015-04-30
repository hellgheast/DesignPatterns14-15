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
#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "Fruit.h"
class Strawberry : public Fruit
{
    public:
        Strawberry() {}
        virtual ~Strawberry() {}
        bool hasPip() const {return false;}
        void showFruit() const;
    protected:
    private:
};


#endif // STRAWBERRY_H
