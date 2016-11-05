#include "funcionario.h"

Funcionario::Funcionario(){
	idade = 0;
	nome = "";
	cpf = "";
	idade = 0;
	tipo_sanguineo = "";
	fatorRH = 0;
	especialidade = "";
}

Funcionario::Funcionario(int i, string n, string c, short ida, string ts, char frh, string e)
	: id(i), nome(n), cpf(c), idade(ida), tipo_sanguineo(ts), fatorRH(frh), especialidade(e) {}

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

string Funcionario::getTipo_sanguineo(){
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

void Funcionario::setTipo_sanguineo(string ts){
	tipo_sanguineo = ts;
}

void Funcionario::setFatorRH(char frh){
	fatorRH = frh;
}

void Funcionario::setEspecialidade(string e){
	especialidade = e;
}

Veterinario::Veterinario() : Funcionario () {}

Veterinario::Veterinario (int i, string n, string c, short ida, string ts, char frh, string e) : Funcionario (i, n, c, ida, ts, frh, e) {}

ostream& operator<< (ostream &o, Funcionario f) {
	o << "ID do funcionario: " << f.id << endl;
	o << "Nome do funcionario: " << f.nome << endl;
	o << "CPF do funcionario: " << f.cpf << endl; 
	o << "Idade do funcionario: " << f.idade << endl;
	o << "Tipo sanguineo do funcionario: " << f.tipo_sanguineo << endl;
	o << "Fator RH do funcionario: " << f.fatorRH << endl;
	o << "Especialidade do funcionario: " << f.especialidade << endl;
	return o;
}

istream& operator>>(istream &is, Funcionario &f) {
	string linha, tipo_f;
	int i;

	getline(is, linha);
	istringstream iss(linha);

	iss >> i;
	iss.ignore();
	getline(iss, tipo_f, ';');
	
	if(tipo_f == "Veterinario"){
		f = new Veterinario;
		f->id = i;
		getline(iss, f->nome, ';');
		getline(iss, f->cpf, ';');
		iss >> f->idade;
		iss.ignore();
		getline(iss, f->tipo_sanguineo, ';');
		iss >> f->fatorRH;
		iss.ignore();
		getline(iss, f->especialidade, ';');
	}
	else if(tipo_f == "Tratador"){
		f = new Tratador;
		t->id = i;
		getline(iss, t->nome, ';');
		getline(iss, t->cpf, ';');
		iss >> t->idade;
		iss.ignore();
		getline(iss, t->tipo_sanguineo, ';');
		iss >> t->fatorRH;
		iss.ignore();
		getline(iss, t->especialidade, ';');
	}

	return is;
}