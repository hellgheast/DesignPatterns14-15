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

#include "Star.h"
#include <iostream>

using namespace std;

Star::Star(Fruit * fruit) : Decorator(fruit)
{

}

char Star::getDecoration() const
{
   return '*';
}

Star::~Star()
{
    //dtor
}
