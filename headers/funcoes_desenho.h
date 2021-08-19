//Funcao de desenhar uma esfera, retirada do exemplo de marte
void solidSphere(int radius, int stacks, int columns){
    // cria uma quádrica
    GLUquadric* quadObj = gluNewQuadric();
    // estilo preenchido... poderia ser GLU_LINE, GLU_SILHOUETTE
    // ou GLU_POINT
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    // chama 01 glNormal para cada vértice.. poderia ser
    // GLU_FLAT (01 por face) ou GLU_NONE
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    // chama 01 glTexCoord por vértice
    gluQuadricTexture(quadObj, GL_TRUE);
    // cria os vértices de uma esfera
    gluSphere(quadObj, radius, stacks, columns);
    // limpa as variáveis que a GLU usou para criar a esfera
    gluDeleteQuadric(quadObj);
}

//desenhas os eixos x,y,z , nas cores r,g,b.
void desenhaEixosOrdenados(){
    int ilumHab;
    glGetIntegerv(GL_LIGHTING, &ilumHab); //GL_LIGHTING estava habilitado antes de chamar a funcao?

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glDisable(GL_LIGHTING);
    glLineWidth(2.0);
    glColor3f(1,0,0);
    glBegin(GL_LINES);  //eixo x
        glVertex3f(0,0,0);
        glVertex3f(100,0,0);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINES);   //eixo y
        glVertex3f(0,0,0);
        glVertex3f(0,100,0);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);   //eixo z
        glVertex3f(0,0,0);
        glVertex3f(0,0,100);
    glEnd();

    if(ilumHab){
        glEnable(GL_LIGHTING);
    }
}

//desenha a orbita de um astro. Considera a posicao 0,0,0 como centro do movimento
void desenhaOrbita(struct astro astro){
    int i, j;
    int ilumHab;

    float angulo = 2*M_PI/PONTOS_CIRCULO;

    glGetIntegerv(GL_LIGHTING, &ilumHab);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    for(j=0; j<PONTOS_CIRCULO; j++){
        glVertex3f(astro.raio_trans*cos(j*angulo), astro.raio_trans*sin(j*angulo), 0);
    }
    glEnd();

    if(ilumHab){
        glEnable(GL_LIGHTING);
    }
    glEnable(GL_TEXTURE_2D);
}

//desenha um eixo paralelo ao eixo Z do planeta. Sera rotacionado caso a inclinacao orbital e obliquidade orbital estejam ativados
void desenhaEixoRot(struct astro astro){
    int ilumHab;
    glGetIntegerv(GL_LIGHTING, &ilumHab);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glColor3f(1,1,1);
    glBegin(GL_LINES);  //eixo z
        glVertex3f(0,0,-1.5*astro.raio_esf);
        glVertex3f(0,0, 1.5*astro.raio_esf);
    glEnd();
    glEnable(GL_TEXTURE_2D);
    if(ilumHab){
        glEnable(GL_LIGHTING);
    }
}
