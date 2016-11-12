/**
 * @file	animal.h
 * @brief	Definicao de prototipos de classes referentes aos animais
 * @author	Bruno Felipe
 * @since	02/11/2016
 * @date	02/11/2016
 */

#ifndef ANIMAL_H
#define ANIMAL_H

#include "funcionario.h"

/** 
 * @class 	Animal animal.h
 * @brief 	Classe que representa um animal
 * @details Os atributos de um animal sao id, classe, nome, cientifico, sexo, tamanho, dieta, Veterinario, Tratador, batismo
 */
class Animal {
	private:
		virtual ostream& print(ostream&) const = 0;
		virtual istream& get(istream&) = 0;

	protected:
		int id;				/**< Numero de identificacao */
		string classe;		/**< String que indica a classe do animal */
		string nome;		/**< String que indica o nome do animal */
		string cientifico;	/**< String que indica o nome cientifico do animal */
		char sexo;			/**< Char que indica o sexo do animal */
		float tamanho;		/**< Float que indica o tamanho do animal */
		string dieta;		/**< String que indica o que o animal come */
		Veterinario *v = new Veterinario;	/**< Veterinario associado ao animal */
		Tratador *t = new Tratador;			/**< Tratador associado ao animal */
		string batismo;

	public:
		Animal();
		Animal(int i, string c, string n, string cien, char s, float t, string d, string b);
		~Animal();

		int getId();			/**< Retorna a identificacao do animal */
		string getClasse();		/**< Retorna a classe do animal */
		string getNome();		/**< Retorna o nome do animal */
		string getCientifico();	/**< Retorna o nome cientifico do animal*/
		char getSexo();			/**< Retorna o sexo do animal */
		float getTamanho();		/**< Retorna o tamanho do animal */
		string getDieta();		/**< Retorna a dieta do animal */
		string getBatismo();	/**< Retorna o nome de batismo do animal */

		void setId(int i);		/**< Modifica a identificação */
		void setClasse(string c); /**< Modifica a classe */
		void setNome(string n);	/**< Modifica o nome */
		void setCientifico(string cien);	/**< Modifica o nome cientifico */
		virtual void setSexo(char s) = 0;	/**< Metodo virtual para tornar a classe abastrata */
		void setTamanho(float t);			/**< Modifica o tamanho */
		void setDieta(string d);			/**< Modifica a dieta */
		void setBatismo(string b);			/**< Modifica o nome de batismo */


		/** @brief Sobrecarga do operador de insercao em stream */
		friend ostream& operator<<(ostream &o, const Animal &a){
			return a.print(o);
		}

		/** @brief Sobrecarga do operador de extracao de stream */
		friend istream& operator>>(istream &is, Animal &a){
			return a.get(is);
		}
};


/** 
 * @class 	Anfibio animal.h
 * @brief 	Classe que representa um animal do tipo "anfibio"
 * @details A classe Anfibio e definida por heranca da classe Animal
 */
class Anfibio : public Animal {
	protected:
		int total_mudas;		/**< Quantidade de mudas total */
		string ultima_muda;		/**< Data da ultima muda */

	public:
		
		/** @brief Construtor padrao */
		Anfibio();

		/** @brief Construtor parametrizado */
		Anfibio(int i, string c, string n, string cien, char s, float t, string d, string b, int tot, string u);
		
		/** @brief Destrutor padrao */
		~Anfibio();

		int getTotal_mudas();		/**< Retorna a quantidade total de mudas */
		string getUltima_muda();	/**< Retorna a data da ultima muda */

		void setTotal_mudas(int tot);	/**< Modifica o total de mudas */
		void setUltima_muda(string u);	/**< Modifica a data da ultima muda */
};

/** 
 * @class 	Sapo animal.h
 * @brief 	Classe concreta que representa um Sapo
 * @details A classe Sapo e definida por heranca da classe Anfibio
 */
