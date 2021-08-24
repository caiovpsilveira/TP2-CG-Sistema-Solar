//aceita escrever \n. Retorna o numero de \n escritos
int escreveStringFormatada(int x, int y, char *string){
    char *c;
    int offset = 15;
    int i=0;
    int ilumHab;

    glGetIntegerv(GL_LIGHTING, &ilumHab);//GL_LIGHTING estava habilitado antes de chamar a funcao?
    glDisable(GL_LIGHTING);

    glColor3f(1,1,1);
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++){
        if(*c == '\n'){
            i++;
            glRasterPos2f(x, y+i*offset);
        }
        else{
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
        }
    }

    if(ilumHab){
        glEnable(GL_LIGHTING);
    }

    return i;
}

//escreve informacoes complementares sobre o planeta quando observador esta na CAM_ACOMPANHA
void escreverInformacoesPlaneta(int x, int y, struct astro astro){
    char str_final[50];
    char str_aux[50];
    int i=0;
    int offset = 15;

    projecaoOrto();

    strncpy(str_final, "Nome: ", 50);
    strcat(str_final, astro.nome);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nDiametro (km): ", 50);
    if(strcmp("Sol", astro.nome) == 0){  //Se e o sol
        sprintf(str_aux, "%.0f", 2*astro.raio_esf*2E3*50);  //a escala do sol e diferente dos outros planetas
    }
    else{
        sprintf(str_aux, "%.0f", 2*astro.raio_esf*2E3);
    }
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nDistancia do sol (10^6 km): ", 50);
    sprintf(str_aux, "%.0f", astro.raio_trans*2);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nObliquidade da orbita (graus): ", 50);
    sprintf(str_aux, "%.2f", astro.obliquidade_orbita*180/M_PI);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nInclinacao orbital (graus): ", 50);
    sprintf(str_aux, "%.2f", astro.inclin_orbital*180/M_PI);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    retornaPerspectiva();
}

//escreve na tela TELA_MENU
void escreverMenuPrincipal(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Trabalho Pratico 2\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte espaco para comecar\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte C para ver os controles\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte Z para ver os creditos\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte I para ver o que cada informacao dos planetas significa\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte ESC para sair\n");

    retornaPerspectiva();
}

//escreve na tela TELA_MENU_PAUSE
void escreveMenuPause(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Pausado\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte C para ver os controles\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte Z para ver os creditos\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte I para ver o que cada informacao dos planetas significa\n");
    i += escreveStringFormatada(x, y + i*offset, "\n\nAperte esc para voltar a tela anterior ou X para ir para o menu principal\n");

    retornaPerspectiva();
}

//escreve na tela TELA_CREDITOS
void escreveCreditos(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Creditos\n");
    i += escreveStringFormatada(x, y + i*offset, "Abdul Kevin e Caio Vinicius\n");
    i += escreveStringFormatada(x, y + i*offset, "\n\nAperte esc para voltar a tela anterior\n");

    retornaPerspectiva();
}

//escreve na tela TELA_CONTROLES
void escreveControles(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "CONTROLES\n\n");
    i += escreveStringFormatada(x, y + i*offset, "CAMERA\n");
    i += escreveStringFormatada(x, y + i*offset,"Aperte 1, 2, 3 ou 4 para alterar a camera\n");
    i += escreveStringFormatada(x, y + i*offset,"1: camera superior, 2: camera frontal,\n3: camera livre, 4: camera acompanha planeta.\n\n");
    i += escreveStringFormatada(x, y + i*offset,"CONTROLE DE CAMERA LIVRE:\n");
    i += escreveStringFormatada(x, y + i*offset,"W A S D: movimentacao\n");
    i += escreveStringFormatada(x, y + i*offset,"Mexer o cursor: mudar direcao da camera\n");
    i += escreveStringFormatada(x, y + i*offset,"MWHEEL UP: Subir camera, MWHEEL DOWN: Descer camera\n");
    i += escreveStringFormatada(x, y + i*offset,"CONTROLE DE CAMERA QUE ACOMPANHA:\n");
    i += escreveStringFormatada(x, y + i*offset,"Aperta espaco para trocar o planeta.\n\n");
    i += escreveStringFormatada(x, y + i*offset,"DENTRO DA SIMULACAO:\n");
    i += escreveStringFormatada(x, y + i*offset,"R: reiniciar simulacao\n");
    i += escreveStringFormatada(x, y + i*offset,"P: pausar simulacao\n");
    i += escreveStringFormatada(x, y + i*offset,"ESC: Ir para o menu de pause\n");
    i += escreveStringFormatada(x, y + i*offset,"L: ligar/desligar iluminacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"Z: mostrar/esconder eixos de rotacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"X: considerar/desconsiderar inclinacao orbital.\n");
    i += escreveStringFormatada(x, y + i*offset,"C: considerar/desconsiderar obliquidade da orbita.\n");
    i += escreveStringFormatada(x, y + i*offset,"O: mostrar/esconder orbitas dos planetas.\n");
    i += escreveStringFormatada(x, y + i*offset,"V: mostrar/esconder eixos ordenados do glut.\n");
    i += escreveStringFormatada(x, y + i*offset, "\n\nAperte esc para voltar a tela anterior\n");

    retornaPerspectiva();
}

//escreve na tela de informacoe extra
void escreveInformacoes(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Informacoes\n");
    i += escreveStringFormatada(x, y + i*offset, "Escrever o que cada informacao dos planetas significa\n");
    i += escreveStringFormatada(x, y + i*offset, "\n\nAperte esc para voltar a tela anterior\n");

    retornaPerspectiva();
}

//escreve na tela TELA_PLANETAS os controles de toggle de estado de desenho
void escreveHud(int x, int y, int cam_atual, int ta_pausado){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Os planetas estao 1000x maiores, e o sol esta 20x maior.\nAs distancias entre as orbitas estao em escala 1:1.\n");

    switch(cam_atual){
        case CAM_CIMA:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera. Camera atual: Camera superior\n");
            break;
        case CAM_FRONTAL:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera. Camera atual: Camera frontal\n");
            break;
        case CAM_LIVRE:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera. Camera atual: Camera livre\n");
            break;
        case CAM_ACOMPANHA:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera.\nCamera atual: Camera centrando astros. Espaco para trocar o astro.\n");
            break;
        default:
            break;
    }
    if(ta_pausado){
        i += escreveStringFormatada(x, y + i*offset,"P: pausar. PAUSADO.\n");
    }
    else{
        i += escreveStringFormatada(x, y + i*offset,"P: pausar.\n");
    }
    i += escreveStringFormatada(x, y + i*offset, "R: reiniciar.\n");
    i += escreveStringFormatada(x, y + i*offset, "H: mostrar/esconder HUD Controles.\n");
    i += escreveStringFormatada(x, y + i*offset, "L: ligar/desligar iluminacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"Z: mostrar/esconder eixos de rotacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"X: considerar/desconsiderar inclinacao orbital.\n");
    i += escreveStringFormatada(x, y + i*offset,"C: considerar/desconsiderar obliquidade da orbita.\n");
    i += escreveStringFormatada(x, y + i*offset,"O: mostrar/esconder orbitas dos planetas.\n");
    i += escreveStringFormatada(x, y + i*offset,"V: mostrar/esconder eixos ordenados do glut.\n");
    i += escreveStringFormatada(x, y + i*offset,"ESC: menu de pause.\n");

    retornaPerspectiva();
}
