#include "funcionario.h"
#include "lista.h"

int main (){
	Veterinario* v = new Veterinario;
	int i;
	string n, c, e;
	short ida, ts;
	char f;

	cout << "Digite a ID do funcionario: ";
	cin >> i;
	v->setId(i);
	cout << "Digite o nome do funcionario: ";
	cin.ignore();
	getline(cin, n);
	v->setNome(n);
	cout << "Digite o CPF do funcionario: ";
	cin.ignore();
	getline(cin, c);
	v->setCpf(c);
	cout << "Digite a idade do funcionario: ";
	cin.ignore();
	cin >> ida;
	v->setIdade(ida);
	/*
	cout << "Digite o tipo sanguineo do funcionario: ";
	cin.ignore();
	cin >> ts;
	v->setTipo_sanguineo(ts);
	cout << "Digite o fator RH do funcionario: ";
	cin >> f;
	v->setFatorRH(f);
	cout << "Digite a especialidade do funcionario: ";
	cin.ignore();
	getline(cin, e);
	v->setEspecialidade(e);*/

	Lista<Veterinario*> func;

	func.inserirInicio(v);

	func.listarElementos();

	return 0;
}