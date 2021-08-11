void inicializaAstros(struct astro * vet_astros){
    int i;
    for(i=0; i < TAM_VET_ASTROS; i++){
        vet_astros[i].raio_esf = 10;
        vet_astros[i].raio_trans = i*30;
        vet_astros[i].ang_rot = 0;  //radianos
        vet_astros[i].ang_trans = 0;    //radianos
        vet_astros[i].vel_rot = M_PI/180;   //1 grau por frame
        vet_astros[i].vel_trans = M_PI/180;
    }
}

void movimentaAstros(struct astro  * vet_astros){
    int i;
    for(i=0;i<TAM_VET_ASTROS;i++){
        vet_astros[i].ang_rot += vet_astros[i].vel_rot;
        vet_astros[i].ang_trans += vet_astros[i].vel_trans;
    }
}

void desenhaAstros(struct astro * vet_astros){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    int i;
    for(i=0;i<TAM_VET_ASTROS;i++){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, vet_astros[i].textura.id);
        glPushMatrix();
            glColor3f(1,1,1);
            glTranslatef(vet_astros[i].raio_trans * cos(vet_astros[i].ang_trans), vet_astros[i].raio_trans * sin(vet_astros[i].ang_trans), 0);
            glRotatef(vet_astros[i].ang_rot*180, 0, 0, 1.0);    //a funcao glRotate recebe em graus
            desenhaEsfera(vet_astros[i]);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
}

void desenhaEsfera(struct astro astro){
    glPushMatrix();
        //glutSolidSphere(astro.raio_esf, NUM_SLICES, NUM_STACKS);
        //glutSolidCube(astro.raio_esf);
        solidSphere(astro.raio_esf, NUM_SLICES, NUM_STACKS);
    glPopMatrix();
}
