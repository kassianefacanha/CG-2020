#include "cama.h"

Cama::Cama()
{

}

void Cama::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        if (selecionado) {
              GUI::setColor(1,0,0);
           } else {
               GUI::setColor(0.8,0.8,0.8);
           }

     //face frente 1
     glBegin (GL_POLYGON ) ;
         glVertex3f (-2.5, 0.8 , 0.0);
         glVertex3f (-2.5 , 0.7 , 0.0);
         glVertex3f (0, 0.7, 0.0);
         glVertex3f (0, 0.8 , 0.0);
     glEnd ( ) ;
     //face frente 2
     glBegin (GL_POLYGON ) ;
         glVertex3f (-0.1, 0.7 , 0.0);
         glVertex3f (-0.1, 0, 0.0);
         glVertex3f (0, 0 , 0.0);
         glVertex3f (0, 0.7 , 0.0);
     glEnd ( ) ;
     //face frente 3
     glBegin (GL_POLYGON ) ;
         glVertex3f (-2.4, 0, 0.0);
         glVertex3f (-2.4, 0.7 , 0.0);
         glVertex3f (-2.5, 0.7 , 0.0);
         glVertex3f (-2.5, 0 , 0.0);
     glEnd ( ) ;
     //face superior 1
     glBegin(GL_POLYGON);
         glVertex3f(-2.5 , 0.8,-1);
         glVertex3f(-2.5, 0.8,0);
         glVertex3f(0, 0.8,0);
         glVertex3f(0, 0.8,-1);
     glEnd();
     //face superior 2
     glBegin(GL_POLYGON);
         glVertex3f(-2.5, 0.7,0);
         glVertex3f(-2.5 , 0.7,-1);
         glVertex3f(0, 0.7,-1);
         glVertex3f(0, 0.7,0);
     glEnd();
     //face inferior 1
     glBegin(GL_POLYGON);
         glVertex3f(-2.5, 0,0);
         glVertex3f(-2.5 , 0.1,-1);
         glVertex3f(-2.4, 0.1,-1);
         glVertex3f(-2.4, 0,0);
     glEnd();
     //face inferior 2
     glBegin(GL_POLYGON);
         glVertex3f(0, 0,0);
         glVertex3f(-0.1, 0,0);
         glVertex3f(-0.1, 0.1,-1);
         glVertex3f(0 , 0.1,-1);
     glEnd();
     //face lateral 1
     glBegin(GL_POLYGON);
         glVertex3f(0, 0,0);
         glVertex3f(0 , 0,-1);
         glVertex3f(0, 0.8,-1);
         glVertex3f(0, 0.8,0);
     glEnd();
     //face lateral 2
     glBegin(GL_POLYGON);
         glVertex3f(-0.1 , 0,-1);
         glVertex3f(-0.1, 0,0);
         glVertex3f(-0.1, 0.8,0);
         glVertex3f(-0.1, 0.8,-1);
     glEnd();
     //face lateral 3
     glBegin(GL_POLYGON);
         glVertex3f(-2.5 , 0,-1);
         glVertex3f(-2.5, 0,0);
         glVertex3f(-2.5, 0.8,0);
         glVertex3f(-2.5, 0.8,-1);

     glEnd();
     //face lateral 4
     glBegin(GL_POLYGON);
         glVertex3f(-2.4, 0,0);
         glVertex3f(-2.4 , 0,-1);
         glVertex3f(-2.4, 0.8,-1);
         glVertex3f(-2.4, 0.8,0);
     glEnd();
     //face tras 1
     glBegin (GL_POLYGON ) ;
         glVertex3f (-2.5 , 0.7 , -1);
         glVertex3f (-2.5, 0.8 , -1);
         glVertex3f (0, 0.8 , -1);
         glVertex3f (0, 0.7, -1);
     glEnd ( ) ;
     //face tras 2
     glBegin (GL_POLYGON ) ;
         glVertex3f (-0.1, 0, -1);
         glVertex3f (-0.1, 0.7 , -1);
         glVertex3f (0, 0.7 , -1);
         glVertex3f (0, 0 , -1);
     glEnd ( ) ;
     //face tras 3
     glBegin (GL_POLYGON ) ;
         glVertex3f (-2.4, 0.7 , -1);
         glVertex3f (-2.4, 0, -1);
         glVertex3f (-2.5, 0 , -1);
         glVertex3f (-2.5, 0.7 , -1);

     glEnd ( ) ;

}
