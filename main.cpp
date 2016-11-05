#include "funcionario.h"
#include "lista.h"

int main (int argc, const char * argv[]){
	
	Veterinario* v = new Veterinario;

	string a1 = argv[1];

	ifstream file;
	file.open(a1);

	if (!file) {
		cerr << "Nao foi possivel abrir o arquivo de entrada" << endl;
		cerr << "O programa sera encerrado" << endl;
		return 1;
	} 
	else {
		file >> (*v);
	}
	
	file.close();

	Lista<Veterinario*> func;

	func.inserirInicio(v);

	func.listarElementos();

	return 0;
}