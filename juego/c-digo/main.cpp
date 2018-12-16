#include <iostream>

#include "Celulas.h"

using namespace std;

int main()
{
    Celulas c(20,12);
    cout << "Automata Celular!" << endl;
    cout << "Cual quiere correr?"<<endl;
    cout << "1.-Forma 1\n2.- Forma 2\n3.- Forma 3\n4.- Forma 4"<<endl;
    int opcion;
    do{
        cin>>opcion;
    }while(opcion < 1 || opcion > 4);
    cin.ignore();
    c.start(opcion);
    
    return system("pause");
}
