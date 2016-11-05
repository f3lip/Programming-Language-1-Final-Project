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
		string tipo_sanguineo;
		char fatorRH;
		string especialidade;

	public:
		Funcionario();
		Funcionario(int i, string n, string c, short ida, string ts, char f, string e);
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
		void setTipo_sanguineo(string ts);
		void setFatorRH(char f);
		void setEspecialidade(string e);

		friend std::ostream& operator<< (std::ostream &o, Funcionario const f);

};

ostream& operator<< (std::ostream &o, Funcionario const f);

class Veterinario : public Funcionario {};

class Tratador : public Funcionario {};

#endif