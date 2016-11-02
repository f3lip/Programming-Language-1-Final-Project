#ifndef ANIMAL_H
#define ANIMAL_H

#include "funcionario.h"

class Animal {
	protected:
		int id;
		string classe;
		string nome;
		string cientifico;
		char sexo;
		float tamanho;
		string dieta;
		Veterinario *veterinario;
		Tratador *tratador;
		string batismo;

	public:
		Animal();
		Animal(int i, string c, string n, string cien, char s, float t, string d, string b);
		~Animal();

		int getId();
		string getClasse();
		string getNome();
		string getCientifico();
		char getSexo();
		float getTamanho();
		string getDieta();
		string getBatismo();

		void setId(int i);
		void setClasse(string c);
		void setNome(string n);
		void setCientifico(string cien);
		void setSexo(char s);
		void setTamanho(float t);
		void setDieta(string d);
		void setBatismo(string b);
};

class Anfibio : public Animal {
	protected:
		int total_mudas;
		string ultima_muda;

	public:
		Anfibio();
		Anfibio(int tot, string u);
		~Anfibio();

		int getTotal_mudas();
		string getUltimo_muda();

		void setTotal_mudas(int tot);
		void setUltimo_muda(string u);
};

class Mamiforo : public Animal {
	protected:
		string cor_pelo;

	public:
		Mamiforo();
		Mamiforo(string cor);
		~Mamiforo();

		string getCor_pelo();

		void setCor_pelo(string cor);
};

class Reptil : public Animal {
	protected:
		bool venenoso;
		string tipo_veneno;

	public:
		Reptil();
		Reptil(bool v, string tipo);
		~Reptil();

		bool getVenenoso();
		string getTipo_veneno();

		void setVenenoso(bool v);
		void setTipo_veneno(string tipo);
};

class Ave : public Animal {
	protected:
		int tamanho_bico;
		int envergadura;

	public:
		Ave();
		Ave(int tam, int env);
		~Ave();

		int getTamanho_bico();
		int getEnvergadura();

		void setTamanho_bico(int tam);
		void setEnvergadura(int env);
};

class AnimalSilvestre {
	protected:
		string ibama;

	public:
		AnimalSilvestre();
		AnimalSilvestre(string ib);
		~AnimalSilvestre();

		string getIbama();

		void setIbama(string ib);
};

class Nativo : public AnimalSilvestre {
	protected:
		string uf_origem;
		string autorizacao;

	public:
		Nativo();
		Nativo(string uf, string aut);
		~Nativo();

		string getUf_origem();
		string getAutorizacao();

		void setUf_origem(string uf);
		void setAutorizacao(string aut);
};

class Exotico : public AnimalSilvestre {
	protected:
		string pais_origem;

	public:
		Exotico();
		Exotico(string pais);
		~Exotico();

		string getPais_origem();

		void setPais_origem(string pais);
};

class AveNativa : public Ave, Nativo {};

class AveExotica : public Ave, Exotico {};

#endif
