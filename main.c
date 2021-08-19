/*  Trabalho Pratico 2 - Computacao Grafica - CEFETMG
*   Autores: Abdul Kevin Klexis e Caio Vinicius Pereira Silveira
*   Agosto 2021
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "headers/definicoes.h"
#include "headers/structs.h"
#include "headers/funcoes_projecao.h"
#include "headers/funcoes_texto.h"
#include "headers/funcoes_desenho.h"
#include "headers/funcoes_diversas.h"
#include "headers/iluminacao.h"
#include "headers/funcoes_astros.h"
#include "headers/funcoes_observador.h"

int obs_atual, astro_atual; //indices da camera
int luzLigada;
int tela, telaAnterior, simul_pausada, aux_pause;
int larg_janela, alt_janela;
int xMouse, yMouse;
int vet_estados[TAM_VET_ESTADOS];
GLfloat ang_perspec, fAspect;

struct observador vet_obs[TAM_VET_OBS];
struct astro vet_astros[TAM_VET_ASTROS];

void toggleEstado(int estado){
    if(vet_estados[estado]){
        vet_estados[estado]=0;
    }
    else{
        vet_estados[estado]=1;
    }
}

void setup(){   //setup inicial

    inicializarTexturas(vet_astros);
    inicializaNomes(vet_astros);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);    //sombreamento
    glEnable(GL_CULL_FACE); //nao desenhar de dentro do objeto
    glCullFace(GL_BACK);

    tela = TELA_MENU;
    telaAnterior = TELA_MENU;
}

void inicializaTudo(){  //estados que podem ser alterados ao longo da execucao. Essa funcao os coloca em um estado inicial e pode ser usada para reiniciar
    obs_atual = CAM_CIMA;
    astro_atual = 0;
    ang_perspec = 45;

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    luzLigada = 1;

    simul_pausada = 0;
    inicializaVetEstados(vet_estados);
    // inicializaAstros(vet_astros);
    inicializaAstrosReal(vet_astros);
    inicializaObservadores(vet_obs);
}

void desenhaMinhaCena(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    switch(tela){
        case TELA_MENU:
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            escreverMenuPrincipal();
        break;
        case TELA_PLANETAS:
            atualizarIluminacao();
            glutSetCursor(GLUT_CURSOR_NONE);

            desenhaAstros(vet_astros, vet_estados);
            escreveHud(obs_atual, simul_pausada);

            if(vet_estados[EIXOS_ORDEN]){
                desenhaEixosOrdenados();
            }

            if(obs_atual == CAM_ACOMPANHA){
                escreverInformacoesPlaneta(30,500, vet_astros[astro_atual]);
            }

            break;
        case TELA_PAUSE_MENU:
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            escreveMenuPause();
            break;
        case TELA_CREDITOS:
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            escreveCreditos();
            break;
        case TELA_CONTROLES:
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            escreveControles();
            break;
        case TELA_INFORMACOES:
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            escreveInformacoes();
            break;
        default:
            break;
    }

    glutSwapBuffers();
}

void atualizaCena(int valorQualquer){   //UPDATE DA CENA
    if(tela == TELA_PLANETAS){
        if(!simul_pausada){
            movimentaAstros(vet_astros);
        }
        if(obs_atual == CAM_ACOMPANHA){
            atualizaCamAcompanha(vet_astros, &vet_obs[obs_atual], astro_atual, vet_estados);
            atualizarObservador(vet_obs[obs_atual]);
        }
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
    gluPerspective(ang_perspec, fAspect, 0.5, 2000);

    atualizarObservador(vet_obs[obs_atual]);

    glMatrixMode(GL_MODELVIEW);
}

void teclaPressionada(unsigned char key, int x, int y){

    float vetorDiretor[3] = {sin(vet_obs[obs_atual].phi)*cos(vet_obs[obs_atual].theta), sin(vet_obs[obs_atual].phi)*sin(vet_obs[obs_atual].theta), cos(vet_obs[obs_atual].phi)};
    normalizarVetor3D(vetorDiretor);

    float vetorPerpendicularXY[2];  //vetor perpendicular a projecao de vetorDiretor no eixo XY
    vetorPerpendicularXY[0] = 1;
    vetorPerpendicularXY[1] = -vetorDiretor[0]/vetorDiretor[1];
    normalizarVetor2D(vetorPerpendicularXY);

    int sinal_horizontal=1;
    if(!(vet_obs[obs_atual].theta>=0 && vet_obs[obs_atual].theta<M_PI)){
        sinal_horizontal=-1;
    }

    switch(key){
    /*
    LETRAS
    */
    case 'A':
    case 'a':
        if(tela==TELA_PLANETAS){
            vet_obs[obs_atual].xpos += vet_obs[obs_atual].velocidade * vetorPerpendicularXY[0] * sinal_horizontal;
            vet_obs[obs_atual].ypos += vet_obs[obs_atual].velocidade * vetorPerpendicularXY[1] * sinal_horizontal;
        }
        break;
    case 'C':
    case 'c':
        if(tela==TELA_PLANETAS){
            toggleEstado(OBLIQ_ORBITA);
        }
        else if(tela == TELA_PAUSE_MENU){
            telaAnterior = TELA_PAUSE_MENU;
            tela = TELA_CONTROLES;
        }
        else if(tela == TELA_MENU){
            telaAnterior = TELA_MENU;
            tela = TELA_CONTROLES;
        }
        break;
    case 'D':
    case 'd':
        if(tela==TELA_PLANETAS){
            vet_obs[obs_atual].xpos -= vet_obs[obs_atual].velocidade * vetorPerpendicularXY[0] * sinal_horizontal;
            vet_obs[obs_atual].ypos -= vet_obs[obs_atual].velocidade * vetorPerpendicularXY[1] * sinal_horizontal;
        }
        break;
    case 'I':
    case 'i':
        if(tela == TELA_MENU){
            telaAnterior = TELA_MENU;
            tela = TELA_INFORMACOES;
        }
        else if(tela == TELA_PAUSE_MENU){
            telaAnterior = TELA_PAUSE_MENU;
            tela = TELA_INFORMACOES;
        }
        break;
    case 'L':
    case 'l':
        if(luzLigada){
            glDisable(GL_LIGHTING);
            luzLigada = 0;
        }
        else{
            glEnable(GL_LIGHTING);
            luzLigada = 1;
        }
        break;
    case 'O':
    case 'o':
        if(tela==TELA_PLANETAS){
            toggleEstado(ORBITAS);
        }
        break;
    case 'P':
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
    case 'R':
    case 'r':
        if(tela == TELA_PLANETAS){
            inicializaTudo();
        }
        break;
    case 'S':
    case 's':
        if(tela==TELA_PLANETAS){
            vet_obs[obs_atual].xpos -= vet_obs[obs_atual].velocidade * vetorDiretor[0];
            vet_obs[obs_atual].ypos -= vet_obs[obs_atual].velocidade * vetorDiretor[1];
            vet_obs[obs_atual].zpos -= vet_obs[obs_atual].velocidade * vetorDiretor[2];
        }
        break;
    case 'V':
    case 'v':
        if(tela==TELA_PLANETAS){
            toggleEstado(EIXOS_ORDEN);
        }
        break;
    case 'W':
    case 'w':   //para frente
        if(tela==TELA_PLANETAS){
            vet_obs[obs_atual].xpos += vet_obs[obs_atual].velocidade * vetorDiretor[0];
            vet_obs[obs_atual].ypos += vet_obs[obs_atual].velocidade * vetorDiretor[1];
            vet_obs[obs_atual].zpos += vet_obs[obs_atual].velocidade * vetorDiretor[2];
        }
        break;
    case 'X':
    case 'x':
        if(tela==TELA_PLANETAS){
            toggleEstado(INC_ORBITAL);
        }
        else if(tela == TELA_PAUSE_MENU){
            tela = TELA_MENU;
        }
        break;
    case 'Z':
    case 'z':
        if(tela==TELA_PLANETAS){
            toggleEstado(EIXO_ROT);
        }
        else if(tela == TELA_MENU){
            telaAnterior = TELA_MENU;
            tela = TELA_CREDITOS;
        }
        else if(tela == TELA_PAUSE_MENU){
            telaAnterior = TELA_PAUSE_MENU;
            tela = TELA_CREDITOS;
        }
        break;

    /*
    NUMEROS
    */
    case '1':
        if(tela==TELA_PLANETAS){
            obs_atual = CAM_CIMA;
        }
        break;
    case '2':
        if(tela==TELA_PLANETAS){
            obs_atual = CAM_FRONTAL;
        }
        break;
    case '3':
        if(tela==TELA_PLANETAS){
            obs_atual = CAM_LIVRE;
        }
        break;
    case '4':
        if(tela==TELA_PLANETAS){
            obs_atual = CAM_ACOMPANHA;
        }
        break;

    /*
    OUTROS
    */
    case ' ':
        if(tela == TELA_MENU){
            inicializaTudo();
            tela = TELA_PLANETAS;
        }
        else if(tela==TELA_PLANETAS && obs_atual == CAM_ACOMPANHA){
            astro_atual++;
            if(astro_atual == TAM_VET_ASTROS){
                astro_atual = 0;
            }
        }
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
        else if(tela == TELA_MENU){
            exit(0);
        }
        else if(tela == TELA_CONTROLES || tela == TELA_INFORMACOES || tela == TELA_CREDITOS){
            tela = telaAnterior;
        }
        break;
    default:
        break;
    }
    atualizarObservador(vet_obs[obs_atual]);
}

void posicionaCamera(int x, int y) {

    if(tela==TELA_PLANETAS){
        xMouse = x;
        yMouse = y;
        glutWarpPointer(larg_janela/2,alt_janela/2);
        vet_obs[obs_atual].theta -= (float)(xMouse - larg_janela/2)/500;
        vet_obs[obs_atual].phi -= (float)(yMouse - alt_janela/2)/500;
        limitarAngulosObservador(&vet_obs[obs_atual]);
        corrigirUpVectorObservador(&vet_obs[obs_atual]);
        atualizarObservador(vet_obs[obs_atual]);
    }
}

void rodaMouse(int button, int dir, int x, int y){
    if (dir > 0){ //roda pra cima
        if(tela==TELA_PLANETAS){
            vet_obs[obs_atual].zpos += vet_obs[obs_atual].velocidade;
        }
    }
    else{
        if(tela==TELA_PLANETAS){
            vet_obs[obs_atual].zpos -= vet_obs[obs_atual].velocidade;
        }
    }
    atualizarObservador(vet_obs[obs_atual]);
}

// fun��o principal
int main(int argc, char** argv)
{
    imprimirInstrucoesConsole();
    glutInit(&argc, argv);

    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
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
