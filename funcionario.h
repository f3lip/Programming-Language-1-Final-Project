/**
 * @file	funcionario.h
 * @brief	Definicao de prototipos de classes referentes aos funcionarios
 * @author	Bruno Felipe
 * @since	02/11/2016
 * @date	02/11/2016
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/** 
 * @class 	Funcionario funcionario.h
 * @brief 	Classe que representa um funcionario
 * @details Os atributos de um funcionario sao id, nome, cpf, idade, tipo_sanguineo, fatoRH, especialidade
 */
class Funcionario {
	protected:
		int id;						/**< Numero de identificacao */
		string nome;				/**< Nome do funcionario */
		string cpf;					/**< CPF do funcionario */
		short idade;				/**< Idade do funcionario */
		string tipo_sanguineo;		/**< Tipo sanguineo do funcionario */
		char fatorRH;				/**< FatorRH do funcionario */
		string especialidade;		/**< Especialidade do funcionario */

	public:

		/** @brief Construtor padrao */
		Funcionario();

		/** @brief Construtor parametrizado */
		Funcionario(int i, string n, string c, short ida, string ts, char frh, string e);

		/** @brief Destrutor padrao */
		~Funcionario();

		int getId();					/**< Retorna o identificador */
		string getNome();				/**< Retorna o nome */
		string getCpf();				/**< Retorna o CPF */
		short getIdade();				/**< Retorna a idade */
		string getTipo_sanguineo();		/**< Retorna o tipo sanguineo */
		char getFatorRH();				/**< Retorna o fatorRH */
		string getEspecialidade();		/**< Retorna a especialidade */

		void setId(int i);				/**< Modifica o identificador */
		void setNome(string n);			/**< Modifica o nome */
		void setCpf(string c);			/**< Modifica o cpf */
		void setIdade(short ida);		/**< Modifica a idade */
		void setTipo_sanguineo(string ts);	/**< Modifica o tipo sanguineo */
		void setFatorRH(char frh);		/**< Modifica o fatorRH */
		virtual void setEspecialidade(string e) = 0;	/**< Metodo virtual para tornar a classe abstrata*/

		/** @brief Sobrecarga do operador de insercao em stream */
		friend ostream& operator<<(ostream &o, Funcionario &f);

		/** @brief Sobrecarga do operador de extracao de stream */
		friend istream& operator>>(istream &is, Funcionario &f);

};

/** 
 * @class 	Veterinario funcionario.h
 * @brief 	Classe que representa um funcionario do tipo "veterinario"
 * @details A classe Veterinario e definida por heranca da classe Funcionario
 */
class Veterinario : public Funcionario {
	public:
		
		/** @brief Construtor padrao */
		Veterinario();

		/** @brief Construtor parametrizado */
		Veterinario(int i, string n, string c, short ida, string ts, char frh, string e) : Funcionario (i, n, c, ida, ts, frh, e) {}

		/** @brief Destrutor padrao */
		~Veterinario();

		void setEspecialidade(string e){		/**< Modifica a especialidade */
			especialidade = e;
		}
};

/** 
 * @class 	Tratador funcionario.h
 * @brief 	Classe que representa um funcionario do tipo "tratador"
 * @details A classe Tratador e definida por heranca da classe Funcionario
 */
class Tratador : public Funcionario {
	public:

		/** @brief Construtor padrao */
		Tratador();

		/** @brief Construtor parametrizado */
		Tratador(int i, string n, string c, short ida, string ts, char frh, string e) : Funcionario (i, n, c, ida, ts, frh, e){}

		/** @brief Destrutor padrao */
		~Tratador();

		void setEspecialidade(string e){		/**< Modifica a especialidade */
			especialidade = e;
		}
};

/** @brief Sobrecarga do operador de insercao em stream */
ostream& operator<<(ostream &o, Funcionario &f);

/** @brief Sobrecarga do operador de extracao de stream */
istream& operator>>(istream &is, Funcionario &f);

#endif