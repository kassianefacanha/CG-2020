#ifndef MINION_H
#define MINION_H

#include <objeto.h>
class Minion : public Objeto
{
public:
    Model3DS* model;

public:
    Minion();
    void desenha();
};


#endif // MINION_H