class Sapo : public Anfibio {
	protected:
		ostream& print(ostream& o) const{
			o << "ID do animal: " << id << endl;
			o << "Classe do animal: " << classe << endl;
			o << "Nome do animal: " << nome << endl;
			o << "Nome cientifico do animal: " << cientifico << endl; 
			o << "Sexo do animal: " << sexo << endl;
			o << "Tamanho do animal:  " << tamanho << endl;
			o << "Dieta do animal: " << dieta << endl;
			o << "Nome de batismo do animal: " << batismo << endl;
			o << "Total de mudas do animal: " << total_mudas << endl;
			o << "Ultima muda do animal: " << ultima_muda << endl;

			return o;
		}

		istream& get(istream& is) {
			string linha;
			int id1, id2;

			getline(is, linha);
			istringstream iss(linha);

			iss>> id;
			iss.ignore();
			getline(iss, classe, ';');
			getline(iss, nome, ';');
			getline(iss, cientifico, ';');
			iss>> sexo;
			iss.ignore();
			iss>> tamanho;
			iss.ignore();
			getline(iss, dieta, ';');
			iss >> id1; 
			v->setId(id1);
			iss.ignore();
			iss >> id2; 
			t->setId(id2);
			iss.ignore();
			getline(iss, batismo, ';');
			iss >> total_mudas;
			iss.ignore();
			getline(iss, ultima_muda, ';');
	
	return is;
		}

	public:
		
		/** @brief Construtor padrao */
		Sapo();

		/** @brief Construtor parametrizado */
		Sapo(int i, string c, string n, string cien, char s, float t, string d, string b, int tot, string u);

		void setSexo(char s);	/**< Modifica o sexo do animal */
};

/** 
 * @class 	Mamifero animal.h
 * @brief 	Classe que representa um animal do tipo "mamifero"
 * @details A classe Mamifero e definida por heranca da classe Animal
 */
class Mamifero : public Animal {
	protected:
		string cor_pelo;	/**< Representa a cor do pelo do mamifero */

	public:

		/** @brief Construtor padrao */
		Mamifero();

		/** @brief Construtor parametrizado */
		Mamifero(int i, string c, string n, string cien, char s, float t, string d, string b, string cor);

		/** @brief Destrutor padrao */
		~Mamifero();

		string getCor_pelo();	/**< Retorna a cor do pelo */

		void setCor_pelo(string cor);	/**< Modifica a cor do pelo */
};

/** 
 * @class 	Leao animal.h
 * @brief 	Classe concreta que representa um Leao
 * @details A classe Leao e definida por heranca da classe Mamifero
 */
class Leao : public Mamifero {
	protected:
		ostream& print(ostream& o) const{
			o << "ID do animal: " << id << endl;
			o << "Classe do animal: " << classe << endl;
			o << "Nome do animal: " << nome << endl;
			o << "Nome cientifico do animal: " << cientifico << endl; 
			o << "Sexo do animal: " << sexo << endl;
			o << "Tamanho do animal:  " << tamanho << endl;
			o << "Dieta do animal: " << dieta << endl;
			o << "Nome de batismo do animal: " << batismo << endl;
			o << "Cor do pelo do animal: " << cor_pelo << endl;

			return o;
		}

		istream& get(istream& is) {
			string linha;
			int id1, id2;

			getline(is, linha);
			istringstream iss(linha);

			iss>> id;
			iss.ignore();
			getline(iss, classe, ';');
			getline(iss, nome, ';');
			getline(iss, cientifico, ';');
			iss>> sexo;
			iss.ignore();
			iss>> tamanho;
			iss.ignore();
			getline(iss, dieta, ';');
			iss >> id1; 
			v->setId(id1);
			iss.ignore();
			iss >> id2; 
			t->setId(id2);
			iss.ignore();
			getline(iss, batismo, ';');
			getline(iss, cor_pelo, ';');
	
	return is;
		}

	public:
		
		/** @brief Construtor padrao */
		Leao();

		/** @brief Construtor parametrizado */
		Leao(int i, string c, string n, string cien, char s, float t, string d, string b, string cor);

