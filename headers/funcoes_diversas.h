void normalizarVetor2D(float * vetor2D){
    float norma = sqrt(vetor2D[0]*vetor2D[0] + vetor2D[1]*vetor2D[1]);
    vetor2D[0] = vetor2D[0]/norma;
    vetor2D[1] = vetor2D[1]/norma;
}

void normalizarVetor3D(float * vetor3D){
    float norma = sqrt(vetor3D[0]*vetor3D[0] + vetor3D[1]*vetor3D[1] + vetor3D[2]*vetor3D[2]);
    vetor3D[0] = vetor3D[0]/norma;
    vetor3D[1] = vetor3D[1]/norma;
    vetor3D[2] = vetor3D[2]/norma;
}

void imprimirInstrucoesConsole(){
    printf("Aperte 1, 2, 3 ou 4para alterar a camera\n");
    printf("1: camera \"superior\", 2: camera \"frontal\", 3: camera livre, 4: camera que acompanha o planeta.\n\n");
    printf("CONTROLE DE CAMERA LIVRE:\n");
    printf("W A S D: movimentacao\n");
    printf("Mexer o cursor: mudar direcao da camera\n");
    printf("MWHEEL UP: Subir camera, MWHEEL DOWN: Descer camera\n\n");
    printf("CONTROLE DE CAMERA QUE ACOMPANHA:\n");
    printf("Aperta espaco para trocar o planeta.\n\n");
    printf("CONTROLES:\n");
    printf("R: reiniciar\n");
    printf("P: pausar\n");
    printf("ESC: tela menu\n");
    printf("L: ligar/desligar iluminacao.\n");
    printf("Z: mostrar/esconder eixos de rotacao.\n");
    printf("X: considerar/desconsiderar inclinacao orbital.\n");
    printf("C: considerar/desconsiderar obliquidade da orbita.\n");
    printf("V: mostrar/esconder eixos ordenados do glut.\n");
}

GLuint carregaTextura(const char* caminho){
    GLuint idTextura = SOIL_load_OGL_texture(
                           caminho,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                       );

    if (idTextura == 0){
        printf("Erro do SOIL ao carregar %s: '%s'\n", caminho, SOIL_last_result());
    }

    return idTextura;
}

//https://www.solarsystemscope.com/textures/
void inicializarTexturas(struct astro * vet_astros){

    int i;

    strncpy(vet_astros[0].textura.nome_arquivo, "texturas/textura_sol.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[1].textura.nome_arquivo, "texturas/textura_mercurio.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[2].textura.nome_arquivo, "texturas/textura_venus.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[3].textura.nome_arquivo, "texturas/textura_terra.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[4].textura.nome_arquivo, "texturas/textura_marte.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[5].textura.nome_arquivo, "texturas/textura_jupiter.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[6].textura.nome_arquivo, "texturas/textura_saturno.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[7].textura.nome_arquivo, "texturas/textura_urano.jpg", TAM_STRING_ARQUIVO);
    strncpy(vet_astros[8].textura.nome_arquivo, "texturas/textura_netuno.jpg", TAM_STRING_ARQUIVO);

    for(i=0; i<TAM_VET_ASTROS; i++){
        vet_astros[i].textura.id = carregaTextura(vet_astros[i].textura.nome_arquivo);
    }
}

void inicializaVetEstados(int * vet_estados){
    vet_estados[EIXOS_ORDEN] = 0;
    vet_estados[EIXO_ROT] = 1;
    vet_estados[INC_ORBITAL] = 1;
    vet_estados[OBLIQ_ORBITA] = 1;
    vet_estados[ORBITAS] = 1;
}
