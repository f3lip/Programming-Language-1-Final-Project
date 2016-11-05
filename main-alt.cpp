#include "funcionario.h"
#include "lista.h"

int main (int argc, const char * argv[]){
	
	//Veterinario* v = new Veterinario;

	string a1 = argv[1];

	ifstream file;
	file.open(a1);

	if (!file) {
		cerr << "Nao foi possivel abrir o arquivo de entrada" << endl;
		cerr << "O programa sera encerrado" << endl;
		return 1;
	} 
	else {
		file >> v; //como fazer isso funcionar? Só aceita se for Veterinario v; Sendo Veterinario* v = new Veterinario; não funciona
	}				// e a lista precisa que seja Veterinario* v = new Veterinario;

	file.close();

	Lista<Veterinario*> func;

	func.inserirInicio(v);

	func.listarElementos();

	return 0;
}