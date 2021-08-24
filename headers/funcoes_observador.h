void inicializaObservadores(struct observador * obs){
    obs[CAM_CIMA].theta = 0;
    obs[CAM_CIMA].phi = M_PI;
    obs[CAM_CIMA].velocidade = 0;
    obs[CAM_CIMA].xpos = 0;
    obs[CAM_CIMA].xpos = 0;
    obs[CAM_CIMA].zpos = 500;
    obs[CAM_CIMA].upz=1;

    obs[CAM_FRONTAL].theta = 0;
    obs[CAM_FRONTAL].phi = 3*M_PI_2;
    obs[CAM_FRONTAL].velocidade = 0;
    obs[CAM_FRONTAL].xpos = 300;
    obs[CAM_FRONTAL].xpos = 300;
    obs[CAM_FRONTAL].zpos = 0;
    obs[CAM_FRONTAL].upz=1;

    obs[CAM_LIVRE].theta = M_PI_4;
    obs[CAM_LIVRE].phi = 3*M_PI_2;
    obs[CAM_LIVRE].velocidade = 5;
    obs[CAM_LIVRE].xpos = 300;
    obs[CAM_LIVRE].ypos = 300;
    obs[CAM_LIVRE].zpos = 0;
    obs[CAM_LIVRE].upz=1;

    obs[CAM_ACOMPANHA].theta = 0;
    obs[CAM_ACOMPANHA].phi = M_PI;
    obs[CAM_ACOMPANHA].velocidade = 0;
    obs[CAM_ACOMPANHA].upz=1;
}

void limitarAngulosObservador(struct observador * obs){
    if(obs->phi >= 2*M_PI){
        obs->phi-=2*M_PI;
    }
    else if(obs->phi < 0){
        obs->phi+= 2*M_PI;
    }

    if(obs->theta >= 2*M_PI){
            obs->theta-=2*M_PI;
    }
    else if(obs->theta < 0){
        obs->theta+= 2*M_PI;
    }
}

//possibilitar que o observador vire de "ponta-cabeca"
void corrigirUpVectorObservador(struct observador * obs){
    if(obs->phi>=0 && obs->phi<M_PI){
        obs->upz=-1;
    }
    else{
        obs->upz=1;
    }
}

//atualiza a funcao gluLookAt com as novas coordenadas e angulos de obs
void atualizarObservador(struct observador obs){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obs.xpos, obs.ypos, obs.zpos, obs.xpos+sin(obs.phi)*cos(obs.theta),obs.ypos+sin(obs.phi)*sin(obs.theta),obs.zpos+cos(obs.phi), 0,0, obs.upz);
    glutPostRedisplay();
}

//atualizaz a posicao do observador para corresponder a posicao acima do planeta
void atualizaCamAcompanha(struct astro * vet_astros, struct observador * obs, int n_astro, int * vet_estados){
    if(vet_estados[INC_ORBITAL]){
        obs->xpos = vet_astros[n_astro].raio_trans * cos(vet_astros[n_astro].ang_trans);
        obs->ypos = vet_astros[n_astro].raio_trans * sin(vet_astros[n_astro].ang_trans) * cos(vet_astros[n_astro].inclin_orbital);
        obs->zpos = vet_astros[n_astro].raio_trans * sin(vet_astros[n_astro].inclin_orbital) * sin(vet_astros[n_astro].ang_trans) + 6*vet_astros[n_astro].raio_esf;
    }
    else{
        obs->xpos = vet_astros[n_astro].raio_trans * cos(vet_astros[n_astro].ang_trans);
        obs->ypos = vet_astros[n_astro].raio_trans * sin(vet_astros[n_astro].ang_trans);
        obs->zpos = 6*vet_astros[n_astro].raio_esf;
    }
}
