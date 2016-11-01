#include "funcionario.h"

Funcionario::Funcionario(){
	idade = 0;
	nome = "";
	cpf = "";
	idade = 0;
	tipo_sanguineo = 0;
	fatorRH = 0;
	especialidade = "";
}

Funcionario::Funcionario(int i, string n, string c, short ida, short ts, char f, string e)
	: id(i), nome(n), cpf(c), idade(ida), tipo_sanguineo(ts), fatorRH(f), especialidade(e) {}

int Funcionario::getId(){
	return id;
}

string Funcionario::getNome(){
	return nome;
}

string Funcionario::getCpf(){
	return cpf;
}

short Funcionario::getIdade(){
	return idade;
}

short Funcionario::getTipo_sanguineo(){
	return tipo_sanguineo;
}

char Funcionario::getFatorRH(){
	return fatorRH;
}

string Funcionario::getEspecialidade(){
	return especialidade;
}

void Funcionario::setId(int i){
	id = i;
}

void Funcionario::setNome(string n){
	nome = n;
}

void Funcionario::setCpf(string c){
	cpf = c;
}

void Funcionario::setIdade(short ida){
	idade = ida;
}

void Funcionario::setTipo_sanguineo(short ts){
	tipo_sanguineo = ts;
}

void Funcionario::setFatorRH(char f){
	fatorRH = f;
}

void Funcionario::setEspecialidade(string e){
	especialidade = e;
}

ostream& operator<< (std::ostream &o, Funcionario const f) {
	o << "ID do funcionario: " << f.id << endl << "Nome do funcionario: " << f.nome << endl << "CPF do funcionario: " << f.cpf << endl 
	<< "Idade do funcionario: " << f.idade << endl << "Tipo sanguineo do funcionario: " << f.tipo_sanguineo << endl << "Fator RH do funcionario: " << f.fatorRH << endl
	<< "Especialidade do funcionario: " << f.especialidade << endl; ;
	return o;
}