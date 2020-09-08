#include <iostream>
#include<math.h>
using namespace std;
#include <vector>
#include <cama.h>
#include <estante.h>
#include <mesa.h>
#include <piano.h>
#include <minion.h>

vector<Objeto*> objetos;
vector<Camera*> cameraOrtho;
vector<Camera*> cameraP;
vector<Camera*> cameraOb;
int marcaCameraOb = -1;
int marcaCamera = -1;
int marcaCameraO = -1;
int marcaCameraP = -1;
int posSelecionado = -1;

//sombra
bool drawShadow = false;
bool pontual = true;
float k = 0.0;
//sombra


void sombra(GLfloat plano[4], GLfloat lightPos[4]){
    glPushMatrix();

            GLfloat sombra[4][4];
            GUI::shadowMatrix(sombra,plano,lightPos);
        glDisable(GL_LIGHTING);
        glColor3d(0.0,0.0,0.0);
        if (drawShadow) {
            bool aux = glutGUI::draw_eixos;
            glutGUI::draw_eixos = false;
            for (int i = 0; i < objetos.size(); ++i) {

                if(objetos[i]->sombra){
                    glPushMatrix();
                        objetos[i]->desenha();
                    glPopMatrix();

                }
            }
            glutGUI::draw_eixos = aux;
        }
        glEnable(GL_LIGHTING);
    glPopMatrix();

}

void desenha() {
    GUI::displayInit();
    GUI::drawOrigin(1);

    GUI::setColor(1,0.5,0.5);
    GUI::drawFloor();
    glPushMatrix();     
    glTranslated(0.0,k-0.001,0.0);
    glPopMatrix();

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    //sombra1
    //definindo a luz que sera usada para gerar a sombra
    float lightPos[4] = {0+glutGUI::lx,3+glutGUI::ly,3+glutGUI::lz,pontual};
    //GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,pontual);
    GUI::setLight(0,0,3,3,true,false,false,false,pontual);
    //desenhando os objetos projetados
    GLfloat plano[4] = {0,1,0,-1}; //{Normal, x, y, z}
    sombra(plano, lightPos);

    //sombra2
    //definindo a luz que sera usada para gerar a sombra
    float lightPos2[4] = {0+glutGUI::lx,3+glutGUI::ly,3+glutGUI::lz,pontual};
    //GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,pontual);
    GUI::setLight(0,0,3,3,true,false,false,false,pontual);
    //desenhando os objetos projetados
    GLfloat plano2[4] = {1,0,0,2.49}; //{Normal, x, y, z}
    sombra(plano2, lightPos2);

    //sombra3
    //definindo a luz que sera usada para gerar a sombra
    float lightPos3[4] = {0+glutGUI::lx,3+glutGUI::ly,3+glutGUI::lz,pontual};
    //GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,pontual);
    GUI::setLight(0,0,3,3,true,false,false,false,pontual);
    //desenhando os objetos projetados
    GLfloat plano3[4] = {-1,0,0,2.49}; //{Normal, x, y, z}
    sombra(plano3, lightPos3);

    //-------------------sombra3-------------------
    //-------------------sombra4-------------------
    //definindo a luz que sera usada para gerar a sombra
    float lightPos4[4] = {0+glutGUI::lx,3+glutGUI::ly,3+glutGUI::lz,pontual};
    //GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,pontual);
    GUI::setLight(0,0,3,3,true,false,false,false,pontual);
    //desenhando os objetos projetados
    GLfloat plano4[4] = {0,sqrt(2)/2,sqrt(2)/2,1.32}; //{Normal, x, y, z}
    sombra(plano4, lightPos4);

    //-------------------sombra4-------------------

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }
 //Parede 1
    glPushMatrix();
    GUI::setColor(1,0,1);
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(2.5,0,2.5);
        glVertex3f(2.5,3.5,2.5);
        glVertex3f(2.5,3.5,-2.5);
        glVertex3f(2.5,0,-2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();


    //Parede 2
    GUI::setColor(4,2,1);
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f(2.5,0,-2.5);
        glVertex3f(2.5,3.5,-2.5);
        glVertex3f(-2.5,3.5,-2.5);
        glVertex3f(-2.5,0,-2.5);
    glEnd();
    glPopMatrix();
    //Parede 3

    GUI::setColor(2,3,1);

    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glVertex3f(-2.5,0,2.5);
        glVertex3f(-2.5,0,-2.5);
        glVertex3f(-2.5,3.5,-2.5);
        glVertex3f(-2.5,3.5,2.5);
    glEnd();
    glPopMatrix();
    //Parede 4

    GUI::setColor(5,0,1);
    glRotated(45,1,0,0);
    glTranslated(0,0,-1.5);
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f(2.5,0,-2.5);
        glVertex3f(2.5,3.5,-2.5);
        glVertex3f(-2.5,3.5,-2.5);
        glVertex3f(-2.5,0,-2.5);
    glEnd();
    glPopMatrix();

    cout<<glutGUI::cam->e.x<<','<<glutGUI::cam->e.y<<','<<glutGUI::cam->e.z<<',';
    cout<<glutGUI::cam->c.x<<','<<glutGUI::cam->c.y<<','<<glutGUI::cam->c.z<<',';
    cout<<glutGUI::cam->u.x<<','<<glutGUI::cam->u.y<<','<<glutGUI::cam->u.z<<endl;
    GUI::displayEnd();

}

