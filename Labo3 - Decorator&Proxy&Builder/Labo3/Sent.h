#ifndef SENT_H
#define SENT_H


#include "OrderState.h"

class Sent : public OrderState
{
    public:
        Sent();
        virtual ~Sent();
        void processOrder(Order* order);
    protected:
    private:
};


#endif // SENT_H
