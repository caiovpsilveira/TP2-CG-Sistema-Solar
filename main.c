/*  Trabalho Pratico 2 - Computacao Grafica - CEFETMG
*   Autores: Abdul Kevin Klexis e Caio Vinicius Pereira Silveira
*   Agosto 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "headers/definicoes.h"
#include "headers/structs.h"
#include "headers/declaracao_funcoes.h"
#include "headers/funcoes_desenho.h"
#include "headers/funcoes_diversas.h"
#include "headers/iluminacao.h"
#include "headers/funcoes_astros.h"
#include "headers/funcoes_observador.h"

int tela, simul_pausada, aux_pause;
int larg_janela, alt_janela;
int xMouse, yMouse;
int vet_estados[TAM_VET_ESTADOS];
GLfloat ang_perspec, fAspect;

struct observador obs;
struct astro vet_astros[TAM_VET_ASTROS];

void habilita(int estado){
    vet_estados[estado] = 1;
}

void desabilita(int estado){
    vet_estados[estado] = 0;
}

void setup(){   //estados do glut que nao serao alterados ao longo da execucao

    inicializarTexturas(vet_astros);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);    //sombreamento
    glEnable(GL_CULL_FACE); //nao desenhar de dentro do objeto
    glCullFace(GL_BACK);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void inicializaTudo(){  //estados que podem ser alterados ao longo da execucao. Essa funcao os coloca em um estado inicial e pode ser usada para reiniciar
    ang_perspec = 45;
    tela = TELA_PLANETAS;
    simul_pausada=0;
    inicializaIluminacao();
    inicializaVetEstados(vet_estados);
    inicializaAstros(vet_astros);
    inicializaObservador(&obs);

    //temporario: ideal seria colocar uma tecla pra alternar
    habilita(EIXO_ROT);
    habilita(INC_ORBITAL);
    habilita(OBLIQ_ORBITA);
}

void desenhaMinhaCena(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    switch(tela){
        case TELA_PLANETAS:
            glutSetCursor(GLUT_CURSOR_NONE);
            desenhaEixosOrdenados();
            desenhaAstros(vet_astros, vet_estados);
            break;
        case TELA_PAUSE_MENU:
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            break;
        default:
            break;
    }

    glutSwapBuffers();
}

void atualizaCena(int valorQualquer){   //UPDATE DA CENA
    if(!simul_pausada){
        movimentaAstros(vet_astros);
    }

    glutPostRedisplay();
    glutTimerFunc(33, atualizaCena, 0); // por qu� 33? 1000/33 = 30fps, 16:60
}

void redimensionar(int width, int height){

    larg_janela = width;
    alt_janela = height;

    if(height==0){
        height=1;
    }

    glViewport(0, 0, width, height);

    fAspect = (GLfloat)width/(GLfloat)height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(ang_perspec, fAspect, 0.5, 1000);

    atualizarObservador(&obs);
}

void teclaPressionada(unsigned char key, int x, int y){

    float vetorDiretor[3] = {sin(obs.phi)*cos(obs.theta), sin(obs.phi)*sin(obs.theta), cos(obs.phi)};
    normalizarVetor3D(vetorDiretor);

    float vetorPerpendicularXY[2];  //vetor perpendicular a projecao de vetorDiretor no eixo XY
    vetorPerpendicularXY[0] = 1;
    vetorPerpendicularXY[1] = -vetorDiretor[0]/vetorDiretor[1];
    normalizarVetor2D(vetorPerpendicularXY);

    int sinal_horizontal=1;
    if(!(obs.theta>=0 && obs.theta<M_PI)){
        sinal_horizontal=-1;
    }

    switch(key){
    case 'd':
        if(tela==TELA_PLANETAS){
            obs.xpos -= obs.velocidade * vetorPerpendicularXY[0] * sinal_horizontal;
            obs.ypos -= obs.velocidade * vetorPerpendicularXY[1] * sinal_horizontal;
        }
        break;
    case 'a':
        if(tela==TELA_PLANETAS){
            obs.xpos += obs.velocidade * vetorPerpendicularXY[0] * sinal_horizontal;
            obs.ypos += obs.velocidade * vetorPerpendicularXY[1] * sinal_horizontal;
        }
        break;
    case 'w':   //para frente
        if(tela==TELA_PLANETAS){
            obs.xpos += obs.velocidade * vetorDiretor[0];
            obs.ypos += obs.velocidade * vetorDiretor[1];
            obs.zpos += obs.velocidade * vetorDiretor[2];
        }
        break;
    case 's':
        if(tela==TELA_PLANETAS){
            obs.xpos -= obs.velocidade * vetorDiretor[0];
            obs.ypos -= obs.velocidade * vetorDiretor[1];
            obs.zpos -= obs.velocidade * vetorDiretor[2];
        }
        break;
    case 'p':
        if(tela==TELA_PLANETAS){
                if(simul_pausada){
                    simul_pausada=0;
                }
                else{
                    simul_pausada=1;
                }
            }
        break;
    case 'r':
        inicializaTudo();
        break;
    case 27: //esc
        if(tela==TELA_PLANETAS){
            tela=TELA_PAUSE_MENU;
            aux_pause = simul_pausada;
            simul_pausada=1;
        }
        else if(tela==TELA_PAUSE_MENU){
            glutWarpPointer(larg_janela/2,alt_janela/2);
            if(!aux_pause){    //retornar ao estado antes de ir para o menu
                simul_pausada=0;
            }
            tela=TELA_PLANETAS;
        }
        break;
    default:
        break;
    }
    atualizarObservador(&obs);
}

void posicionaCamera(int x, int y) {

    if(tela==TELA_PLANETAS){
        xMouse = x;
        yMouse = y;
        glutWarpPointer(larg_janela/2,alt_janela/2);
        obs.theta -= (float)(xMouse - larg_janela/2)/500;
        obs.phi -= (float)(yMouse - alt_janela/2)/500;
        limitarAngulosObservador(&obs);
        corrigirUpVectorObservador(&obs);
        atualizarObservador(&obs);
    }
}

void rodaMouse(int button, int dir, int x, int y){
    if (dir > 0){ //roda pra cima
        if(tela==TELA_PLANETAS){
            obs.zpos += obs.velocidade;
        }
    }
    else{
        if(tela==TELA_PLANETAS){
            obs.zpos -= obs.velocidade;
        }
    }
    atualizarObservador(&obs);
}

// fun��o principal
int main(int argc, char** argv)
{
    imprimirInstrucoesConsole();
    glutInit(&argc, argv);

    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(600, 100);

    glutCreateWindow("tp2 teste");

    glutReshapeFunc(redimensionar);
    glutDisplayFunc(desenhaMinhaCena);
    glutMouseWheelFunc(rodaMouse);
    glutKeyboardFunc(teclaPressionada);
    glutPassiveMotionFunc(posicionaCamera);
    glutTimerFunc(0, atualizaCena, 33);

    setup();
    inicializaTudo();

    glutMainLoop();
    return 0;
}
