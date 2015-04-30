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

#include "Equal.h"
#include <iostream>

using namespace std;

Equal::Equal(Fruit* fruit) : Decorator((Fruit*)fruit)
{
}

char Equal::getDecoration() const
{
    return '=';
}


Equal::~Equal()
{
    //dtor
}
