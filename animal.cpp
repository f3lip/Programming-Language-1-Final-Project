#include "animal.h"

// Construtor padrao
Animal::Animal(){
	id = 0;
	classe = "";
	nome = "";
	cientifico = "";
	sexo = 0;
	tamanho = 0.0;
	dieta = "";
	batismo = "";
}

/**
 * @details O construtor parametrizado da classe Animal e utilizado para instanciar um objeto Animal
 * @param	i Identificacao
 * @param	c Classe do animal
 * @param	n Nome do animal
 * @param 	cien Nome cientifico
 * @param	s Sexo
 * @param	t Tamanho
 * @param	d Dieta
 * @param	b Batismo
 */
Animal::Animal(int i, string c, string n, string cien, char s, float t, string d, string b)
	: id(i), classe(c), nome(n), cientifico(cien), sexo(s), tamanho(t), dieta(d), batismo(b) {}

// Destrutor padrao
Animal::~Animal() {}

/** @return Identificacao */
int Animal::getId(){
	return id;
}

/** @return Classe */
string Animal::getClasse(){
	return classe;
}

/** @return Nome */
string Animal::getNome(){
	return nome;
}

/** @return Nome cientifico */
string Animal::getCientifico(){
	return cientifico;
}

/** @return Sexo */
char Animal::getSexo(){
	return sexo;
}

/** @return Tamanho */
float Animal::getTamanho(){
	return tamanho;
}

/** @return Dieta */
string Animal::getDieta(){
	return dieta;
}

/** @return Nome de batismo */
string Animal::getBatismo(){
	return batismo;
}

/** @param i Valor para a identificacao */
void Animal::setId(int i){
	id = i;
}

/** @param i Valor para a classe */
void Animal::setClasse(string c){
	classe = c;
}

/** @param n Valor para o nome */
void Animal::setNome(string n){
	nome = n;
}

/** @param cien Valor para o nome cientifico */
void Animal::setCientifico(string cien){
	cientifico = cien;
}

/** @param t Valor para o tamanho */
void Animal::setTamanho(float t){
	tamanho = t;
}

/** @param d Valor para a dieta */
void Animal::setDieta(string d){
	dieta = d;
}

/** @param b Valor para o nome de batismo */
void Animal::setBatismo(string b){
	batismo = b;
}

// Construtor padrao
Anfibio::Anfibio(){
	total_mudas = 0;
	ultima_muda = "";
}

/**
 * @details O construtor parametrizado da classe Anfibio e utilizado para instanciar um objeto Anfibio
 * @param	tot Total de mudas
 * @param	u Data da ultima muda
 */
Anfibio::Anfibio(int i, string c, string n, string cien, char s, float t, string d, string b, int tot, string u)
	: Animal(i, c, n, cien, s, t, d, b), total_mudas(tot), ultima_muda(u) {}

// Destrutor padrao
Anfibio::~Anfibio() {}

int Anfibio::getTotal_mudas(){
	return total_mudas;
}

string Anfibio::getUltima_muda(){
	return ultima_muda;
}

void Anfibio::setTotal_mudas(int tot){
	total_mudas = tot;
}

void Anfibio::setUltima_muda(string u){
	ultima_muda = u;
}

Sapo::Sapo() : Anfibio() {}

Sapo::Sapo(int i, string c, string n, string cien, char s, float t, string d, string b, int tot, string u):
	Anfibio(i, c, n, cien, s, t, d, b, tot, u){}

void Sapo::setSexo(char s){
	sexo = s;
}

Mamifero::Mamifero(){
	cor_pelo = "";
}

/**
 * @details O construtor parametrizado da classe Mamifero e utilizado para instanciar um objeto Mamifero
 * @param	cor Cor do pelo
 */
Mamifero::Mamifero(int i, string c, string n, string cien, char s, float t, string d, string b, string cor)
	: Animal(i, c, n, cien, s, t, d, b), cor_pelo(cor) {}

string Mamifero::getCor_pelo(){
	return cor_pelo;
}

void Mamifero::setCor_pelo(string cor){
	cor_pelo = cor;
}

Leao::Leao() : Mamifero() {}

Leao::Leao(int i, string c, string n, string cien, char s, float t, string d, string b, string cor):
	Mamifero(i, c, n, cien, s, t, d, b, cor){}

void Leao::setSexo(char s){
	sexo = s;
}

