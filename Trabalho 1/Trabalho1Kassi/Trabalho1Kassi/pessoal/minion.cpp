#include "minion.h"

Minion::Minion()
{
    model=new Model3DS("../3ds/Minion.3ds");
}

void Minion::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glTranslated(-1,0.7,1);
        glRotatef(-90,1,0,0);
        glScalef(0.025,0.021,0.025);


        model->draw();
    glPopMatrix();
}
