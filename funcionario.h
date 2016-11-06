#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
		Funcionario(int i, string n, string c, short ida, string ts, char frh, string e);
		~Funcionario();

		int getId();
		string getNome();
		string getCpf();
		short getIdade();
		string getTipo_sanguineo();
		char getFatorRH();
		string getEspecialidade();

		void setId(int i);
		void setNome(string n);
		void setCpf(string c);
		void setIdade(short ida);
		void setTipo_sanguineo(string ts);
		void setFatorRH(char frh);
		virtual void setEspecialidade(string e) = 0;

		friend ostream& operator<<(ostream &o, Funcionario &f);
		friend istream& operator>>(istream &is, Funcionario &f);

};

class Veterinario : public Funcionario {
	public:
		Veterinario();
		Veterinario(int i, string n, string c, short ida, string ts, char frh, string e) : Funcionario (i, n, c, ida, ts, frh, e) {}
		~Veterinario();

		void setEspecialidade(string e){
			especialidade = e;
		}
};

class Tratador : public Funcionario {
	public:
		Tratador();
		Tratador(int i, string n, string c, short ida, string ts, char frh, string e) : Funcionario (i, n, c, ida, ts, frh, e){}
		~Tratador();

		void setEspecialidade(string e){
			especialidade = e;
		}
};

ostream& operator<<(ostream &o, Funcionario &f);

istream& operator>>(istream &is, Funcionario &f);

#endif