bool incluirObjeto = true;

void teclado(unsigned char key, int x, int y) {
        GUI::keyInit(key,x,y);

    switch (key) {
        case 't':
            glutGUI::trans_obj = !glutGUI::trans_obj;
            break;
        case 'l':
            glutGUI::trans_luz = !glutGUI::trans_luz;
            break;

        case 'n':
            if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
                objetos[posSelecionado]->selecionado = false;
            }
            posSelecionado++;
            posSelecionado = posSelecionado%objetos.size();
            if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
                objetos[posSelecionado]->selecionado = true;
            }
            break;
        case 'b':
            if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
                objetos[posSelecionado]->selecionado = false;
            }
            posSelecionado--;
            if (posSelecionado < 0) {
                posSelecionado = objetos.size()-1;
            }
            if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
                objetos[posSelecionado]->selecionado = true;
            }
            break;

        case 'p':
            incluirObjeto = !incluirObjeto;
            break;
        case '2':
            if (incluirObjeto) {
                objetos.push_back( new Cama());
            }
            break;
        case '3':
            if (incluirObjeto) {
                objetos.push_back( new Estante());
            }
            break;
        case '4':
            if(incluirObjeto){
                GUI::drawOrigin(1);
                objetos.push_back(new Piano());
            }
            break;
        case '5':
            if(incluirObjeto){
                objetos.push_back(new Minion());
            }
            break;
        case '6':
            if(incluirObjeto){
                objetos.push_back(new Mesa());
            }
            break;

        case 'q':
            glutGUI::ortho = true;
            glutGUI::perspective= false;
            glutGUI::obliq = false;
            marcaCameraO++;

            if(marcaCameraO>=cameraOrtho.size()){
                marcaCameraO =0;
            }
            glutGUI::cam = new CameraDistante(cameraOrtho[marcaCameraO]->e, cameraOrtho[marcaCameraO]->c, cameraOrtho[marcaCameraO]->u);
            break;
        case 'a':
            glutGUI::perspective = true;
            glutGUI::obliq = false;
            glutGUI::ortho = false;
            marcaCameraP++;

            if(marcaCameraP>=cameraP.size()){
                marcaCameraP =0;
            }
            glutGUI::cam = new CameraDistante(cameraP[marcaCameraP]->e, cameraP[marcaCameraP]->c, cameraP[marcaCameraP]->u);
            break;

        case 'z':
            glutGUI::obliq = true;
            glutGUI::ortho = false;
            glutGUI::perspective = false;
            marcaCameraOb++;
            if(marcaCameraOb>=cameraOb.size()){
                marcaCameraOb = 0;
            }
            glutGUI::cam = new CameraDistante(cameraOb[marcaCameraOb]->e, cameraOb[marcaCameraOb]->c, cameraOb[marcaCameraOb]->u);
            break;
            case 'w':
                drawShadow = !drawShadow;
                break;
            case 's':
                pontual = !pontual;
                break;
            case 'x':
                k += 0.1;
                break;
            case 'c':
                k -= 0.1;
                break;

            case 'u':

                if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
                 objetos[posSelecionado]->sombra = !objetos[posSelecionado]->sombra;
            }

        default:
            break;
    }
}

int main()
{
    cout << "Hello World!" << endl;


   cameraP.push_back(new CameraDistante(4,0.5,0.01,0,1,0,0.1,0.99,0.0002));
   cameraP.push_back(new CameraDistante(2.5,0,3.7,0,1,0,-0.05,0.9,-0.07));
   cameraP.push_back(new CameraDistante(3,2.1,3.2,0,1,0,-0.1,0.9,-0.1));
   cameraOrtho.push_back(new CameraDistante(5,5.5,6.7,0,1,0,-0.2,0.8,-0.3));
   cameraOrtho.push_back(new CameraDistante(3,3.04,9,0,1,0,-0.07,0.9,-0.19));
   cameraOrtho.push_back(new CameraDistante(-0.00019,5.13,9,0,1,0,9,0.91,-0.41));
   cameraOb.push_back(new CameraDistante(0.9,1.9,10.3,-1.8,-0.7,1.09,-0.07,0.9,-0.2));

    GUI gui = GUI(800,600,desenha,teclado);
}