		/** @brief Destrutor padrao */
		~Leao();

		void setSexo(char s);	/**< Modifica o sexo do animal */
};

/** 
 * @class 	Reptil animal.h
 * @brief 	Classe que representa um animal do tipo "reptil"
 * @details A classe Reptil e definida por heranca da classe Animal
 */
class Reptil : public Animal {
	protected:
		bool venenoso;			/**< Define se o reptil e venenoso ou nao */
		string tipo_veneno;		/**< Representa o tipo de veneno do reptil */

	public:

		/** @brief Construtor padrao */
		Reptil();

		/** @brief Construtor parametrizado */
		Reptil(int i, string c, string n, string cien, char s, float t, string d, string b, bool ven, string tipo);

		/** @brief Destrutor padrao */
		~Reptil();

		bool getVenenoso();					/**< Retorna se o reptil e venenoso ou nao */
		string getTipo_veneno();			/**< Retorna o tipo de veneno */

		void setVenenoso(bool ven);			/**< Modifica se o reptil e venenoso ou nao */
		void setTipo_veneno(string tipo);	/**< Modifica o tipo de veneno */
};

/** 
 * @class 	Tartaruga animal.h
 * @brief 	Classe concreta que representa uma Tartaruga
 * @details A classe Tartaruga e definida por heranca da classe Reptil
 */
class Tartaruga : public Reptil {
	protected:
		ostream& print(ostream& o) const{
			o << "ID do animal: " << id << endl;
			o << "Classe do animal: " << classe << endl;
			o << "Nome do animal: " << nome << endl;
			o << "Nome cientifico do animal: " << cientifico << endl; 
			o << "Sexo do animal: " << sexo << endl;
			o << "Tamanho do animal:  " << tamanho << endl;
			o << "Dieta do animal: " << dieta << endl;
			o << "Nome de batismo do animal: " << batismo << endl;
			o << "Venenoso: " << venenoso << endl;
			o << "Tipo do veneno: " << tipo_veneno << endl;

			return o;
		}

		istream& get(istream& is) {
			string linha;
			int id1, id2;

			getline(is, linha);
			istringstream iss(linha);

			iss>> id;
			iss.ignore();
			getline(iss, classe, ';');
			getline(iss, nome, ';');
			getline(iss, cientifico, ';');
			iss>> sexo;
			iss.ignore();
			iss>> tamanho;
			iss.ignore();
			getline(iss, dieta, ';');
			iss >> id1; 
			v->setId(id1);
			iss.ignore();
			iss >> id2; 
			t->setId(id2);
			iss.ignore();
			getline(iss, batismo, ';');
			iss >>venenoso;
			iss.ignore();
			getline(iss, tipo_veneno, ';');
	
	return is;
		}

	public:

		/** @brief Construtor padrao */
		Tartaruga();

		/** @brief Construtor parametrizado */
		Tartaruga(int i, string c, string n, string cien, char s, float t, string d, string b, bool ven, string tipo);

		/** @brief Destrutor padrao */
		~Tartaruga();

		void setSexo(char s);	/**< Modifica o sexo do animal */
};

/** 
 * @class 	Ave animal.h
 * @brief 	Classe que representa um animal do tipo "ave"
 * @details A classe Ave e definida por heranca da classe Animal
 */
class Ave : public Animal {
	protected:
		int tamanho_bico;		/**< Tamanho do bico da ave */
		int envergadura;		/**< Tamanho da envergadura da ave */

	public:

		/** @brief Construtor padrao */
		Ave();

		/** @brief Construtor parametrizado */
		Ave(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env);

		/** @brief Destrutor padrao */
		~Ave();

		int getTamanho_bico();				/**< Retorna o tamanho do bico da ave */
		int getEnvergadura();				/**< Retorna o tamanho da envergadura da ave */

		void setTamanho_bico(int tam);		/**< Modifica o tamanho do bico */
		void setEnvergadura(int env);		/**< Modifica o tamanho da envergadura */

		friend class Nativo;
		friend class Exotico;
};

