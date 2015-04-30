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
#include "Peach.h"
#include <iostream>

using namespace std;

void Peach::showFruit() const
{
    cout << endl << "Peach";
    showPip();
}
