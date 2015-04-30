#include "Paid.h"
#include <iostream>
#include "Order.h"
#include "Sent.h"

using namespace std;


Paid::Paid() : OrderState()
{
    //ctor
}

Paid::~Paid()
{
    //dtor
}

void Paid::processOrder(Order* order)
{
    //prints a message saying the order has been paid
    std::cout << "-> The order has been payed."<< std::endl;
    while(!confirmation("Would you like to send the order?")){
        cout << "\/!\\ The order hasn't been sent. \/!\\" << endl;
    }
    //changes the order state to sent
    order->changeState(new Sent());
}
