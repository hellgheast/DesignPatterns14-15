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
#ifndef BASKET_H
#define BASKET_H

#include "Fruit.h"
#include <vector>

class Basket : public Fruit
{
    public:
        Basket() {}
        virtual ~Basket();
        bool hasPip() const;
        void showFruit() const;
        void add(Fruit * fruit) {subComposants.push_back(fruit);};
    protected:
    private:
        std::vector<Fruit *> subComposants;
};

#endif // BASKET_H

