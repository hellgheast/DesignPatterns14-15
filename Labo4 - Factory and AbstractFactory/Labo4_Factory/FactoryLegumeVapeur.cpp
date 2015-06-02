#include "FactoryLegumeVapeur.h"

FactoryLegumeVapeur::FactoryLegumeVapeur()
{
    //ctor
}

FactoryLegumeVapeur::~FactoryLegumeVapeur()
{
    //dtor
}

Legume* FactoryLegumeVapeur::createLegume()
{
    return new LegumeVapeur();
}