/** 
 * @class 	AnimalSilvestre animal.h
 * @brief 	Classe que representa um Animal Silvestre
 * @details O atributo de um animal silvestre é ibama
 */
class AnimalSilvestre {
	protected:

		string ibama;					/**< Indica o status do animal no ibama */

	public:

		/** @brief Construtor padrao */
		AnimalSilvestre();

		/** @brief Construtor parametrizado */
		AnimalSilvestre(string ib);

		/** @brief Destrutor padrao */
		~AnimalSilvestre();

		string getIbama();				/**< Retorna o status do animal no ibama */

		void setIbama(string ib);		/**< Modifica o status do animal no ibama */

		/** @brief Sobrecarga do operador de insercao em stream */
		friend ostream& operator<<(ostream &o, const Animal &a);

		/** @brief Sobrecarga do operador de extracao de stream */
		friend istream& operator>>(istream &is, Animal &a);

		friend class Ave;
};

/** 
 * @class 	Nativo animal.h
 * @brief 	Classe que representa um animal nativo
 * @details A classe Nativo e definida por heranca da classe AnimalSilvestre
 */
class Nativo : public AnimalSilvestre {
	protected:
		string uf_origem;					/**< Estado de origem do animal */
		string autorizacao;					/**< Status de autorização */

	public:

		/** @brief Construtor padrao */
		Nativo();

		/** @brief Construtor parametrizado */
		Nativo(string ib, string uf, string aut);

		/** @brief Destrutor padrao */
		~Nativo();

		string getUf_origem();				/**< Retorna o estado de origem do animal */
		string getAutorizacao();			/**< Retorna o status de autorizacao do animal */

		void setUf_origem(string uf);		/**< Modifica o estado de origem do animal */
		void setAutorizacao(string aut);	/**< Modifica o status de autorizacao */

		friend class Ave;
};

/** 
 * @class 	Exotico animal.h
 * @brief 	Classe que representa um animal exotico
 * @details A classe Exotico e definida por heranca da classe AnimalSilvestre
 */
class Exotico : public AnimalSilvestre {
	protected:
		string pais_origem;						/**< Pais de origem do animal */

	public:

		/** @brief Construtor padrao */
		Exotico();

		/** @brief Construtor parametrizado */
		Exotico(string ib, string pais);

		/** @brief Destrutor padrao */
		~Exotico();

		string getPais_origem();				/**< Retorna o pais de origem do animal */

		void setPais_origem(string pais);		/**< Modifica o pais de origem do animal */

		friend class Ave;
};


/** 
 * @class 	AveNativa animal.h
 * @brief 	Classe que representa uma Ave Nativa
 * @details A classe AveNativa e definida por heranca multipla das classes
 * 			Ave e Nativo
 */
class AveNativa : public Ave, public Nativo {
	public:

		/** @brief Construtor padrao */
		AveNativa();

		/** @brief Construtor parametrizado */
		AveNativa(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string uf, string aut);

		/** @brief Destrutor padrao */
		~AveNativa();

		friend class Ave;
};

/** 
 * @class 	AraraAzul animal.h
 * @brief 	Classe que representa um animal do tipo "arara azul"
 * @details A classe AraraAzul e definida por heranca da classe AveNativa
 */
class AraraAzul : public AveNativa {
	protected:

		ostream& print(ostream& o) const{
			o << "ID do animal: " << id << endl;
			o << "Classe do animal: " << classe << endl;
			o << "Nome do animal: " << nome << endl;
			o << "Nome cientifico do animal: " << cientifico << endl; 
			o << "Sexo do animal: " << sexo << endl;
			o << "Tamanho do animal:  " << tamanho << endl;
			o << "Dieta do animal: " << dieta << endl;
			o << "Nome de batismo do animal: " << batismo << endl;
			o << "Tamanho do bico do animal: " << tamanho_bico << endl;
			o << "Envergadura do animal: " << envergadura << endl;
			o << "Situação do animal no IBAMA: " << ibama << endl;
			o << "Estado de origem do animal: " << uf_origem << endl;
			o << "Status de autorização do animal: " << autorizacao << endl;

			return o;
		}

