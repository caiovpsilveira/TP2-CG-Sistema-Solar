//aceita escrever \n. Retorna o numero de \n escritos
int escreveStringFormatada(int x, int y, char *string){
    char *c;
    int offset = 15;
    int i=0;
    int ilumHab;

    glGetIntegerv(GL_LIGHTING, &ilumHab);//GL_LIGHTING estava habilitado antes de chamar a funcao?
    glDisable(GL_LIGHTING);

    glColor3f(1,1,1);
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++){
        if(*c == '\n'){
            i++;
            glRasterPos2f(x, y+i*offset);
        }
        else{
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
        }
    }

    if(ilumHab){
        glEnable(GL_LIGHTING);
    }

    return i;
}

//escreve informacoes complementares sobre o planeta quando observador esta na CAM_ACOMPANHA
void escreverInformacoesPlaneta(int x, int y, struct astro astro){
    char str_final[50];
    char str_aux[50];
    int i=0;
    int offset = 15;

    projecaoOrto();

    strncpy(str_final, "Nome: ", 50);
    strcat(str_final, astro.nome);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nDiametro (km): ", 50);
    if(strcmp("Sol", astro.nome) == 0){  //Se e o sol
        sprintf(str_aux, "%.0f", 2*astro.raio_esf*2E3*50);  //a escala do sol e diferente dos outros planetas
    }
    else{
        sprintf(str_aux, "%.0f", 2*astro.raio_esf*2E3);
    }
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nDistancia do sol (10^6 km): ", 50);
    sprintf(str_aux, "%.0f", astro.raio_trans*2);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nObliquidade da orbita (graus): ", 50);
    sprintf(str_aux, "%.2f", astro.obliquidade_orbita*180/M_PI);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nInclinacao orbital (graus): ", 50);
    sprintf(str_aux, "%.2f", astro.inclin_orbital*180/M_PI);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nMassa (10^24kg): ", 50);
    sprintf(str_aux, "%.2f", astro.massa);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    strncpy(str_final, "\nTemperatura Media (C): ", 50);
    sprintf(str_aux, "%.2f", astro.temperatura);
    strcat(str_final, str_aux);
    i += escreveStringFormatada(x, y+i*offset, str_final);

    retornaPerspectiva();
}

//escreve na tela TELA_MENU
void escreverMenuPrincipal(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Trabalho Pratico 2\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte espaco para comecar\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte C para ver os controles\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte Z para ver os creditos\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte I para ver o que cada informacao dos planetas significa\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte ESC para sair\n");

    retornaPerspectiva();
}

//escreve na tela TELA_MENU_PAUSE
void escreveMenuPause(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Pausado\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte C para ver os controles\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte Z para ver os creditos\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte I para ver o que cada informacao dos planetas significa\n");
    i += escreveStringFormatada(x, y + i*offset, "\n\nAperte esc para voltar a tela anterior ou X para ir para o menu principal\n");

    retornaPerspectiva();
}

//escreve na tela TELA_CREDITOS
void escreveCreditos(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Creditos\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Abdul Kevin e Caio Vinicius\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Esse trabalho foi desenvolvido no ambito da \ndisciplina Computação Grafica 2021.1\n");
    i += escreveStringFormatada(x, y + i*offset, "Setembro 2021.\n\n");
    i += escreveStringFormatada(x, y + i*offset, "As texturas dos astros foram obtidas em https://www.solarsystemscope.com/textures/.\n");
    i += escreveStringFormatada(x, y + i*offset, "Os dados dos planetas foram obtidos em https://nssdc.gsfc.nasa.gov/planetary/factsheet\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Aperte esc para voltar a tela anterior\n");

    retornaPerspectiva();
}

