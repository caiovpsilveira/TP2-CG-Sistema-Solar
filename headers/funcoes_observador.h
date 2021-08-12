void inicializaObservador(struct observador * obs){
    obs->theta = M_PI_4;
    obs->phi = 3*M_PI_2;
    obs->velocidade = 5;
    obs->xpos = 300;
    obs->ypos = 300;
    obs->zpos = 0;
    obs->upz=1;
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

void corrigirUpVectorObservador(struct observador * obs){
    if(obs->phi>=0 && obs->phi<M_PI){
        obs->upz=-1;
    }
    else{
        obs->upz=1;
    }
}

void atualizarObservador(struct observador * obs){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obs->xpos, obs->ypos, obs->zpos, obs->xpos+sin(obs->phi)*cos(obs->theta),obs->ypos+sin(obs->phi)*sin(obs->theta),obs->zpos+cos(obs->phi), 0,0, obs->upz);
    glutPostRedisplay();
}
