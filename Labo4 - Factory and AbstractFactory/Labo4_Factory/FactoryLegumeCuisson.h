#ifndef FACTORYLEGUMECUISSON_H
#define FACTORYLEGUMECUISSON_H
#include "FactoryLegume.h"
#include "LegumeCuisson.h"

class FactoryLegumeCuisson: public FactoryLegume
{
public:
    FactoryLegumeCuisson();
    virtual ~FactoryLegumeCuisson();

    static Legume* createLegume();
protected:
private:
};

#endif // FACTORYLEGUMECUISSON_H
