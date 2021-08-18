void inicializaAstros(struct astro * vet_astros){
    int i;

    strncpy(vet_astros[0].nome, "Sol", TAM_STR_ASTRO);
    strncpy(vet_astros[1].nome, "Mercurio", TAM_STR_ASTRO);
    strncpy(vet_astros[2].nome, "Venus", TAM_STR_ASTRO);
    strncpy(vet_astros[3].nome, "Terra", TAM_STR_ASTRO);
    strncpy(vet_astros[4].nome, "Marte", TAM_STR_ASTRO);
    strncpy(vet_astros[5].nome, "Jupiter", TAM_STR_ASTRO);
    strncpy(vet_astros[6].nome, "Saturno", TAM_STR_ASTRO);
    strncpy(vet_astros[7].nome, "Urano", TAM_STR_ASTRO);
    strncpy(vet_astros[8].nome, "Netuno", TAM_STR_ASTRO);

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

void desenhaEsferaAstro(struct astro astro){
    glColor3f(1,1,1);
    glPushMatrix();
        //glutSolidCube(astro.raio_esf);
        solidSphere(astro.raio_esf, NUM_SLICES, NUM_STACKS);
    glPopMatrix();
}

void desenhaAstros(struct astro * vet_astros, int * vet_estados){

    int i, ilumHab;
    glGetIntegerv(GL_LIGHTING, &ilumHab);//GL_LIGHTING estava habilitado antes de chamar a funcao?

    glColor3f(1,1,1);

    for(i=0;i<TAM_VET_ASTROS;i++){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, vet_astros[i].textura.id);
        glPushMatrix();

            //inclina as orbitas em relacao ao plano da terra (plano xy)
            if(vet_estados[INC_ORBITAL]){
                glRotatef(vet_astros[i].inclin_orbital*180/M_PI, 1.0, 0.0, 0.0);
            }

            if(vet_estados[ORBITAS]){
                desenhaOrbita(vet_astros[i]);
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
                desenhaEixoRot(vet_astros[i]);
            }

            if(i==0){   //desabilitar iluminacao sol
                glDisable(GL_LIGHTING);
            }
            desenhaEsferaAstro(vet_astros[i]);
            if(i==0 && ilumHab){
                glEnable(GL_LIGHTING);
            }
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
}
