//FUNCOES ASTROS
void inicializaAstros(struct astro * vet_astros);

void movimentaAstros(struct astro  * vet_astros);

void desenhaAstros(struct astro * vet_astros, int * vet_estados);

//FUNCOES OBSERVADOR
void inicializaObservadores(struct observador * obs);

void limitarAngulosObservador(struct observador * obs);

void corrigirUpVectorObservador(struct observador * obs);

void atualizarObservador(struct observador obs);

void atualizaCamAcompanha(struct astro * vet_astros, struct observador * obs, int n_astro, int * vet_estados);

//ILUMINACAO
void inicializaIluminacao();

//FUNCOES DESENHO
void solidSphere(int radius, int stacks, int columns);

void desenhaEixosOrdenados();

void desenhaEsfera(struct astro astro);

//FUNCOES DIVERSAS
void normalizarVetor2D(float * vetor2D);

void normalizarVetor3D(float * vetor3D);

void imprimirInstrucoesConsole();

GLuint carregaTextura(const char* caminho);

void inicializarTexturas(struct astro * vet_astros);

void inicializaVetEstados(int * vet_estados);
