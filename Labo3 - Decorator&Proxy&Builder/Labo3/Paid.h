#ifndef PAID_H
#define PAID_H

#include "OrderState.h"

class Paid : public OrderState
{
    public:
        Paid();
        virtual ~Paid();
        void processOrder(Order* order);
    protected:
    private:
};

#endif // PAID_H
