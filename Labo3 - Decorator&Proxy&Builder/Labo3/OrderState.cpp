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
#include "OrderState.h"
#include "Order.h"
#include <iostream>
using namespace std;
OrderState::OrderState()
{

}

OrderState::~OrderState()
{
    //dtor
}

bool OrderState::confirmation(string question) const {
    char choix = ' ';
    bool confirmation = false;
    bool reponseJuste = false;
    do {
        cout << endl<<endl<<question << "(y/n)" << endl
             << "Your choice: ";
        string input;
        getline(cin, input);
        choix = input[0];
        switch (choix)
        {
            case 'y':
            case 'Y':   confirmation = true;
                        reponseJuste = true;
                break;
            case 'n':
            case 'N':   confirmation = false;
                        reponseJuste = true;
                break;
            default:
                cout << "Wrong entry!";
        }
        cout << endl << endl;
    } while (!reponseJuste);
    return confirmation;
}
