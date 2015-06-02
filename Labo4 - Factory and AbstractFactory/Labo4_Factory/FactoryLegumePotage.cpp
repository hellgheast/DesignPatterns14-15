#include "FactoryLegumePotage.h"

FactoryLegumePotage::FactoryLegumePotage()
{
    //ctor
}

FactoryLegumePotage::~FactoryLegumePotage()
{
    //dtor
}

Legume* FactoryLegumePotage::createLegume()
{
    return new LegumePotage();
}