		istream& get(istream& is) {
			string linha;
			int id1, id2;

			getline(is, linha);
			istringstream iss(linha);

			iss>> id;
			iss.ignore();
			getline(iss, classe, ';');
			getline(iss, nome, ';');
			getline(iss, cientifico, ';');
			iss>> sexo;
			iss.ignore();
			iss>> tamanho;
			iss.ignore();
			getline(iss, dieta, ';');
			iss >> id1; 
			v->setId(id1);
			iss.ignore();
			iss >> id2; 
			t->setId(id2);
			iss.ignore();
			getline(iss, batismo, ';');
			iss >> tamanho_bico;
			iss.ignore();
			iss >> envergadura;
			iss.ignore();
			getline(iss, ibama, ';');
			getline(iss, uf_origem, ';');
			getline(iss, autorizacao, ';');
	
			return is;
		}

	public:

		/** @brief Construtor padrao */
		AraraAzul();

		/** @brief Construtor paramatrizado */
		AraraAzul(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string uf, string aut);

		/** @brief Destrutor padrao */
		~AraraAzul();

		void setSexo(char s);	/**< Modifica o sexo do animal */
};

/** 
 * @class 	AveExoticaanimal.h
 * @brief 	Classe que representa uma Ave Exotica
 * @details A classe AveExotica e definida por heranca multipla das classes
 * 			Ave e Exotico
 */
class AveExotica : public Ave, public Exotico {
	public:

		/** @brief Construtor padrao */
		AveExotica();

		/** @brief Construtor parametrizado*/
		AveExotica(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string pais);

		/** @brief Destrutor padrao */
		~AveExotica();

		friend class Ave;
};

/** 
 * @class 	Pavao animal.h
 * @brief 	Classe que representa um animal do tipo "pavao"
 * @details A classe Pavao e definida por heranca da classe AveExotica
 */
class Pavao : public AveExotica {
	protected:

		ostream& print(ostream& o) const{
			o << "ID do animal: " << id << endl;
			o << "Classe do animal: " << classe << endl;
			o << "Nome do animal: " << nome << endl;
			o << "Nome cientifico do animal: " << cientifico << endl; 
			o << "Sexo do animal: " << sexo << endl;
			o << "Tamanho do animal:  " << tamanho << endl;
			o << "Dieta do animal: " << dieta << endl;
			o << "Nome de batismo do animal: " << batismo << endl;
			o << "Tamanho do bico do animal: " << tamanho_bico << endl;
			o << "Envergadura do animal: " << envergadura << endl;
			o << "Situação do animal no IBAMA: " << ibama << endl;
			o << "País de origem do animal: " << pais_origem << endl;

			return o;
		}

		istream& get(istream& is) {
			string linha;
			int id1, id2;

			getline(is, linha);
			istringstream iss(linha);

			iss>> id;
			iss.ignore();
			getline(iss, classe, ';');
			getline(iss, nome, ';');
			getline(iss, cientifico, ';');
			iss>> sexo;
			iss.ignore();
			iss>> tamanho;
			iss.ignore();
			getline(iss, dieta, ';');
			iss >> id1; 
			v->setId(id1);
			iss.ignore();
			iss >> id2; 
			t->setId(id2);
			iss.ignore();
			getline(iss, batismo, ';');
			iss >> tamanho_bico;
			iss.ignore();
			iss >> envergadura;
			iss.ignore();
			getline(iss, ibama, ';');
			getline(iss, pais_origem, ';');
	
	return is;
		}

	public:

		/** @brief Construtor padrao */
		Pavao();

		/** @brief Construtor parametrizado*/
		Pavao(int i, string c, string n, string cien, char s, float t, string d, string b, int tam, int env, string ib, string pais);

		/** @brief Destrutor padrao */
		~Pavao();

		void setSexo(char s);	/**< Modifica o sexo do animal */
};

#endif