#include "inverso.hpp"

Inverso::Inverso(string entrada){
    this->texto=entrada;
}

string Inverso::invertir(){
    string *copiaTextoEntrada=new string(texto);
    int tamanio=copiaTextoEntrada->size();
    string *cifradoDescifrado=new string();

    for(int i = tamanio-1; i>= 0; i--){
        cifradoDescifrado+=copiaTextoEntrada->at(i);
    }
    return *cifradoDescifrado;
}

string Inverso::cifrar(){
    return invertir();
}

string Inverso::decifrar(){
    return invertir();
}
