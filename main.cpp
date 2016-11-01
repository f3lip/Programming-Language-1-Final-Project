#include "funcionario.h"
#include "lista.h"

int main (){
	Veterinario v;
	int i;
	string n, c, e;
	short ida, ts;
	char f;

	cout << "Digite a ID do funcionario: ";
	cin >> i;
	v.setId(i);
	cout << "Digite o nome do funcionario: ";
	cin >> n;
	v.setNome(n);
	cout << "Digite o CPF do funcionario: ";
	cin >> c;
	v.setCpf(c);
	cout << "Digite a idade do funcionario: ";
	cin >> ida;
	v.setIdade(ida);
	cout << "Digite o tipo sanguineo do funcionario: ";
	cin >> ts;
	v.setTipo_sanguineo(ts);
	cout << "Digite o fator RH do funcionario: ";
	cin >> f;
	v.setFatorRH(f);
	cout << "Digite a especialidade do funcionario: ";
	cin >> e;
	v.setEspecialidade(e);

	Lista<> func; //resolver problema com o tipo

	func.inserirInicio(v);

	func.listarElementos();

	return 0;
}