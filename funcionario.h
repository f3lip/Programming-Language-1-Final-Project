#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>

using namespace std;

class Funcionario {
	protected:
		int id;
		string nome;
		string cpf;
		short idade;
		short tipo_sanguineo;
		char fatorRH;
		string especialidade;

	public:
		Funcionario();
		Funcionario(int i, string n, string c, short ida, short ts, char f, string e);
		~Funcionario();

		int getId();
		string getNome();
		string getCpf();
		short getIdade();
		short getTipo_sanguineo();
		char getFatorRH();
		string getEspecialidade();

		void setId(int i);
		void setNome(string n);
		void setCpf(string c);
		void setIdade(short ida);
		void setTipo_sanguineo(short ts);
		void setFatorRH(char f);
		void setEspecialidade(string e);

};

class Veterinario : protected Funcionario {};

class Tratador : protected Funcionario {};

#endif