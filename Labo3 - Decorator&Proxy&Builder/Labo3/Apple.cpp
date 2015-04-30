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
#include "Apple.h"
#include <iostream>

using namespace std;

void Apple::showFruit() const
{
    cout << endl << "Apple";
    showPip();
}
