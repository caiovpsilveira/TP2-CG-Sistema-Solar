struct textura {
    GLuint id;
    char nome_arquivo[50];
};

//obs: os angulos estao em radianos
//as funcoes sin e cos recebem em radianos
//a funcao glRotatef recebe em graus

// 1 grau = M_PI rad /180;
//1 rad = 180 graus /M_PI;

struct astro{
    float raio_esf; //tamanho da esfera
    float raio_trans;
    float ang_rot;
    float ang_trans;    //considerando uma trajetoria circular
    float vel_rot; //velocidade angular de rotação (radianos)
    float vel_trans;    //velocidade angular de rotação (radianos)
    float inclin_orbital;  //diferenca entre o plano que contem a orbita do planeta e o plano que contem a orbita da terra
    float obliquidade_orbita; //diferenca entre o eixo de rotacao do planeta e o vetor perpendicular ao plano que contem sua orbita.
    struct textura textura;
};

struct observador{
    float theta;    //coordenadas polares
    float phi;
    float velocidade;   //se a velocidade for 0, a camera sera fixa em um ponto, e so poder olhar em volta
    float xpos;
    float ypos;
    float zpos;
    int upz;
};
