#ifndef CELULAS_H
#define CELULAS_H

#include <vector>
#include "Mundo.h"
#include "Reglas.h"
using namespace std;

class Celulas{
private:
    Reglas *reglas;
    Mundo *mundo;
    int generacion;

    void display();
    void generation();
public:
    Celulas(int,int);
    ~Celulas();
    void start(int);

};

#endif // CELULAS_H
