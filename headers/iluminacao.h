void inicializaIluminacao(){

    float matShine[] = {50.0};                       // expoente especular (shininess)
    float matAmbAndDif[] = {1.0, 1.0, 1.0, 1.0};    // cor ambiente e difusa: branca
    float matSpec[] = { 1.0, 1.0, 1,0, 1.0 };       // cor especular: branca

    float lightAmb[] = {0.0, 0.0, 0.0, 1.0 };
    float lightDif0[] = { 1.0, 1.0, 1.0, 1.0 };
    float lightSpec0[] = { 1.0, 1.0, 1.0, 1.0 };
    float lightPos0[] = { 0.0, 0.0, 0.0, 1 }; //ultimo parametro: posicional :1 ou direcional:0
    float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };
    int localViewer = 1;    //0: specular em direcao ao eixo z, outro: em direcao ao sistema do observador

    // Definindo as propriedades do material
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

    // Propriedades da fonte de luz LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, localViewer);// Enable local viewpoint

	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}
