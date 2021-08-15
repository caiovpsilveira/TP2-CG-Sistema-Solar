//funcões astros
void inicializaAstros(struct astro * vet_astros);
void movimentaAstros(struct astro  * vet_astros);
void desenhaAstros(struct astro * vet_astros, int * vet_estados);
void desenhaEsfera(struct astro astro);
//funcões desenho
void solidSphere(int radius, int stacks, int columns);
void desenhaEixosOrdenados();
//funcoes diversas
void normalizarVetor2D(float * vetor2D);
void normalizarVetor3D(float * vetor3D);
void imprimirInstrucoesConsole();
GLuint carregaTextura(const char* caminho);
void inicializarTexturas(struct astro * vet_astros);
void inicializaVetEstados(int * vet_estados);
//funcões observador 
void inicializaObservador(struct observador * obs);
void limitarAngulosObservador(struct observador * obs);
void corrigirUpVectorObservador(struct observador * obs);
void atualizarObservador(struct observador * obs);

//Iluminação
int  inicializaIluminacao();

//main
void setup();
void inicializaTudo();
void desenhaMinhaCena();
void atualizaCena(int valorQualquer);
void redimensionar(int width, int height);
void teclaPressionada(unsigned char key, int x, int y);
void posicionaCamera(int x, int y);
void rodaMouse(int button, int dir, int x, int y);