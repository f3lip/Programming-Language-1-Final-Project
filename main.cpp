#include "funcionario.h"
#include "lista.h"

int main (int argc, const char * argv[]){

	Funcionario* v;
	Funcionario* t;

	string a1 = argv[1];

	ifstream file;
	file.open(a1);

	if (!file) {
		cerr << "Nao foi possivel abrir o arquivo de entrada" << endl;
		cerr << "O programa sera encerrado" << endl;
		return 1;
	} 
	else {
		string linha, tipo_f;

		getline(file, linha);
		istringstream iss(linha);

		iss.ignore();
		iss.ignore();
		getline(iss, tipo_f, ';');

		if(tipo_f == "Veterinario"){
			v = new Veterinario;
			file>>*v;
		}
		else{
			t = new Tratador;
			file>>(*t);
		}
	}
	
	file.close();

	Lista<Funcionario*> func;

	func.inserirInicio(t);

	func.listarElementos();

	return 0;
}