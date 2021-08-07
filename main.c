/*  Trabalho Pratico 2 - Computacao Grafica - CEFETMG
*   Autores: Abdul Kevin Klexis e Caio Vinicius Pereira Silveira
*   Agosto 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "headers/definicoes.h"
#include "headers/structs.h"
#include "headers/inicializacao.h"
#include "headers/funcoes_desenho.h"
#include "headers/funcoes_update_cena.h"

int tela;
float upz;
GLfloat ang_perspec, fAspect;

struct observador obs;
struct astro vet_astros[TAM_VET_ASTROS];

void inicializaTudo(){
    ang_perspec = 45;
    tela = 0;
    upz=1;
    inicializaIluminacao();
    inicializaAstros(vet_astros);
    inicializaObservador(&obs);
}

void desenhaMinhaCena(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    switch(tela){
        case 0:
            desenhaEixos();
            desenhaAstros(vet_astros);
            break;
        default:
            break;
    }

    glutSwapBuffers();
}

void atualizaCena(int valorQualquer){   //UPDATE DA CENA
    movimentaAstros(vet_astros);

    glutPostRedisplay();
    glutTimerFunc(33, atualizaCena, 0); // por quê 33? 1000/33 = 30fps, 16:60
}

void redimensionar(int width, int height){
    if(height==0){
        height=1;
    }

    glViewport(0, 0, width, height);

    fAspect = (GLfloat)width/(GLfloat)height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(ang_perspec, fAspect, 0.5, 500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obs.raio*sin(obs.phi)*cos(obs.theta), obs.raio*sin(obs.phi)*sin(obs.theta), obs.raio*cos(obs.phi), 0,0,0, 0,0,upz);
}

void SpecialKeys(int key, int x, int y){

    switch (key) {
        case GLUT_KEY_LEFT :
            obs.theta -= M_PI/180; //somar 1 grau (radianos).
            break;
        case GLUT_KEY_RIGHT :
            obs.theta += M_PI/180;
            break;
        case GLUT_KEY_UP :
            obs.phi -= M_PI/180;
            break;
        case GLUT_KEY_DOWN :
            obs.phi += M_PI/180;
            break;
        case GLUT_KEY_HOME :
            obs.raio++;
            break;
        case GLUT_KEY_END :
            obs.raio--;
            break;
    }

    float xObs = obs.raio*sin(obs.phi)*cos(obs.theta);
    float yObs = obs.raio*sin(obs.phi)*sin(obs.theta);
    float zObs = obs.raio*cos(obs.phi);
    printf("theta:%f, phi:%f, raio:%f, xObs:%f, yObs:%f, zObs:%f\n",obs.theta,obs.phi,obs.raio,xObs,yObs,zObs);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(xObs, yObs, zObs, 0,0,0, 0,0,upz);
    glutPostRedisplay();
}

// função principal
int main(int argc, char** argv)
{
    srand(time(NULL));
    glutInit(&argc, argv);

    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(LARG_JANELA, ALT_JANELA);
    glutInitWindowPosition(600, 100);

    glutCreateWindow("tp2 teste");

    inicializaTudo();
    glutReshapeFunc(redimensionar);
    glutDisplayFunc(desenhaMinhaCena);
    glutSpecialFunc(SpecialKeys);
    glutTimerFunc(0, atualizaCena, 33);

    glutMainLoop();
    return 0;
}