Reptil::Reptil(){
	venenoso = false;
	tipo_veneno = "";
}

/**
 * @details O construtor parametrizado da classe Reptil e utilizado para instanciar um objeto Reptil
 * @param	ven Identifica se o animal e venenoso
 * @param	tipo Indica o tipo de veneno do animal
 */
Reptil::Reptil(int i, string c, string n, string cien, char s, float t, string d, string b, bool ven, string tipo)
	: Animal(i, c, n, cien, s, t, d, b), venenoso(ven), tipo_veneno(tipo) {}

bool Reptil::getVenenoso(){
	return venenoso;
}
string Reptil::getTipo_veneno(){
	return tipo_veneno;
}

void Reptil::setVenenoso(bool ven){
	venenoso = ven;
}

void Reptil::setTipo_veneno(string tipo){
	tipo_veneno = tipo;
}

Tartaruga::Tartaruga() : Reptil() {}

Tartaruga::Tartaruga(int i, string c, string n, string cien, char s, float t, string d, string b, bool ven, string tipo)
	: Reptil(i, c, n, cien, s, t, d, b, ven, tipo) {}

void Tartaruga::setSexo(char s){
	sexo = s;
}

Ave::Ave(){
	tamanho_bico = 0;
	envergadura = 0;
}


/**
 * @details O construtor parametrizado da classe Animal e utilizado para instanciar um objeto Animal
 * @param	tam Tamanho do bico
 * @param	env Tamanho da envergadura
 */
Ave::Ave(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env)
	: Animal(i, c, n, cien, s, t, d, b), tamanho_bico(tam), envergadura(env) {}

Ave::~Ave() {}

int Ave::getTamanho_bico(){
	return tamanho_bico;
}

int Ave::getEnvergadura(){
	return envergadura;
}

void Ave::setTamanho_bico(int tam){
	tamanho_bico = tam;
}

void Ave::setEnvergadura(int env){
	envergadura = env;
}

AnimalSilvestre::AnimalSilvestre(){
	ibama = "";
}

AnimalSilvestre::AnimalSilvestre(string ib)
	: ibama(ib) {}

AnimalSilvestre::~AnimalSilvestre() {}

string AnimalSilvestre::getIbama(){
	return ibama;
}

void AnimalSilvestre::setIbama(string ib){
	ibama = ib;
}

Nativo::Nativo(){
	uf_origem = "";
	autorizacao = "";
}

Nativo::Nativo(string ib, string uf, string aut)
	: AnimalSilvestre(ib), uf_origem(uf), autorizacao(aut) {}

Nativo::~Nativo() {}

string Nativo::getUf_origem(){
	return uf_origem;
}

string Nativo::getAutorizacao(){
	return autorizacao;
}

void Nativo::setUf_origem(string uf){
	uf_origem = uf;
}

void Nativo::setAutorizacao(string aut){
	autorizacao = aut;
}

Exotico::Exotico(){
	pais_origem = "";
}

Exotico::Exotico(string ib, string pais)
	: AnimalSilvestre(ib), pais_origem(pais) {}

Exotico::~Exotico() {}

string Exotico::getPais_origem(){
	return pais_origem;
}

void Exotico::setPais_origem(string pais){
	pais_origem = pais;
}

AveNativa::AveNativa() : Ave(), Nativo() {}

AveNativa::~AveNativa() {}

AveNativa::AveNativa(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string uf, string aut)
	: Ave(i, c, n, cien, s, t, d, b, tam, env), Nativo(ib, uf, aut) {}

AraraAzul::AraraAzul() : AveNativa() {}

AraraAzul::AraraAzul(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string uf, string aut)
	: AveNativa(i, c, n, cien, s, t, d, b, tam, env, ib, uf, aut) {}

void AraraAzul::setSexo(char s){
	sexo = s;
}

AveExotica::AveExotica() : Ave(), Exotico() {}

AveExotica::~AveExotica() {}

AveExotica::AveExotica(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string pais)
	: Ave(i, c, n, cien, s, t, d, b, tam, env), Exotico(ib, pais) {}

Pavao::Pavao() : AveExotica () {}

Pavao::Pavao(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string pais)
	: AveExotica(i, c, n, cien, s, t, d, b, tam, env, ib, pais) {}

void Pavao::setSexo(char s){
	sexo = s;
}