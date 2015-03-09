#include <stdlib.h>
#include <conio.h>

#include "CircleV1.h"
#include "CircleV2.h"
#include "RectangleV1.h"
#include "RectangleV2.h"
#include "HexagonV1.h"
#include "HexagonV2.h"

using namespace std;

//Renvoie le caractère saisi par l'utilisateur. Ne gère pas les exceptions de saisi.
char keyboardInput()
{
    char c;
    cin>>c;
    return c;
}

//Créer une interface pour l'utilisateur.
void interface()
{
    char answer='4';
    bool isAPI1,answerOk,stop,error=false;
    do
    {
        if(answer=='4')
            do
            {
                cout<<"--Cette interface permet d'instancier des formes avec deux APIs.--"<<endl<<endl;
                cout<<"Choisissez une API:"<<endl<<endl;
                cout<<"[1] API version 1"<<endl;
                cout<<"[2] API version 2"<<endl;
                if(error)
                {
                    cout<<"----ERREUR DE SAISI----"<<endl;
                    error=false;
                }
                else
                    cout<<endl;
                cout<<"Votre choix: ";
                answer=keyboardInput();
                answerOk=false;
                switch(answer)
                {
                case '1':
                    isAPI1=true;
                    answerOk=true;
                    break;
                case '2':
                    isAPI1=false;
                    answerOk=true;
                    break;
                default:
                    error=true;
                }
                system("cls");
            }
            while(!answerOk);
        do
        {
            cout<<"--Cette interface permet d'instancier des formes avec deux APIs.--"<<endl<<endl;
            cout<<"Choisissez une forme:"<<endl<<endl;
            cout<<"[1] Dessine un rectangle."<<endl;
            cout<<"[2] Dessine un hexagon."<<endl;
            cout<<"[3] Dessine un cercle."<<endl;
            cout<<"[4] Changer d'API."<<endl;
            cout<<"[5] Quitter."<<endl;
            if(error)
            {
                cout<<"----ERREUR DE SAISI----"<<endl;
                error=false;
            }
            else
                cout<<endl;
            cout<<"Votre choix: ";
            answer=keyboardInput();
            cout<<endl;
            answerOk=false;
            switch(answer)
            {
            case '1':
                if(isAPI1)
                {
                    RectangleV1 shape=RectangleV1();
                    shape.draw();
                }
                else
                {
                    RectangleV2 shape=RectangleV2();
                    shape.draw();
                }
                answerOk=true;
                break;
            case '2':
                if (isAPI1)
                {
                    HexagonV1 shape=HexagonV1();
                    shape.draw();
                }
                else
                {
                    HexagonV2 shape=HexagonV2();
                    shape.draw();
                }
                answerOk=true;
                break;
            case '3':
                if (isAPI1)
                {
                    CircleV1 shape=CircleV1();
                    shape.draw();
                }
                else
                {
                    CircleV2 shape=CircleV2();
                    shape.draw();
                }
                answerOk=true;
                break;
            case '4':
                answerOk=true;
                system("cls");
                break;
            case '5':
                stop=true;
                answerOk=true;
                break;
            default:
                error=true;
                system("cls");
            }
            if(answer=='1'||answer=='2'||answer=='3')
            {
                cout<<endl<<"Presser une touche pour continuer...";
                getch();
                system("cls");
            }
        }
        while(!answerOk);

    }
    while (!stop);
}

int main()
{
    interface();
    return 0;
}
