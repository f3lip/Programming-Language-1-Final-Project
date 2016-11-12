#include "funcionario.h"

// Construtor padrao
Funcionario::Funcionario(){
	id = 0;
	nome = "";
	cpf = "";
	idade = 0;
	tipo_sanguineo = "";
	fatorRH = 0;
	especialidade = "";
}

/**
 * @details O construtor parametrizado da classe Funcionario e utilizado para instanciar um objeto Funcionario
 * @param	i Identificacao
 * @param	n Nome 
 * @param	c CPF
 * @param 	ida Idade
 * @param	ts Tipo sanguineo
 * @param	frh fatorRH
 * @param	e Especialidade
 */
Funcionario::Funcionario(int i, string n, string c, short ida, string ts, char frh, string e)
	: id(i), nome(n), cpf(c), idade(ida), tipo_sanguineo(ts), fatorRH(frh), especialidade(e) {}

/** @return Identificacao */
int Funcionario::getId(){
	return id;
}

/** @return Nome */
string Funcionario::getNome(){
	return nome;
}

/** @return CPF */
string Funcionario::getCpf(){
	return cpf;
}

/** @return Idade */
short Funcionario::getIdade(){
	return idade;
}

/** @return Tipo sanguineo */
string Funcionario::getTipo_sanguineo(){
	return tipo_sanguineo;
}

/** @return FatorRH */
char Funcionario::getFatorRH(){
	return fatorRH;
}

/** @return Especialidade */
string Funcionario::getEspecialidade(){
	return especialidade;
}

/** @param i Valor para a identificacao */
void Funcionario::setId(int i){
	id = i;
}

/** @param n String para o nome */
void Funcionario::setNome(string n){
	nome = n;
}

/** @param c String para o CPF*/
void Funcionario::setCpf(string c){
	cpf = c;
}

/** @param ida Valor para a idade */
void Funcionario::setIdade(short ida){
	idade = ida;
}

/** @param ts String para o tipo sanguineo */
void Funcionario::setTipo_sanguineo(string ts){
	tipo_sanguineo = ts;
}

/** @param frh Char para o fatorRH */
void Funcionario::setFatorRH(char frh){
	fatorRH = frh;
}

// Construtor padrao 
Veterinario::Veterinario() : Funcionario () {}

// Construtor padrao
Tratador::Tratador() : Funcionario () {}

/**
 * @brief 	Sobrecarga do operador de insercao de dados de um stream de saida
 *		 	para impressao de campos de uma variavel classe que representa
 *		  	um funcionario
 * @param 	os Objeto representando stream de saida
 * @param 	f Variavel do tipo classe representando um funcionario
 */
ostream& operator<< (ostream &o, Funcionario &f) {
	o << "ID do funcionario: " << f.id << endl;
	o << "Nome do funcionario: " << f.nome << endl;
	o << "CPF do funcionario: " << f.cpf << endl; 
	o << "Idade do funcionario: " << f.idade << endl;
	o << "Tipo sanguineo do funcionario: " << f.tipo_sanguineo << endl;
	o << "Fator RH do funcionario: " << f.fatorRH << endl;
	o << "Especialidade do funcionario: " << f.especialidade << endl;
	return o;
}

/**
 * @brief Sobrecarga do operador de extracao de dados de um stream de entrada
 *		  para armazenamento nos respectivos campos de uma variavel que representa um funcionario
 * @param is Objeto representando stream de entrada
 * @param f Variavel do tipo classe representando um funcionario
 */
istream& operator>>(istream &is, Funcionario &f) {
	string linha, tipo_f;

	getline(is, linha);
	istringstream iss(linha);

	iss>> f.id;
	iss.ignore();
	getline(iss, tipo_f, ';');
	getline(iss, f.nome, ';');
	getline(iss, f.cpf, ';');
	iss>> f.idade;
	iss.ignore();
	getline(iss, f.tipo_sanguineo, ';');
	iss>> f.fatorRH;
	iss.ignore();
	getline(iss, f.especialidade, ';');
	
	return is;
}