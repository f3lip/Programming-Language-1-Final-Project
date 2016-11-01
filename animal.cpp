#include "animal.h"

Animal::Animal(){
	id = 0;
	classe = "";
	nome = "";
	cientifico = "";
	sexo = "";
	tamanho = 0.0;
	dieta = "";
	batismo = "";
}

Animal::Animal(int i, string c, string n, string cien, char s, float t, string d, string b)
	: id(i), classe(c), nome(n), cientifico(cien), sexo(s), tamanho(t), dieta(d), batismo(b) {}

int Animal::getId(){
	return id;
}
string Animal::getClasse(){
	return classe;
}

string Animal::getNome(){
	return nome;
}

string Animal::getCientifico(){
	return cientifico;
}

char Animal::getSexo(){
	return sexo;
}

float Animal::getTamanho(){
	return tamanho;
}

string Animal::getDieta(){
	return dieta;
}

string Animal::getBatismo(){
	return batismo;
}

void Animal::setId(int i){
	id = i;
}

void Animal::setClasse(string c){
	classe = c;
}

void Animal::setNome(string n){
	nome = n;
}

void Animal::setCientifico(string cien){
	cientifico = cien;
}

void Animal::setSexo(char s){
	sexo = s;
}

void Animal::setTamanho(float t){
	tamanho = t;
}

void Animal::setDieta(string d){
	dieta = d;
}

void Animal::setBatismo(string b){
	batismo = b;
}

Anfibio::Anfibio(){
	total_mudas = 0;
	ultimo_muda = "";
}

Anfibio::Anfibio(int tot, string u)
	: total_mudas(tot), ultimo_muda(u) {}

int Anfibio::getTotal_mudas(){
	return total_mudas;
}

string Anfibio::getUltimo_muda(){
	return ultimo_muda;
}

void Anfibio::setTotal_mudas(int tot){
	total_mudas = tot;
}

void Anfibio::setUltimo_muda(string u){
	ultimo_muda = u;
}

Mamiforo::Mamiforo(){
	cor_pelo = "";
}

Mamiforo::Mamiforo(string cor)
	: cor_pelo(cor) {}

string Mamiforo::getCor_pelo(){
	return cor_pelo;
}

void Mamiforo::setCor_pelo(string cor){
	cor_pelo = cor;
}

Reptil::Reptil(){
	v = false;
	tipo = "";
}

Reptil::Reptil(bool v, string tipo)
	: venenoso(v), tipo_veneno(tipo) {}

bool Reptil::getVenenoso(){
	return venenoso;
}
string Reptil::getTipo_veneno(){
	return tipo_veneno;
}

void Reptil::setVenenoso(bool v){
	venenoso = v;
}

void Reptil::setTipo_veneno(string tipo){
	tipo_veneno = tipo;
}

Ave::Ave(){
	tamanho_bico = 0;
	envergadura = 0;
}

Ave::Ave(int tam, int env)
	: tamanho_bico(tam), envergadura(env) {}

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

Nativo::Nativo(string uf, string aut)
	: uf_origem(uf), autorizacao(aut) {}

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

Exotico::Exotico(string pais)
	: pais_origem(pais) {}

string Exotico::getPais_origem(){
	return pais_origem;
}

void Exotico::setPais_origem(string pais){
	pais_origem = pais;
}