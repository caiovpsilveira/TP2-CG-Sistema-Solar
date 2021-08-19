//setup inicial dos nomes dos astros, nao sao alterados durante a execucao
void inicializaNomes(struct astro * vet_astros){
    strncpy(vet_astros[0].nome, "Sol", TAM_STR_ASTRO);
    strncpy(vet_astros[1].nome, "Mercurio", TAM_STR_ASTRO);
    strncpy(vet_astros[2].nome, "Venus", TAM_STR_ASTRO);
    strncpy(vet_astros[3].nome, "Terra", TAM_STR_ASTRO);
    strncpy(vet_astros[4].nome, "Marte", TAM_STR_ASTRO);
    strncpy(vet_astros[5].nome, "Jupiter", TAM_STR_ASTRO);
    strncpy(vet_astros[6].nome, "Saturno", TAM_STR_ASTRO);
    strncpy(vet_astros[7].nome, "Urano", TAM_STR_ASTRO);
    strncpy(vet_astros[8].nome, "Netuno", TAM_STR_ASTRO);
}

//funcão usada para colocar os valores reais em escala aproximada
//fonte das informacoes: https://nssdc.gsfc.nasa.gov/planetary/factsheet/
void inicializaAstrosReal(struct astro * vet_astros){

    //SOL
    vet_astros[0].raio_esf = 10;
    vet_astros[0].raio_trans = 0*30;
    vet_astros[0].ang_rot = 0;
    vet_astros[0].ang_trans = 0;
    vet_astros[0].vel_rot = M_PI/180;
    vet_astros[0].vel_trans = M_PI/180;
    vet_astros[0].obliquidade_orbita = 0;
    vet_astros[0].inclin_orbital = 0;

    //MERCURIO
    vet_astros[1].raio_esf = 4;
    vet_astros[1].raio_trans = 1*30;
    vet_astros[1].ang_rot = 0;
    vet_astros[1].ang_trans = 0;
    vet_astros[1].vel_rot = M_PI/100;
    vet_astros[1].vel_trans = M_PI/60;
    vet_astros[1].obliquidade_orbita = 5.934E-4;
    vet_astros[1].inclin_orbital = 0.12217;

    //VENUS
    vet_astros[2].raio_esf = 8;
    vet_astros[2].raio_trans = 2*30;
    vet_astros[2].ang_rot = 0;
    vet_astros[2].ang_trans = 0;
    vet_astros[2].vel_rot = M_PI/-500;
    vet_astros[2].vel_trans = M_PI/90;
    vet_astros[2].obliquidade_orbita = 3.0962;
    vet_astros[2].inclin_orbital = 0.05934;

    //TERRA
    vet_astros[3].raio_esf = 8;
    vet_astros[3].raio_trans = 3*30;
    vet_astros[3].ang_rot = 0;
    vet_astros[3].ang_trans = 0;
    vet_astros[3].vel_rot = M_PI/24;
    vet_astros[3].vel_trans = M_PI/180;
    vet_astros[3].obliquidade_orbita = 0.4084;
    vet_astros[3].inclin_orbital = 0;

    //MARTE
    vet_astros[4].raio_esf = 6;
    vet_astros[4].raio_trans = 4*30;
    vet_astros[4].ang_rot = 0;
    vet_astros[4].ang_trans = 0;
    vet_astros[4].vel_rot = M_PI/24;
    vet_astros[4].vel_trans = M_PI/240;
    vet_astros[4].obliquidade_orbita = 0.4398;
    vet_astros[4].inclin_orbital = 0.03316;

    //JUPITER
    vet_astros[5].raio_esf = 10;
    vet_astros[5].raio_trans = 5*30;
    vet_astros[5].ang_rot = 0;
    vet_astros[5].ang_trans = 0;
    vet_astros[5].vel_rot = M_PI/10;
    vet_astros[5].vel_trans = M_PI/300;
    vet_astros[5].obliquidade_orbita = 0.054;
    vet_astros[5].inclin_orbital = 0.022689;

    //SATURNO
    vet_astros[6].raio_esf = 10;
    vet_astros[6].raio_trans = 6*30;
    vet_astros[6].ang_rot = 0;
    vet_astros[6].ang_trans = 0;
    vet_astros[6].vel_rot = M_PI/10;
    vet_astros[6].vel_trans = M_PI/360;
    vet_astros[6].obliquidade_orbita = 0.466;
    vet_astros[6].inclin_orbital = 0.04363;

    //URANO
    vet_astros[7].raio_esf = 10;
    vet_astros[7].raio_trans = 7*30;
    vet_astros[7].ang_rot = 0;
    vet_astros[7].ang_trans = 0;
    vet_astros[7].vel_rot = M_PI/-17;
    vet_astros[7].vel_trans = M_PI/390;
    vet_astros[7].obliquidade_orbita = 1.7069;
    vet_astros[7].inclin_orbital = 0.013962;

    //NETUNO
    vet_astros[8].raio_esf = 10;
    vet_astros[8].raio_trans = 8*30;
    vet_astros[8].ang_rot = 0;
    vet_astros[8].ang_trans = 0;
    vet_astros[8].vel_rot = M_PI/16;
    vet_astros[8].vel_trans = M_PI/420;
    vet_astros[8].obliquidade_orbita = 0.493928;
    vet_astros[8].inclin_orbital = 0.031411;

}

//inicializa os astros usando parametros arbitrarios e iguais para todos
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

//funcao de update da posicao e do angulo de rotacao
void movimentaAstros(struct astro  * vet_astros){
    int i;
    for(i=0;i<TAM_VET_ASTROS;i++){
        vet_astros[i].ang_rot += vet_astros[i].vel_rot;
        vet_astros[i].ang_trans += vet_astros[i].vel_trans;
    }
}

//desenha a esfera de raio raio_esf
void desenhaEsferaAstro(struct astro astro){
    glColor3f(1,1,1);
    glPushMatrix();
        //glutSolidCube(astro.raio_esf);
        solidSphere(astro.raio_esf, NUM_SLICES, NUM_STACKS);
    glPopMatrix();
}

//funcao de desenhar os astros e outros parametros relacionados, informados por vet_estados
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

            //desenha as orbitas circulares dos planetas
            if(vet_estados[ORBITAS]){
                desenhaOrbita(vet_astros[i]);
            }

            //translacao da posicao dos planetas
            glTranslatef(vet_astros[i].raio_trans * cos(vet_astros[i].ang_trans), vet_astros[i].raio_trans * sin(vet_astros[i].ang_trans), 0);

            //inclinacao do eixo de rotacao em relacao ao vetor perpendicular ao plano da orbita
            if(vet_estados[OBLIQ_ORBITA]){
                glRotatef(vet_astros[i].obliquidade_orbita*180/M_PI, 0.0, 1.0, 0.0);    //inclinacao do eixo em rela��o a y
            }

            //movimento de rotacao
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
