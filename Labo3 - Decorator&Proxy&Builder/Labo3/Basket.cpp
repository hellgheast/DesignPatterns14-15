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
#include "Basket.h"
#include <iostream>

using namespace std;

Basket::~Basket()
{
     // while list contains something
    while (!subComposants.empty()) {
        // get the last element
        Fruit * last = subComposants.back();
        // remove it
        subComposants.pop_back();
        delete last;
    }
}
bool Basket::hasPip() const
{
    bool pip = false;
    for(std::vector<Fruit *>::const_iterator it = subComposants.begin(); it != subComposants.end(); ++it)
    {
        pip |= (*it)->hasPip();
    }
    return pip;
}
void Basket::showFruit() const
{
    cout << "Basket [";
    for(std::vector<Fruit *>::const_iterator it = subComposants.begin(); it != subComposants.end(); ++it)
    {
        (*it)->showFruit();
        if (it + 1 != subComposants.end()) {
            cout << ", " << endl;
        }
    }
    cout << "]";
}
