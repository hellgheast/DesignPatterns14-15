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
#include "Banana.h"
#include <iostream>

using namespace std;

void Banana::showFruit() const
{
    cout << endl << "Banana";
    showPip();
}
