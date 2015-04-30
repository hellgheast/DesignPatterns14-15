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

#include "Sharp.h"
#include <iostream>

using namespace std;

Sharp::Sharp(Fruit * fruit) : Decorator(fruit)
{

}

char Sharp::getDecoration() const
{
    return '#';
}


Sharp::~Sharp()
{
    //dtor
}
