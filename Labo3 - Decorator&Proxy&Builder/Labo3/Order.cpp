/*
	Design Patterns
	Labo3 : Panier de fruits avec State, Composite, Decorator
	Authors :
        - Karim Luy
        - Nicolas Gonin
        - Mathieu Bandelier
	Equipe1
************************************************************************
*/
#include <iostream>

#include "Order.h"
#include "Waiting.h"

#include "Fruit.h"
#include "Apple.h"
#include "Banana.h"
#include "Strawberry.h"

#include "Decorator.h"
#include "Star.h"
#include "Equal.h"
#include "Sharp.h"

using namespace std;
Order::Order()
{
    this->orderState = new Waiting();
    this->createBasket();
}

Order::~Order()
{
    delete this->orderState;
    delete this->basket;
}

void Order::changeState(OrderState* newOrderState)
{
    delete this->orderState;
    this->orderState = newOrderState;
}

void Order::nextState()
{
    this->orderState->processOrder(this);
}

void Order::createBasket(){
    this->basket = new Basket();
    addInto(basket);
    basket->showFruit();
}

void Order::addDecoration(Fruit ** fruit)
{
    char choix = ' ';
    do {
        cout << "Quelle decoration voulez-vous ajouter : " << endl
             << " a : Etoile" << endl
             << " b : diese" << endl
             << " c : signe egal" << endl
             << " q : Rien d'autre" << endl
             << "Votre choix : ";
        string input;
        getline(cin, input);
        choix = input[0];
        switch (choix)
        {
            case 'a':
            case 'A': *fruit = new Star(*fruit);
                break;
            case 'b':
            case 'B': *fruit = new Sharp(*fruit);
                break;
            case 'c':
            case 'C': *fruit = new Equal(*fruit);
                break;

            case 'q':
            case 'Q':

                break;
            default:
                cout << "Erreur de saisie !";
        }
        cout << endl << endl;
    } while (choix != 'q' && choix != 'Q');
}

void Order::addInto(Basket * basket)
{
    char choix = ' ';
    do {
        cout << "What do you want to add? : " << endl
             << " a : Strawberry" << endl
             << " b : Apple" << endl
             << " c : Banana" << endl
             << " d : Basket" << endl
             << " q : Nothing else" << endl
             << "Your choice : ";
        string input;
        getline(cin, input);
        choix = input[0];
        Fruit * nouveau = 0;
        switch (choix)
        {
            case 'a':
            case 'A':
                nouveau = new Strawberry();
                break;
            case 'b':
            case 'B':
                nouveau = new Apple();
                break;
            case 'c':
            case 'C':
                nouveau = new Banana();
                break;
            case 'd':
            case 'D':
            {
                Basket * sub = new Basket();
                nouveau = sub;
                addInto(sub);
                break;
            }
            case 'q':
            case 'Q':

                break;
            default:
                cout << "Wrong entry!";
        }
        cout << endl << endl;

        if(nouveau)
        {
            addDecoration(&nouveau);
            basket->add(nouveau);
        }
    } while (choix != 'q' && choix != 'Q');
}
