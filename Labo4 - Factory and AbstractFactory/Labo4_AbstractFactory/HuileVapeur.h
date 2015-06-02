#ifndef HUILEVAPEUR_H
#define HUILEVAPEUR_H
#include "Huile.h"

class HuileVapeur: public Huile
{
public:
    HuileVapeur();
    virtual ~HuileVapeur();

    void print();
protected:
private:
};

#endif // HUILEVAPEUR_H
