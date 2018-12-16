#ifndef REGLAS_H
#define REGLAS_H

#include <vector>
#include "Mundo.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Reglas{
private:
    int width;
    int heigth;
    Mundo *mundo;
    Mundo *mundoT;
    vector<int> stay;
    vector<int> birth;

    int neighbours(int,int);
    bool inStay(int);
    bool inBirth(int);

public:
    Reglas(Mundo*);
    ~Reglas();
    bool hasLivingCells();
    void swapWorlds();
    void setRuleB(vector<int>&);
    void setRuleS(vector<int>&);
    void applyRules();
};


#endif // REGLAS_H
