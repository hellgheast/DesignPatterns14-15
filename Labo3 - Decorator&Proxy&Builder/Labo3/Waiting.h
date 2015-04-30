#ifndef WAITING_H
#define WAITING_H


#include "OrderState.h"


class Waiting : public OrderState
{
    public:
        Waiting();
        virtual ~Waiting();
        void processOrder(Order* order);
    protected:
    private:
};

#endif // WAITING_H
