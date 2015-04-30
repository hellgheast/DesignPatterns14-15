#include "Waiting.h"
#include "Paid.h"
#include "Order.h"
#include <iostream>

using namespace std;

Waiting::Waiting() : OrderState()
{
}

Waiting::~Waiting()
{
    //dtor
}

void Waiting::processOrder(Order* order)
{
    cout << endl << endl << "-> The order is ready and awaiting payment." << endl;
    while(!confirmation("Would you like to pay the order?")){
        cout << "\\The order is still awaiting payment!\\" << endl;
    }
    //changes the order state to paid
    order->changeState(new Paid());
}
