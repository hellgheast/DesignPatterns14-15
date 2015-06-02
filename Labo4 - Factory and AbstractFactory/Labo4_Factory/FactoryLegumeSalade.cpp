#include "FactoryLegumeSalade.h"

FactoryLegumeSalade::FactoryLegumeSalade()
{
    //ctor
}

FactoryLegumeSalade::~FactoryLegumeSalade()
{
    //dtor
}

Legume* FactoryLegumeSalade::createLegume()
{
    return new LegumeSalade();
}
