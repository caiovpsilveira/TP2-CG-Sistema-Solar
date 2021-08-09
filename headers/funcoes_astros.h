void inicializaAstros(struct astro * vet_astros){
    int i;
    for(i=0; i < TAM_VET_ASTROS; i++){
        vet_astros[i].raio_esf = 10;
        vet_astros[i].raio_trans = i*30;
        vet_astros[i].ang_rot = 0;
        vet_astros[i].ang_trans = 0;
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
    int i;
    for(i=0;i<TAM_VET_ASTROS;i++){
        glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(vet_astros[i].raio_trans * cos(vet_astros[i].ang_trans), vet_astros[i].raio_trans * sin(vet_astros[i].ang_trans), 0);
            glutSolidSphere(vet_astros[i].raio_esf, NUM_SLICES, NUM_STACKS);
        glPopMatrix();
    }
}
