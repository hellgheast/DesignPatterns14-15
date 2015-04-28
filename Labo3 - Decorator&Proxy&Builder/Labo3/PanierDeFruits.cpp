#include "PanierDeFruits.h"

PanierDeFruits::PanierDeFruits(list<Fruit> _Fruits)
{
    this.Fruits = _Fruits;
}

PanierDeFruits::~PanierDeFruits()
{
    //dtor
}

void PanierDeFruits::AfficherFruits()
{
    cout<<"Panier[";
    for(std::list<Fruit>::iterator it = Fruits.begin(); it != Fruits.end(); it++)
    {
        if(*it != Fruits.begin())
        {
            cout<<",";
        }
        *it.AfficherFruit();
    }
    cout<<"]\n";
}
