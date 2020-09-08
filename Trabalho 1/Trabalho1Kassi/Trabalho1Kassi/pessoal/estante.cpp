#include "estante.h"

Estante::Estante()
{

}

void Estante::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        if (selecionado) {
              GUI::setColor(0.8,0.8,0.8);
           } else {
               GUI::setColor(1,0,0);
           }

        //face frente 1
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5, 1.8 , -2);
            glVertex3f (-2.5 , 1.7 , -2);
            glVertex3f (0, 1.7, -2);
            glVertex3f (0, 1.8 , -2);
        glEnd ( ) ;
        //face frente 2
        glBegin (GL_POLYGON ) ;
            glVertex3f (-0.1, 1.7 , -2);
            glVertex3f (-0.1, 0, -2);
            glVertex3f (0, 0 , -2);
            glVertex3f (0, 1.7 , -2);
        glEnd ( ) ;
        //face frente 3
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.4, 0, -2);
            glVertex3f (-2.4, 1.7 , -2);
            glVertex3f (-2.5, 1.7 , -2);
            glVertex3f (-2.5, 0 , -2);
        glEnd ( ) ;
        //face superior 1
        glBegin(GL_POLYGON);
            glVertex3f(-2.5 , 0.3,-2.5);
            glVertex3f(-2.5, 0.3,-2);
            glVertex3f(0, 0.3,-2);
            glVertex3f(0, 0.3,-2.5);
        glEnd();
        //face superior 2
        glBegin(GL_POLYGON);
            glVertex3f(-2.5, 0.2,-2);
            glVertex3f(-2.5 , 0.2,-2.5);
            glVertex3f(0, 0.2,-2.5);
            glVertex3f(0, 0.2,-2);
        glEnd();
        //face frente 4
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5, 0.3 , -2);
            glVertex3f (-2.5 , 0.2 , -2);
            glVertex3f (0, 0.2, -2);
            glVertex3f (0, 0.3 , -2);
        glEnd ( ) ;
        //face tras 4
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5 , 0.2 , -2.5);
            glVertex3f (-2.5, 0.3 , -2.5);
            glVertex3f (0, 0.3 , -2.5);
            glVertex3f (0, 0.2, -2.5);
        glEnd ( ) ;
        //face superior 3
        glBegin(GL_POLYGON);
            glVertex3f(-2.5 , 0.7,-2.5);
            glVertex3f(-2.5, 0.7,-2);
            glVertex3f(0, 0.7,-2);
            glVertex3f(0, 0.7,-2.5);
        glEnd();
        //face superior 4
        glBegin(GL_POLYGON);
            glVertex3f(-2.5, 0.6,-2);
            glVertex3f(-2.5 , 0.6,-2.5);
            glVertex3f(0, 0.6,-2.5);
            glVertex3f(0, 0.6,-2);
        glEnd();
        //face frente 5
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5, 0.7 , -2);
            glVertex3f (-2.5 , 0.6 , -2);
            glVertex3f (0, 0.6, -2);
            glVertex3f (0, 0.7 , -2);
        glEnd ( ) ;
        //face tras 5
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5 , 0.6 , -2.5);
            glVertex3f (-2.5, 0.7 , -2.5);
            glVertex3f (0, 0.7 , -2.5);
            glVertex3f (0, 0.6, -2.5);
        glEnd ( ) ;
        //face superior 5
        glBegin(GL_POLYGON);
            glVertex3f(-2.5 , 1.2,-2.5);
            glVertex3f(-2.5, 1.2,-2);
            glVertex3f(0, 1.2,-2);
            glVertex3f(0, 1.2,-2.5);
        glEnd();
        //face superior 6
        glBegin(GL_POLYGON);
            glVertex3f(-2.5, 1.1,-2);
            glVertex3f(-2.5 , 1.1,-2.5);
            glVertex3f(0, 1.1,-2.5);
            glVertex3f(0, 1.1,-2);
        glEnd();
        //face frente 6
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5, 1.2 , -2);
            glVertex3f (-2.5 , 1.1 , -2);
            glVertex3f (0, 1.1, -2);
            glVertex3f (0, 1.2 , -2);
        glEnd ( ) ;
        //face tras 6
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5 , 1.1 , -2.5);
            glVertex3f (-2.5, 1.2 , -2.5);
            glVertex3f (0, 1.2 , -2.5);
            glVertex3f (0, 1.1, -2.5);
        glEnd ( ) ;
        //face superior 7
        glBegin(GL_POLYGON);
            glVertex3f(-2.5 , 1.8,-2.5);
            glVertex3f(-2.5, 1.8,-2);
            glVertex3f(0, 1.8,-2);
            glVertex3f(0, 1.8,-2.5);
        glEnd();
        //face superior 8
        glBegin(GL_POLYGON);
            glVertex3f(-2.5, 1.7,-2);
            glVertex3f(-2.5 , 1.7,-2.5);
            glVertex3f(0, 1.7,-2.5);
            glVertex3f(0, 1.7,-2);
        glEnd();
        //face inferior 1
        glBegin(GL_POLYGON);
            glVertex3f(-2.5, 0,-2);
            glVertex3f(-2.5 , 0.1,-2.5);
            glVertex3f(-2.4, 0.1,-2.5);
            glVertex3f(-2.4, 0,-2);
        glEnd();
        //face inferior 2
        glBegin(GL_POLYGON);
            glVertex3f(0, 0,-2);
            glVertex3f(-0.1, 0,-2);
            glVertex3f(-0.1, 0.1,-2.5);
            glVertex3f(0 , 0.1,-2.5);
        glEnd();
        //face lateral 1
        glBegin(GL_POLYGON);
            glVertex3f(0, 0,-2);
            glVertex3f(0 , 0,-2.5);
            glVertex3f(0, 1.8,-2.5);
            glVertex3f(0, 1.8,-2);
        glEnd();
        //face lateral 2
        glBegin(GL_POLYGON);
            glVertex3f(-0.1 , 0,-2.5);
            glVertex3f(-0.1, 0,-2);
            glVertex3f(-0.1, 1.8,-2);
            glVertex3f(-0.1, 1.8,-2.5);
        glEnd();
        //face lateral 3
        glBegin(GL_POLYGON);
            glVertex3f(-2.5 , 0,-2.5);
            glVertex3f(-2.5, 0,-2);
            glVertex3f(-2.5, 1.8,-2);
            glVertex3f(-2.5, 1.8,-2.5);

        glEnd();
        //face lateral 4
        glBegin(GL_POLYGON);
            glVertex3f(-2.4, 0,-2);
            glVertex3f(-2.4 , 0,-2.5);
            glVertex3f(-2.4, 1.8,-2.5);
            glVertex3f(-2.4, 1.8,-2);
        glEnd();
        //face tras 1
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.5 , 1.7 , -2.5);
            glVertex3f (-2.5, 1.8 , -2.5);
            glVertex3f (0, 1.8 , -2.5);
            glVertex3f (0, 1.7, -2.5);
        glEnd ( ) ;
        //face tras 2
        glBegin (GL_POLYGON ) ;
            glVertex3f (-0.1, 0, -2.5);
            glVertex3f (-0.1, 1.7 , -2.5);
            glVertex3f (0, 1.7 , -2.5);
            glVertex3f (0, 0 , -2.5);
        glEnd ( ) ;
        //face tras 3
        glBegin (GL_POLYGON ) ;
            glVertex3f (-2.4, 1.7 , -2.5);
            glVertex3f (-2.4, 0, -2.5);
            glVertex3f (-2.5, 0 , -2.5);
            glVertex3f (-2.5, 1.7 , -2.5);

        glEnd ( ) ;


    glPopMatrix();
}
