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
#ifndef ORDER_H
#define ORDER_H
#include "OrderState.h"
#include "Basket.h"

using namespace std;

class Order
{
    public:
        Order();
        virtual ~Order();
        void changeState(OrderState* newOrderState);
        void nextState();
    protected:
    private:
        Basket* basket;
        OrderState* orderState;
        void createBasket();
        void addDecoration(Fruit **);
        void addInto(Basket *);
};

#endif // ORDER_H
