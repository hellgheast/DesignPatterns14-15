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
#include "Strawberry.h"
#include <iostream>

using namespace std;

void Strawberry::showFruit() const
{
    cout << endl << "Strawberry";
    showPip();
}
