#include "piano.h"

Piano::Piano()
{
    model=new Model3DS("../3ds/Piano.3ds");
}

void Piano::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glTranslated(1.5,1.050,-1.5);
        glRotatef(-90,1,0,0);
        glScalef(0.020,0.016,0.020);

        model->draw();
    glPopMatrix();
}
