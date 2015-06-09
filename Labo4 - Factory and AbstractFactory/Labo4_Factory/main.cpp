/**
  * Design Pattern
  * Labo 4 Partie 1
  * Nicolas Gonin, Karim Luy et Matthieu Bandelier
  *
**/
#include <iostream>
#include <windows.h>
#include "Legume.h"
#include "FactoryLegume.h"

using namespace std;

int main()
{
    Legume* legume = NULL;
    int choice;
    char answer;
    bool stop, answer_ok;

    do
    {
        while (true)
        {
            cout << "Quel type de menu voulez-vous cuisiner?"<<endl;
            cout << "(1) Cuisson"<<endl;
            cout << "(2) Potage"<<endl;
            cout << "(3) Salade"<<endl;
            cout << "(4) Vapeur"<<endl;
            cout << endl;
            cout<<"Votre choix: ";
            cin>>choice;
            cin.clear();
            cin.ignore(1000,'\n');
            if(choice<5)
            {
                if(legume != NULL)
                    delete legume;
                legume=FactoryLegume::createLegume(choice);
                break;
            }
            else
                cout<<"Erreur de saisi"<<endl;
        }
        cout<<endl;
        cout<<"Votre menu contient:"<<endl;
        legume->print();
        do
        {
            cout<<endl<<"Voulez-vous continuer?[y/n]:";
            cin>>answer;
            cin.clear();
            cin.ignore(1000,'\n');
            answer_ok=false;
            switch(answer)
            {
            case 'y':
                answer_ok=true;
                break;
            case 'n':
                answer_ok=true;
                stop=true;
                break;
            default:
                cout<<"Erreur de saisi"<<endl;
            }
        }
        while(!answer_ok);
        system("CLS");
    }
    while (!stop);

    delete legume;
}