//escreve na tela TELA_CONTROLES
void escreveControles(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset,"CONTROLES\n\n");
    i += escreveStringFormatada(x, y + i*offset,"CAMERA\n");
    i += escreveStringFormatada(x, y + i*offset,"Para ativar o controle via mouse, e necessario descomentar as funcoes na main\n");
    i += escreveStringFormatada(x, y + i*offset,"e compilar novamente. O mouse gera muitos callbacks, o que pesa na execucao.\n\n");
    i += escreveStringFormatada(x, y + i*offset,"Aperte 1, 2, 3 ou 4 para alterar a camera\n");
    i += escreveStringFormatada(x, y + i*offset,"1: camera superior, 2: camera frontal,\n3: camera livre, 4: camera acompanha planeta.\n\n");
    i += escreveStringFormatada(x, y + i*offset,"CONTROLE DE CAMERA LIVRE:\n");
    i += escreveStringFormatada(x, y + i*offset,"W A S D: movimentacao\n");
    i += escreveStringFormatada(x, y + i*offset,"Mexer o cursor / setas do teclado: mudar direcao da camera\n");
    i += escreveStringFormatada(x, y + i*offset,"MWHEEL UP / Page up: Subir camera, MWHEEL DOWN / Page down: Descer camera\n");
    i += escreveStringFormatada(x, y + i*offset,"CONTROLE DE CAMERA QUE ACOMPANHA:\n");
    i += escreveStringFormatada(x, y + i*offset,"Aperta espaco para trocar o planeta.\n\n");
    i += escreveStringFormatada(x, y + i*offset,"DENTRO DA SIMULACAO:\n");
    i += escreveStringFormatada(x, y + i*offset,"R: reiniciar simulacao\n");
    i += escreveStringFormatada(x, y + i*offset,"P: pausar simulacao\n");
    i += escreveStringFormatada(x, y + i*offset,"ESC: Ir para o menu de pause\n");
    i += escreveStringFormatada(x, y + i*offset,"L: ligar/desligar iluminacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"Z: mostrar/esconder eixos de rotacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"X: considerar/desconsiderar inclinacao orbital.\n");
    i += escreveStringFormatada(x, y + i*offset,"C: considerar/desconsiderar obliquidade da orbita.\n");
    i += escreveStringFormatada(x, y + i*offset,"O: mostrar/esconder orbitas dos planetas.\n");
    i += escreveStringFormatada(x, y + i*offset,"V: mostrar/esconder eixos ordenados do glut.\n");
    i += escreveStringFormatada(x, y + i*offset,"\n\nAperte esc para voltar a tela anterior\n");

    retornaPerspectiva();
}

