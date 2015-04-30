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
#include "Fruit.h"
#include <iostream>

using namespace std;

void Fruit::showPip() const{

    if(this->hasPip()){
        cout << " - contains seeds";
    }
    else {
        cout << " - doesn't contain seeds";
    }
}
