#include "Huile.h"
#include "HuileCuisson.h"
#include "HuileVapeur.h"
#include "HuilePotage.h"
#include "HuileSalade.h"

Huile::Huile()
{
    //ctor
}

Huile::~Huile()
{
    //dtor
}

Huile* Huile::createHuile(int choice)
{
    if (choice == 1)
        return new HuileCuisson();
    else if (choice == 2)
        return new HuilePotage();
    else if (choice == 3)
        return new HuileSalade();
    else
        return new HuileVapeur();
}
