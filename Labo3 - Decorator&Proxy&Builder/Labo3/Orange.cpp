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
#include "Orange.h"
#include <iostream>

using namespace std;

void Orange::showFruit() const
{
    cout << endl << "Orange";
    showPip();
}
