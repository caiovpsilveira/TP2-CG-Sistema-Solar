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
    // limpa as variáveis que a GLU usou para criar
    // a esfera
    gluDeleteQuadric(quadObj);
}

void desenhaEixosOrdenados(){
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

    glEnable(GL_LIGHTING);
}
