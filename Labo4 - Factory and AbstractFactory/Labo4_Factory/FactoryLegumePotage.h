#ifndef FACTORYLEGUMEPOTAGE_H
#define FACTORYLEGUMEPOTAGE_H
#include "FactoryLegume.h"
#include "LegumePotage.h"

class FactoryLegumePotage: public FactoryLegume
{
public:
    FactoryLegumePotage();
    virtual ~FactoryLegumePotage();

    static Legume* createLegume();
protected:
private:
};

#endif // FACTORYLEGUMEPOTAGE_H
