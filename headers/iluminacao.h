inicializaIluminacao(){

    float d=1.0;    // Intensidade da cor difusa da luz branca
    float e=1.0;    // Intensidade da cor especular da luz branca
    float m=0.2;    // Intensidade da luz ambiente global
    float p=1.0;    // A luz branca é posicional?
    int localViewer = 0;    //a luz e local?

    float s = 50.0;    // Expoente especular do material (shininess)
    float matShine[] = { s };

    //luz
    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
	float lightDif0[] = { d, d, d, 1.0 };
	float lightSpec0[] = { e, e, e, 1.0 };
	float lightPos0[] = { 0.0, 0.0, 20.0, p };
    float globAmb[] = { m, m, m, 1.0 };

    // Propriedades da fonte de luz LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);        // Luz ambiente global
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, localViewer);// Enable local viewpoint

    //material
    // Propriedades do material da esfera
    float matAmbAndDif[] = {1.0, 1.0, 1.0, 1.0};    // cor ambiente e difusa: branca
    float matSpec[] = { 1.0, 1.0, 1,0, 1.0 };       // cor especular: branca

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

	//estados glut
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}
