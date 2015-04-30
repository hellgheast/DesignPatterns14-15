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
#ifndef ORDERSTATE_H
#define ORDERSTATE_H
#include <string>
using namespace std;
class Order;

class OrderState
{
    public:
        OrderState();
        virtual ~OrderState();
        virtual void processOrder(Order* order) = 0;
    protected:
        bool confirmation(string question) const;
};

#endif // ORDERSTATE_H