//escreve na tela de informacoe extra
void escreveInformacoes(int x, int y){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Informacoes\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Diametro (km) - O diametro do planeta no equador, \na distancia atraves do centro do planeta de um ponto no \nequador ao lado oposto, em quilometros ou milhas.\n\n");
    i +=escreveStringFormatada(x, y+ i*offset,"Distancia do Sol (10^6 km) - Esta e a distancia media \ndo planeta ao Sol em milhoes de quilometros ou \nmilhoes de milhas, tambem conhecida como semi-eixo \nmaior. Todos os planetas tem orbitas elipticas, noo \nperfeitamente circulares; portanto, ha um ponto na \norbita em que o planeta esta mais proximo do Sol, o \nperielio, e um ponto mais distante do Sol, o afelio. \nA distencia media do Sol este a meio caminho entre \nesses dois valores. A distancia media da Terra ao Sol \ne definida como 1 Unidade Astronomica (UA), entao a \ntabela de razao fornece essa distancia em UA.\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Obliquidade em relacao a orbita (graus) - o angulo em \ngraus do eixo de um planeta (a linha imaginaria que \natravessa o centro do planeta dos polos norte a sul) \ne inclinado em relacaoo a uma linha perpendicular a \norbita do planeta em torno do Sol, ao norte polo \ndefinido pela regra da mao direita. Venus gira em uma \ndirecao retrograda, oposta aos outros planetas, entao \na inclinacao e de quase 180 graus, ele e considerado \ngirando com seu \"topo\", ou polo norte apontando \n\"para baixo\" (sul). Urano gira quase de lado em \nrelacao a orbita, Plutão esta apontando ligeiramente \n\"para baixo\". As relacoes com a Terra referem-se ao \neixo sem referencia ao norte ou ao sul.\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Inclinacao Orbital (graus) - O angulo em graus em que \nos planetas orbitam ao redor do Sol sao inclinados em \nrelacao ao plano da ecliptica. O plano ecliptico e \ndefinido como o plano que contem a orbita da Terra, \nentao a inclinacao da Terra e 0.\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Massa (10^24 kg ou 10^21 toneladas) - Esta e a massa do \nplaneta em setilhoes (1 seguido por 24 zeros) \nquilogramas ou sextiliones (1 seguido por 21 zeros) \ntoneladas. Estritamente falando, toneladas sao \nmedidas de peso, nao de massa, mas sao usadas aqui \npara representar a massa de uma tonelada de material \nsob a gravidade da Terra.\n\n");
    i += escreveStringFormatada(x, y + i*offset, "Temperatura media (C ou F) - Esta e a temperatura \nmedia em toda a superficie do planeta (ou para os \ngigantes gasosos no nivel de uma barra) em graus C \n(Celsius ou Centigrados) ou graus F (Fahrenheit). Para \nMercurio e a Lua, por exemplo, esta e uma media sobre \nos hemisferios iluminados pelo sol (muito quentes) e \nescuros (muito frios) e, portanto, não e \nrepresentativa de nenhuma regiao do planeta, e a \nmaior parte da superficie e bastante diferente desta \nvalor medio. Tal como acontece com a Terra, havera \ntendencia a variacoes de temperatura do equador aos \npolos, do lado diurno ao noturno, e mudancas sazonais \nna maioria dos planetas.\n\n");
    i += escreveStringFormatada(x, y + i*offset, "\n\nAperte esc para voltar a tela anterior\n");

    retornaPerspectiva();
}

//escreve na tela TELA_PLANETAS os controles de toggle de estado de desenho
void escreveHud(int x, int y, int cam_atual, int ta_pausado){
    int i=0;
    int offset = 15;

    projecaoOrto();

    i += escreveStringFormatada(x, y + i*offset, "Os planetas estao 1000x maiores, e o sol esta 50x menor.\nAs distancias entre as orbitas estao em escala 1:1.\n");

    switch(cam_atual){
        case CAM_CIMA:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera. Camera atual: Camera superior\n");
            break;
        case CAM_FRONTAL:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera. Camera atual: Camera frontal\n");
            break;
        case CAM_LIVRE:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera. Camera atual: Camera livre\n");
            break;
        case CAM_ACOMPANHA:
            i += escreveStringFormatada(x, y + i*offset, "Aperte 1, 2, 3 ou 4 para alternar a camera.\nCamera atual: Camera centrando astros. Espaco para trocar o astro.\n");
            break;
        default:
            break;
    }
    if(ta_pausado){
        i += escreveStringFormatada(x, y + i*offset,"P: pausar. PAUSADO.\n");
    }
    else{
        i += escreveStringFormatada(x, y + i*offset,"P: pausar.\n");
    }
    i += escreveStringFormatada(x, y + i*offset, "R: reiniciar.\n");
    i += escreveStringFormatada(x, y + i*offset, "H: mostrar/esconder HUD Controles.\n");
    i += escreveStringFormatada(x, y + i*offset, "L: ligar/desligar iluminacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"Z: mostrar/esconder eixos de rotacao.\n");
    i += escreveStringFormatada(x, y + i*offset,"X: considerar/desconsiderar inclinacao orbital.\n");
    i += escreveStringFormatada(x, y + i*offset,"C: considerar/desconsiderar obliquidade da orbita.\n");
    i += escreveStringFormatada(x, y + i*offset,"O: mostrar/esconder orbitas dos planetas.\n");
    i += escreveStringFormatada(x, y + i*offset,"V: mostrar/esconder eixos ordenados do glut.\n");
    i += escreveStringFormatada(x, y + i*offset,"ESC: menu de pause.\n");

    retornaPerspectiva();
}
