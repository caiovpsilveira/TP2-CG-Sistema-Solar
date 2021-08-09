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
    printf("CONTROLE DE CAMERA:\n");
    printf("W A S D: movimentacao\n");
    printf("Mexer o cursor: mudar direcao da camera\n");
    printf("MWHEEL UP: Subir camera, MWHEEL DOWN: Descer camera\n\n");
    printf("CONTROLES:\n");
    printf("R: reiniciar simulacao\n");
    printf("P: pausar simulacao\n");
    printf("ESC: tela menu\n");
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
