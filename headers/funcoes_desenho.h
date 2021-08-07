void desenhaAstros(struct astro * vet_astros){
    int i;
    for(i=0;i<TAM_VET_ASTROS;i++){
        glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(vet_astros[i].raio_trans * cos(vet_astros[i].ang_trans), vet_astros[i].raio_trans * sin(vet_astros[i].ang_trans), 0);
            glutSolidSphere(vet_astros[i].raio_esf, NUM_SLICES, NUM_STACKS);
        glPopMatrix();
    }
}

void desenhaEixos(){
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
}
