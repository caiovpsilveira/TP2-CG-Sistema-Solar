void inicializaAstros(struct astro * vet_astros){
    int i;
    for(i=0; i < TAM_VET_ASTROS; i++){
        vet_astros[i].raio_esf = 10;
        vet_astros[i].raio_trans = i*30;
        vet_astros[i].ang_rot = 0;
        vet_astros[i].ang_trans = 0;
        vet_astros[i].vel_rot = M_PI/180;
        vet_astros[i].vel_trans = M_PI/180;
        vet_astros[i].obliquidade_orbita = M_PI/6;
        vet_astros[i].inclin_orbital = M_PI/30;
    }
}

void movimentaAstros(struct astro  * vet_astros){
    int i;
    for(i=0;i<TAM_VET_ASTROS;i++){
        vet_astros[i].ang_rot += vet_astros[i].vel_rot;
        vet_astros[i].ang_trans += vet_astros[i].vel_trans;
    }
}

void desenhaAstros(struct astro * vet_astros, int * vet_estados){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    int i;
    for(i=0;i<TAM_VET_ASTROS;i++){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, vet_astros[i].textura.id);
        glPushMatrix();

            //inclina as orbitas em relacao ao plano da terra (plano xy)
            if(vet_estados[INC_ORBITAL]){
                glRotatef(vet_astros[i].inclin_orbital*180/M_PI, 1.0, 0.0, 0.0);
            }

            //translacao da posicao dos planetas
            glTranslatef(vet_astros[i].raio_trans * cos(vet_astros[i].ang_trans), vet_astros[i].raio_trans * sin(vet_astros[i].ang_trans), 0);

            //inclinacao do eixo de rotacao em relacao ao vetor perpendicular ao plano da orbita
            if(vet_estados[OBLIQ_ORBITA]){
                glRotatef(vet_astros[i].obliquidade_orbita*180/M_PI, 0.0, 1.0, 0.0);    //inclinacao do eixo em relação a y
            }

            glRotatef(vet_astros[i].ang_rot*180/M_PI, 0.0, 0.0, 1.0);    //movimento de rotacao

            //desenhaEixosRotacao
            if(vet_estados[EIXO_ROT]){
                glClearColor(0,0,0,0);
                glDisable(GL_TEXTURE_2D);
                glDisable(GL_LIGHTING);
                glColor3f(1,1,1);
                glBegin(GL_LINES);  //eixo z
                    glVertex3f(0,0,-1.5*vet_astros[i].raio_esf);
                    glVertex3f(0,0, 1.5*vet_astros[i].raio_esf);
                glEnd();
                glEnable(GL_TEXTURE_2D);
                glEnable(GL_LIGHTING);
            }

            desenhaEsfera(vet_astros[i]);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
}

void desenhaEsfera(struct astro astro){
    glColor3f(1,1,1);
    glPushMatrix();
        //glutSolidCube(astro.raio_esf);
        solidSphere(astro.raio_esf, NUM_SLICES, NUM_STACKS);
    glPopMatrix();
}
