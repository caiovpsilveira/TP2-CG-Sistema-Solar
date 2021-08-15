void solidSphere(int radius, int stacks, int columns){
    // cria uma qu�drica
    GLUquadric* quadObj = gluNewQuadric();
    // estilo preenchido... poderia ser GLU_LINE, GLU_SILHOUETTE
    // ou GLU_POINT
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    // chama 01 glNormal para cada v�rtice.. poderia ser
    // GLU_FLAT (01 por face) ou GLU_NONE
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    // chama 01 glTexCoord por v�rtice
    gluQuadricTexture(quadObj, GL_TRUE);
    // cria os v�rtices de uma esfera
    gluSphere(quadObj, radius, stacks, columns);
    // limpa as vari�veis que a GLU usou para criar
    // a esfera
    gluDeleteQuadric(quadObj);
}

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

void desenhaEsfera(struct astro astro){
    glColor3f(1,1,1);
    glPushMatrix();
        //glutSolidCube(astro.raio_esf);
        solidSphere(astro.raio_esf, NUM_SLICES, NUM_STACKS);
    glPopMatrix();
}
