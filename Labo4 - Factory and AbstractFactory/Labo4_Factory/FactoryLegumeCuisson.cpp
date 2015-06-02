#include "FactoryLegumeCuisson.h"

FactoryLegumeCuisson::FactoryLegumeCuisson()
{
    //ctor
}

FactoryLegumeCuisson::~FactoryLegumeCuisson()
{
    //dtor
}

Legume* FactoryLegumeCuisson::createLegume()
{
    return new LegumeCuisson();
}
