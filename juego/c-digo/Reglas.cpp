
#include "Reglas.h"


Reglas::Reglas(Mundo *m){
    mundo=m;
    width=m->getWidth();
    heigth=m->getHeight();
    mundoT=new Mundo(width,heigth);
}

Reglas::~Reglas(){
    if(mundoT) delete mundoT;
}

bool Reglas::hasLivingCells(){
    for(int x=0;x<heigth;x++){
        for(int y=0;y<width;y++){
            if(mundo->at(x,y)) return true;
        }
    }
    cout << "Todas las celulas estan muertas"<<endl;
    return false;
}


void Reglas::swapWorlds(){
    mundo->swap(mundoT);
}

void Reglas::setRuleB(vector<int>& bi){
    birth=bi;
}

void Reglas::setRuleS(vector<int>& st){
    stay=st;
}


void Reglas::applyRules(){
    int n;
    for(int y=0;y<heigth;y++){
        for(int x=0;x<width;x++){
            n=neighbours(x,y);
            if(mundo->at(x,y)){
                mundoT->set(x,y,inStay(n)? 1: 0);
            }else{
                mundoT->set(x,y,inBirth(n) ? 1:0);
            }
        }
    }
}



int Reglas::neighbours(int xx,int yy){
    int n=0;
    int nx;
    int ny;

    for(int y=-1;y<2;y++){
        for(int x=-1;x<2;x++){
            if(!x && !y){
                continue;
            }
            nx=(width+xx+x)%width;
            ny=(heigth+yy+y)%heigth;
            n+=mundo->at(nx,ny)>0 ? 1:0;
        }
    }
    return n;
}

bool Reglas::inStay(int n){
    return (stay.end() != find(stay.begin(),stay.end(),n));
}

bool Reglas::inBirth(int n){
    return (birth.end() != find(birth.begin(),birth.end(),n));
}


