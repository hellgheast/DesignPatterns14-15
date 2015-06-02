#ifndef FACTORYLEGUME_H
#define FACTORYLEGUME_H
#include "Legume.h"

class FactoryLegume
{
public:
    FactoryLegume();
    virtual ~FactoryLegume();

    static Legume* createLegume(int choice);
protected:
private:
};

#endif // FACTORYLEGUME_H
