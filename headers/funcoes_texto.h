void escreveString(int x, int y, char *string){
    char *c;
    int ilumHab;

    glGetIntegerv(GL_LIGHTING, &ilumHab);//GL_LIGHTING estava habilitado antes de chamar a funcao?
    glDisable(GL_LIGHTING);

    glColor3f(1,1,1);
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);

    if(ilumHab){
        glEnable(GL_LIGHTING);
    }
}

void escreverTexto(int x, int y, char *string){
    projecaoOrto();
    escreveString(x, y, string);
    retornaPerspectiva();
}

void escreverInformacoesPlaneta(int x, int y, struct astro astro){
    char str_final[50];
    char str_aux[50];

    projecaoOrto();

    strncpy(str_final, "Nome: ", 50);
    strcat(str_final, astro.nome);
    escreveString(x, y, str_final);

    strncpy(str_final, "Diametro: ", 50);
    sprintf(str_aux, "%.0f", 2*astro.raio_esf);
    strcat(str_final, str_aux);
    escreveString(x, y+15, str_final);

    strncpy(str_final, "Raio de translacao: ", 50);
    sprintf(str_aux, "%.0f", astro.raio_trans);
    strcat(str_final, str_aux);
    escreveString(x, y+30, str_final);

    strncpy(str_final, "Obliquidade da orbita (graus): ", 50);
    sprintf(str_aux, "%.2f", astro.obliquidade_orbita*180/M_PI);
    strcat(str_final, str_aux);
    escreveString(x, y+45, str_final);

    strncpy(str_final, "Inclinacao orbital (graus): ", 50);
    sprintf(str_aux, "%.2f", astro.inclin_orbital*180/M_PI);
    strcat(str_final, str_aux);
    escreveString(x, y+60, str_final);

    retornaPerspectiva();
}

void escreverMenuPrincipal(){
    projecaoOrto();
    escreveString(10,10, "Trabalho Pratico 2");
    escreveString(10, 20, "Aperte espaco para comecar");
    escreveString(10, 45, "Aperte C para ver os controles");
    escreveString(10,60, "Aperte Z para ver os creditos");
    escreveString(10,75, "Aperte I para ver o que cada informacao dos planetas significa");
    escreveString(10,90, "Aperte ESC para sair");
    retornaPerspectiva();
}

//C: Controles
//X: creditos
//I: informacoes extras
void escreveMenuPause(){
    projecaoOrto();
    escreveString(10,15, "Pausado");
    escreveString(10, 30, "Aperte esc para voltar a tela anterior ou X para ir para o menu principal");
    escreveString(10, 45, "Aperte C para ver os controles");
    escreveString(10,60, "Aperte Z para ver os creditos");
    escreveString(10,75, "Aperte I para ver o que cada informacao dos planetas significa");
    retornaPerspectiva();
}

void escreveCreditos(){
    projecaoOrto();
    escreveString(10,15, "Creditos");
    escreveString(10, 30, "Abdul Kevin e Caio Vinicius");
    escreveString(10, 45, "Aperte esc para voltar a tela anterior");
    retornaPerspectiva();
}

void escreveControles(){
    projecaoOrto();
    escreveString(10,15, "CONTROLES");
    escreveString(10,30, "CAMERA");
    escreveString(10,45,"Aperte 1, 2, 3 ou 4 para alterar a camera");
    escreveString(10,60,"1: camera superior, 2: camera frontal, 3: camera livre, 4: camera acompanha planeta.");
    escreveString(10,75,"CONTROLE DE CAMERA LIVRE:");
    escreveString(10,90,"W A S D: movimentacao");
    escreveString(10,105,"Mexer o cursor: mudar direcao da camera");
    escreveString(10,120,"MWHEEL UP: Subir camera, MWHEEL DOWN: Descer camera\n\n");
    escreveString(10,135,"CONTROLE DE CAMERA QUE ACOMPANHA:");
    escreveString(10,150,"Aperta espaco para trocar o planeta.\n\n");
    escreveString(10,200,"DENTRO DA SIMULACAO:");
    escreveString(10,215,"R: reiniciar simulacao");
    escreveString(10,230,"P: pausar simulacao");
    escreveString(10,245,"ESC: Ir para o menu de pause");
    escreveString(10,260,"L: ligar/desligar iluminacao.");
    escreveString(10,275,"Z: mostrar/esconder eixos de rotacao.");
    escreveString(10,290,"X: considerar/desconsiderar inclinacao orbital.");
    escreveString(10,305,"C: considerar/desconsiderar obliquidade da orbita.");
    escreveString(10, 320, "O: mostrar/esconder orbitas dos planetas.");
    escreveString(10,335,"V: mostrar/esconder eixos ordenados do glut.");
    escreveString(10, 370, "Aperte esc para voltar a tela anterior");
    retornaPerspectiva();
}

void escreveInformacoes(){
    projecaoOrto();
    escreveString(10,10, "Informacoes");
    escreveString(10, 20, "Escrever o que cada informacao dos planetas significa");
    escreveString(10, 45, "Aperte esc para voltar a tela anterior");
    retornaPerspectiva();
}

void escreveHud(){
    projecaoOrto();
    escreveString(10,10,"P: pausar simulacao.");
    escreveString(10,25, "L: ligar/desligar iluminacao.");
    escreveString(10,40,"Z: mostrar/esconder eixos de rotacao.");
    escreveString(10,55,"X: considerar/desconsiderar inclinacao orbital.");
    escreveString(10,70,"C: considerar/desconsiderar obliquidade da orbita.");
    escreveString(10,85,"V: mostrar/esconder eixos ordenados do glut.");
    escreveString(10,100,"ESC: menu de pause.");
    retornaPerspectiva();
}
