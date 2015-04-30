#include "Sent.h"
#include <iostream>

using namespace std;



Sent::Sent() : OrderState()
{
    //ctor
}

Sent::~Sent()
{
    //dtor
}

void Sent::processOrder(Order* order)
{
    //prints a message saying the order has been sent
    std::cout << "-> The order has been sent." << std::endl;
}
