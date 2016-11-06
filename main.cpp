#include "funcionario.h"
#include "lista.h"

int main (int argc, const char * argv[]){
	
	Funcionario* f = new Funcionario;

	string a1 = argv[1];

	ifstream file;
	file.open(a1);

	if (!file) {
		cerr << "Nao foi possivel abrir o arquivo de entrada" << endl;
		cerr << "O programa sera encerrado" << endl;
		return 1;
	} 
	else {
		file >> *f;
	}
	
	file.close();

	Lista<Funcionario*> func;

	func.inserirInicio(f);

	func.listarElementos();

	return 0;
}