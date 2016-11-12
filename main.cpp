/**
 * @file	main.cpp
 * @brief	Codigo fonte principal da implementacao do Projeto 2
 * @author	Bruno Felipe
 * @since	02/11/2016
 * @date	02/11/2016
 * @sa		funcionario.h
 * @sa		animal.h
 * @sa		lista.h
 */


#include "funcionario.h"
#include "animal.h"
#include "lista.h"

int main (int argc, const char * argv[]){
	int op, id;
	Funcionario* v;
	Funcionario* t;
	Animal* am;
	Animal* r;
	Animal* m;
	Animal* an;
	Animal* ae;
	string a1 = argv[1];
	string a2 = argv[2];
	string tmp, linha, linha2, tipo, tipo2;
	ifstream file, file2, filean, file2an;

	if(a1 == "funcionarios.txt"){
		tmp = a1;
		a1 = a2;
		a2 = tmp;
	}

	Lista<Animal*> anm;
	Lista<Funcionario*> func;

	while(op != 6){

		cout << "-----------------------------------" << endl;
		cout << "|                                 |" << endl;
		cout << "|            PET FERA             |" << endl;
		cout << "|                                 |" << endl;
		cout << "-----------------------------------" << endl;	
	
		cout << endl << "	Opções disponíveis: " << endl;
		cout << "1. Cadastrar um novo animal para comercialização" << endl;
		cout << "2. Remover um animal que foi comercializado" << endl;
		cout << "3. Alterar os dados cadastrais de um animal" << endl;
		cout << "4. Consultar os dados cadastrais de um animal específico" << endl;
		cout << "5. Cadastrar veterinarios ou tratadores" << endl << endl;
		cout << "6. Caso deseje sair do programa." << endl;

		cout << "Digite o número da opção desejada: ";
		cin >> op;

		switch(op){

			case 1: {
				filean.open(a1);
				file2an.open(a1);

				getline(filean, linha);
				istringstream iss(linha);

				iss.ignore();
				iss.ignore();
				getline(iss, tipo, ';');
			
				if(tipo == "Amphibia"){
					am = new Sapo;
					file2an>>(*am);
					anm.inserirInicio(am);
				}
				else if(tipo == "Reptilia"){
					r = new Tartaruga;
					file2an>>(*r);
					anm.inserirInicio(r);
				}
				else if(tipo == "Mammalia"){
					m = new Leao;
					file2an>>(*m);
					anm.inserirInicio(m);
				}
			
				else if(tipo == "Aves"){
					for(int i = 0; i < 7; i++){
						iss.ignore();
					}
					getline(iss, tipo2, ';');
					if(tipo2 == "AveNativa"){
						an = new AraraAzul;
						file2an>>(*an);
						anm.inserirInicio(an);
					}
					else if(tipo2 == "AveExotica"){
						ae = new Pavao;
						file2an>>(*ae);
						anm.inserirInicio(ae);
					}
				}	
				filean.close();
				file2an.close();
				break;
			}
			case 2: {
				cout << "Digite o ID do animal a ser removido: ";
				cin >> id;
				anm.removerId(id);
				anm.listarElementos();
				break;
			}
			case 3: {
				string nome, cientifico, dieta, batismo, classe, cor, u_m, t_v, ib, u_o, aut, p_o;
				int t_m, t_b, env;
				bool ven;
				char sexo;
				float tamanho;
				cout << "Digite o ID do animal que deseja alterar os dados: ";
				cin >> id;
				cin.ignore();
				cout << "Digite a classe do animal (no caso de Aves, digitar AveNativa ou AveExotica) que deseja alterar os dados: ";
				getline(cin, classe);

				if(classe == "Amphibia"){
					Anfibio* am1 = new Sapo;
					am1->setId(id);
					am1->setClasse(classe);
					cout << "Digite o nome: ";
					getline(cin, nome);
					am1->setNome(nome);
					cout << "Digite o nome cientifico: ";
					getline(cin, cientifico);
					am1->setCientifico(cientifico);
					cout << "Digite o sexo: ";
					cin >> sexo;
					am1->setSexo(sexo);
					cout << "Digite o tamanho: ";
					cin >> tamanho;
					am1->setTamanho(tamanho);
					cout << "Digite a dieta: ";
					cin.ignore();
					getline(cin, dieta);
					am1->setDieta(dieta);
					cout << "Digite o nome de batismo: ";
					getline(cin, batismo);
					am1->setBatismo(batismo);
					cout << "Total de mudas: ";
					cin >> t_m;
					cin.ignore();
					am1->setTotal_mudas(t_m);
					cout << "Data da ultima muda: ";
					getline(cin, u_m);
					am1->setUltima_muda(u_m);

					anm.inserirId(am1, id);
				}
				else if(classe == "Reptilia"){
					Reptil* r1 = new Tartaruga;
					r1->setId(id);
					r1->setClasse(classe);
					cout << "Digite o nome: ";
					getline(cin, nome);
					r1->setNome(nome);
					cout << "Digite o nome cientifico: ";
					getline(cin, cientifico);
					r1->setCientifico(cientifico);
					cout << "Digite o sexo: ";
					cin >> sexo;
					r1->setSexo(sexo);
					cout << "Digite o tamanho: ";
					cin >> tamanho;
					r1->setTamanho(tamanho);
					cout << "Digite a dieta: ";
					cin.ignore();
					getline(cin, dieta);
					r1->setDieta(dieta);
					cout << "Digite o nome de batismo: ";
					getline(cin, batismo);
					r1->setBatismo(batismo);
					cout << "Venenoso: ";
					cin >> ven;
					cin.ignore();
					r1->setVenenoso(ven);
					cout << "Digite o tipo de veneno: ";
					getline(cin, t_v);
					r1->setTipo_veneno(t_v);

					anm.inserirId(r1, id);
				}
				else if(classe == "Mammalia"){
					Mamifero* m1 = new Leao;
					m1->setId(id);
					m1->setClasse(classe);
					cout << "Digite o nome: ";
					getline(cin, nome);
					m1->setNome(nome);
					cout << "Digite o nome cientifico: ";
					getline(cin, cientifico);
					m1->setCientifico(cientifico);
					cout << "Digite o sexo: ";
					cin >> sexo;
					m1->setSexo(sexo);
					cout << "Digite o tamanho: ";
					cin >> tamanho;
					m1->setTamanho(tamanho);
					cout << "Digite a dieta: ";
					cin.ignore();
					getline(cin, dieta);
					m1->setDieta(dieta);
					cout << "Digite o nome de batismo: ";
					getline(cin, batismo);
					m1->setBatismo(batismo);
					cout << "Digite a cor de pele: ";
					getline(cin, cor);
					m1->setCor_pelo(cor);

					cout << (*m1);
					anm.inserirId(m1, id);
				}
				
				else if(classe == "AveNativa"){
					AraraAzul* an1 = new AraraAzul;
					an1->setId(id);
					an1->setClasse(classe);
					cout << "Digite o nome: ";
					getline(cin, nome);
					an1->setNome(nome);
					cout << "Digite o nome cientifico: ";
					getline(cin, cientifico);
					an1->setCientifico(cientifico);
					cout << "Digite o sexo: ";
					cin >> sexo;
					an1->setSexo(sexo);
					cout << "Digite o tamanho: ";
					cin >> tamanho;
					an1->setTamanho(tamanho);
					cout << "Digite a dieta: ";
					cin.ignore();
					getline(cin, dieta);
					an1->setDieta(dieta);
					cout << "Digite o nome de batismo: ";
					getline(cin, batismo);
					an1->setBatismo(batismo);
					cout << "Digite o tamanho do bico: ";
					cin >> t_b;
					cin.ignore();
					an1->setTamanho_bico(t_b);
					cout << "Digite a envergadura: ";
					cin >> env;
					cin.ignore();
					an1->setEnvergadura(env);
					cout << "Digite a situação com o IBAMA: ";
					getline(cin, ib);
					an1->setIbama(ib);
					cout << "Digite o estado de origem: ";
					getline(cin, u_o);
					an1->setUf_origem(u_o);
					cout << "Digite o status de autorização: ";
					getline(cin, aut);
					an1->setAutorizacao(aut);

					anm.inserirId(an, id);
				}
				else if(classe == "AveExotica"){
					Pavao* ae1 = new Pavao;
					ae1->setId(id);
					ae1->setClasse(classe);
					cout << "Digite o nome: ";
					getline(cin, nome);
					ae1->setNome(nome);
					cout << "Digite o nome cientifico: ";
					getline(cin, cientifico);
					ae1->setCientifico(cientifico);
					cout << "Digite o sexo: ";
					cin >> sexo;
					ae1->setSexo(sexo);
					cout << "Digite o tamanho: ";
					cin >> tamanho;
					ae1->setTamanho(tamanho);
					cout << "Digite a dieta: ";
					cin.ignore();
					getline(cin, dieta);
					ae1->setDieta(dieta);
					cout << "Digite o nome de batismo: ";
					getline(cin, batismo);
					ae1->setBatismo(batismo);
					cout << "Digite o tamanho do bico: ";
					cin >> t_b;
					cin.ignore();
					ae1->setTamanho_bico(t_b);
					cout << "Digite a envergadura: ";
					cin >> env;
					cin.ignore();
					ae1->setEnvergadura(env);
					cout << "Digite a situação com o IBAMA: ";
					getline(cin, ib);
					ae1->setIbama(ib);
					cout << "Digite o país de origem: ";
					getline(cin, p_o);
					ae1->setPais_origem(p_o);

					anm.inserirId(ae, id);
				}
				
				break;
			}
			
			case 4: {
				cout << "Digite o ID do animal que deseja consultar os dados: ";
				cin >> id;
				anm.buscarObj(id);
				break;
			}
			case 5: {
				break;
			}
			case 6: {
				file.open(a2);
				file2.open(a2);

				getline(file, linha2);
				istringstream iss(linha2);

				iss.ignore();
				iss.ignore();
				getline(iss, tipo, ';');

				if(tipo == "Veterinario"){
					v = new Veterinario;
					file2 >> (*v);
					func.inserirInicio(v);
				}
				else if(tipo == "Tratador"){
					t = new Tratador;
					file2 >> (*t);
					func.inserirInicio(t);
				}
				file.close();
				file2.close();
				break;
			}	
		}
	}

	return 0;
}