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

#ifndef STAR_H
#define STAR_H

#include "Decorator.h"

class Star : public Decorator
{
    public:
        Star(Fruit * fruit);
        virtual ~Star();
        char getDecoration() const;
    protected:
    private:
};

#endif // STAR_H
