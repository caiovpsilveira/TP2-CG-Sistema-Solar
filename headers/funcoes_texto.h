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
