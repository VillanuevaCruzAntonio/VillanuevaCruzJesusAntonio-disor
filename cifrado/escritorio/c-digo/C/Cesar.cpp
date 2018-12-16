Inverso#include "cesar.hpp"

Cesar::Cesar(string textEntrada,int posicion){
    this->texto=textEntrada;
    this->indicePos=posicion;
}

string Cesar::cifrar(){
    string textoCifrado;
    int indice;
    int movimiento;
    size_t dimension;
    for(indice=0;indice<texto.length();indice++){
        if(texto.at(indice)>96 && texto.at(indice)<123)
            texto.at(indice) -= 32;

        if(texto.at(indice)<64 && texto.at(indice)>91)
            textoCifrado+=texto.at(indice);

        else{
            dimension = letras.find(texto.at(indice));
            if(((int)dimension+indicePos) > letras.length())
            movimiento = ((int)dimension+indicePos)-letras.length();
            else
            movimiento = (int)dimension+indicePos;
            textoCifrado.append(letras,movimiento,1);
        }
    }
    return textoCifrado;
}

string Cesar::decifrar(){
    string textoDesifrado;
    int indice;
    int movimiento;
    size_t dimension;
    for(indice=0;indice<texto.length();indice++){
        if(texto.at(indice)>96 && texto.at(indice)<123)
            texto.at(indice) -= 32;

        if(texto.at(indice)<64 && texto.at(indice)>91)
            textoDesifrado+=texto.at(indice);

        else{
            dimension = letras.find(texto.at(indice));
            if(((int)dimension-indicePos) < 0)
                movimiento = letras.length()+((int)dimension-indicePos);
            else
                movimiento = (int)dimension-indicePos;

            textoDesifrado.append(letras,movimiento,1);
        }
    }
    return textoDesifrado;
}
