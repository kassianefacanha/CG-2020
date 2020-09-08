#include "mesa.h"

Mesa::Mesa()
{
    model=new Model3DS("../3ds/Table.3ds");
}

void Mesa::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glTranslated(-2,0.5,0.7);
        glRotatef(-90,1,0,0);
        glScalef(0.0013,0.0009,0.0013);

        model->draw();
    glPopMatrix();
}
