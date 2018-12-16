
#include "Celulas.h"

Celulas::Celulas(int w,int h):reglas(0){
    mundo=new Mundo(w,h);
}
Celulas::~Celulas(){
    if(reglas){
        delete reglas;
    }
    delete mundo;
}
void Celulas::start(int r){
    reglas=new Reglas(mundo);
    generacion=1;
    vector<int> t;

    switch(r){
    case 1://conway
        t.push_back(2);
        t.push_back(3);
        reglas->setRuleS(t);
        t.clear();
        t.push_back(3);
        reglas->setRuleB(t);
        break;

    case 2://amoeba
        t.push_back(1);
        t.push_back(3);
        t.push_back(5);
        t.push_back(8);
        reglas->setRuleS(t);
        t.clear();
        t.push_back(3);
        t.push_back(5);
        t.push_back(7);
        reglas->setRuleB(t);
        break;

    case 3://life34
        t.push_back(3);
        t.push_back(4);
        reglas->setRuleS(t);
        reglas->setRuleB(t);
        break;
    case 4://maze
        t.push_back(1);
        t.push_back(2);
        t.push_back(3);
        t.push_back(4);
        t.push_back(5);
        reglas->setRuleS(t);
        t.clear();
        t.push_back(3);
        reglas->setRuleB(t);
        break;
    }

    /*glider*/
    mundo->set(6,1,1);
    mundo->set(7,2,1);
    mundo->set(5,3,1);
    mundo->set(6,3,1);
    mundo->set(7,3,1);

    /*blinker*/
    mundo->set(1,3,1);
    mundo->set(2,3,1);
    mundo->set(3,3,1);
    generation();
}

void Celulas::display(){
    system("clear");
    int wid=mundo->getWidth();
    int hei=mundo->getHeight();
    cout << "+" <<string(wid,'-') << "+\n";
    for(int y=0;y<hei;y++){
        cout << "|";
        for(int x=0;x<wid;x++){
            if(mundo->at(x,y)){
                cout << "#";
            }else{
                cout << ".";
            }
        }
        cout << "|\n";
    }
    cout << "+" << string(wid,'-')<< "+\n";
    cout <<"Generacion:"<<generacion<<"[Enter] para salir";
    cin.get();
}

void Celulas::generation(){
    do{
        display();
        reglas->applyRules();
        reglas->swapWorlds();
        generacion++;
    }while(reglas->hasLivingCells());
}
