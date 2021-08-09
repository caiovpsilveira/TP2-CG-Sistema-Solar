struct textura {
    GLuint id;
    char nome_arquivo[50];
};

struct astro{
    float raio_esf; //tamanho da esfera
    float raio_trans;
    float ang_rot;
    float ang_trans;    //considerando uma trajetoria circular
    float vel_rot; //velocidade angular de rotação (radianos)
    float vel_trans;    //velocidade angular de rotação (radianos)
    struct textura textura;
};

struct observador{
    float theta;    //coordenadas polares
    float phi;
    float velocidade;
    float xpos;
    float ypos;
    float zpos;
    int upz;
};
