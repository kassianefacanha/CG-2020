#ifndef PIANO_H
#define PIANO_H


#include <objeto.h>
class Piano : public Objeto
{
public:
    Model3DS* model;

public:
   Piano();
    void desenha();
};


#endif // PIANO_H
