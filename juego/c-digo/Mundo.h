#ifndef MUNDO_H
#define MUNDO_H

#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;


class Mundo{
private:
    typedef unsigned char byte;
    int width;
    int height;
    byte *celdas;

public:
    Mundo(int ,int );
    ~Mundo();
    int getWidth()const;
    int getHeight()const;
    byte at(int,int)const;
    void set(int,int,byte) ;
    void swap(Mundo *);
};

#endif // MUNDO_H
