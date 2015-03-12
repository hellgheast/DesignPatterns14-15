#include <stdlib.h>
#include <conio.h>

#include "CircleV1.h"
#include "CircleV2.h"
#include "RectangleV1.h"
#include "RectangleV2.h"
#include "HexagonV1.h"
#include "HexagonV2.h"

using namespace std;

//Affiche le menu API, gère l'erreur de saisi et renvoie la saisi.
char menuAPI(bool answerOk)
{
    char answer;
    cout<<"--Cette interface permet d'instancier des formes avec deux APIs.--"<<endl<<endl;
    cout<<"Choisissez une API:"<<endl<<endl;
    cout<<"[1] API version 1"<<endl;
    cout<<"[2] API version 2"<<endl;
    if(!answerOk)
        cout<<"----ERREUR DE SAISI----"<<endl;
    else
        cout<<endl;
    cout<<"Votre choix: ";
    cin>>answer;
    cout<<"--Cette interface permet d'instancier des formes avec deux APIs.--"<<endl<<endl;
    cout<<"Choisissez une API:"<<endl<<endl;
    cout<<"[1] API version 1"<<endl;
    cout<<"[2] API version 2"<<endl<<endl;
    cout<<"Votre choix: "<<answer<<endl<<endl;
    return answer;
}

//Affiche le menu de dessin des formes, gère l'erreur de saisi et renvoie la saisi.
char menuFormes(bool answerOk)
{
    char answer;
    cout<<"--Cette interface permet d'instancier des formes avec deux APIs.--"<<endl<<endl;
    cout<<"Choisissez une forme:"<<endl<<endl;
    cout<<"[1] Dessine un rectangle."<<endl;
    cout<<"[2] Dessine un hexagon."<<endl;
    cout<<"[3] Dessine un cercle."<<endl;
    cout<<"[4] Changer d'API."<<endl;
    cout<<"[5] Quitter."<<endl;
    if(!answerOk)
        cout<<"----ERREUR DE SAISI----"<<endl;
    else
        cout<<endl;
    cout<<"Votre choix: ";
    cin>>answer;
    system("cls");
    cout<<"--Cette interface permet d'instancier des formes avec deux APIs.--"<<endl<<endl;
    cout<<"Choisissez une forme:"<<endl<<endl;
    cout<<"[1] Dessine un rectangle."<<endl;
    cout<<"[2] Dessine un hexagon."<<endl;
    cout<<"[3] Dessine un cercle."<<endl;
    cout<<"[4] Changer d'API."<<endl;
    cout<<"[5] Quitter."<<endl<<endl;
    cout<<"Votre choix: "<<answer<<endl<<endl;
    return answer;
}

//Créer une interface pour l'utilisateur.
void interface()
{
    char answer='4';
    bool isAPI1,answerOk=true,stop;

    do
    {
        if(answer=='4')
            do
            {
                answer=menuAPI(answerOk);
                answerOk=true;
                switch(answer)
                {
                case '1':
                    isAPI1=true;
                    break;
                case '2':
                    isAPI1=false;
                    break;
                default:
                    answerOk=false;
                }
                system("cls");
            }
            while(!answerOk);
        do
        {
            answer=menuFormes(answerOk);
            answerOk=true;
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
                break;
            case '4':
                system("cls");
                break;
            case '5':
                stop=true;
                break;
            default:
                answerOk=false;
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
