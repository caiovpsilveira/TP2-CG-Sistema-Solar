int inicializaIluminacao(){

    float matShine[] = {50.0};                       // expoente especular (shininess)
    float matAmbAndDif[] = {1.0, 1.0, 1.0, 1.0};    // cor ambiente e difusa: branca
    float matSpec[] = { 1.0, 1.0, 1,0, 1.0 };       // cor especular: branca

    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
    float lightDif0[] = { 1.0, 1.0, 1.0, 1.0 };
    float lightSpec0[] = { 1.0, 1.0, 1.0, 1.0 };
    float lightPos0[] = { 0.0, 0.0, 20, 0 }; //ultimo parametro: posicional ou direcional
    float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

    // Definindo as propriedades do material
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

    // Propriedades da fonte de luz LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}
