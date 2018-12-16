
#include "Mundo.h"


Mundo::Mundo(int x,int y){
    width=x;
    height=y;
    int s=width*height*sizeof(byte);
    celdas=new unsigned char[s];
    memset(celdas,0,s);//inicializacion de celdas a 0
}


Mundo::~Mundo(){
    delete [] celdas;
}



int Mundo::getWidth()const{
    return width;
}
int Mundo::getHeight()const{
    return height;
}

unsigned char Mundo::at(int x,int y) const{
    return celdas[x+y*width];
}

void Mundo::set(int x,int y,byte c){
    celdas[x+y*width]=c;
}

void Mundo::swap(Mundo *m){
    memcpy(celdas,m->celdas,width*height*sizeof(byte));
}

