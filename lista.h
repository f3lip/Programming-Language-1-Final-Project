#ifndef LISTA_H
#define LISTA_H

#include "no.h"

template<class T>
class Lista{
	private:
		int tamanho;
		No<T>* inicio;
		No<T>* fim;

	public:
		Lista();
		Lista(T d);
		~Lista();
 
		int getTamanho();
		No<T>* getInicio();

		void setInicio(No<T>* i);
		void setFim(No<T>* f);

		void inserirInicio(T d);
		void inserirPosicao(T d, int pos);
		void inserirFim(T d);
		void removerInicio();
		void removerPosicao(int pos);
		void removerFim();
		bool listaVazia();
		void listarElementos();
		int buscar(T d);
};

template<class T>
Lista<T>::Lista() {
	tamanho = 0;
	this->inicio = NULL;
}

template<class T>
Lista<T>::Lista(T d) {
	this->inicio = new No<T>(d);
	tamanho++;
}

template<class T>
Lista<T>::~Lista() {
	if (!listaVazia()) {
		delete this->inicio;
	}
	tamanho = 0;
}

template<class T>
int Lista<T>::getTamanho() {
	return tamanho;
}

template<class T>
No<T>* Lista<T>::getInicio() {
	return this->inicio;
}

template<class T>
void Lista<T>::setInicio(No<T>* i) {
	this->inicio = i;
}

template<class T>
void Lista<T>::inserirInicio(T d) {
	No<T>* novo = new No<T>(d);	
	if (!listaVazia()) {
		novo->setProximo(this->inicio);
	}
	this->inicio = novo;
	tamanho++;
}

template<class T>
void Lista<T>::inserirPosicao(T d, int pos) {
	if (pos > tamanho) {
		cerr << "Nao e possivel inserir: posicao invalida" << endl;
	} else {
		if (listaVazia()) {
			inserirInicio(d);
		} else {
			No<T>* novo = new No<T>(d);
			No<T>* p = this->inicio;
			for (int i = 0; i < pos-1; i++) {
				p = p->getProximo();
			}
			novo->setProximo(p->getProximo());
			p->setProximo(novo);
			tamanho++;
		}
	}
}

template<class T>
void Lista<T>::inserirFim(T d) {
	if (listaVazia()) {
		inserirInicio(d);
	} else {
		No<T>* novo = new No<T>(d);
		No<T>* p = this->inicio;
		while (p->getProximo() != NULL) {
			p = p->getProximo();
		}
		p->setProximo(novo);
		tamanho++;
	}
}

template<class T>
void Lista<T>::removerInicio() {
	if (listaVazia()) {
		cerr << "Nao e possivel remover: lista vazia" << endl;
	} else {
		No<T>* removido = this->inicio;
		this->inicio = removido->getProximo();
		delete removido;
		tamanho--;
	}
}

template<class T>
void Lista<T>::removerPosicao(int pos) {
	if (listaVazia()) {
		cerr << "Nao e possivel remover: lista vazia" << endl;
	} else if (pos > tamanho-1) {
		cerr << "Nao e possivel remover: posicao invalida" << endl;
	} else {
		No<T>* p = this->inicio;
		No<T>* anterior;
		for (int i = 0; i < pos; i++) {
			anterior = p;
			p = p->getProximo();
		}

		anterior->setProximo(p->getProximo());
		delete p;
		tamanho--;
	}
}

template<class T>
void Lista<T>::removerFim() {
	if (listaVazia()) {
		cerr << "Nao e possivel remover: lista vazia" << endl;
	} else {
		No<T>* p = this->inicio;
		No<T>* anterior;
		while (p->getProximo() != NULL) {
			anterior = p;
			p = p->getProximo();
		}
		anterior->setProximo(NULL);
		delete p;
		tamanho--;
	}
}

template<class T>
bool Lista<T>::listaVazia() {
	return (this->inicio == NULL);
}

template<class T>
void Lista<T>::listarElementos() {
	if (listaVazia()) {
		cout << "A lista esta vazia" << endl;
	} else {
		No<T>* p = this->inicio;
		while (p != NULL) {
			cout << p->getDado() << " -> ";
			p = p->getProximo();	
		}
		cout << "NULL" << endl;
	}
}

template<class T>
int Lista<T>::buscar(T d) {
	int posicao = -1;
	No<T>* p = this->inicio;
	while (p != NULL) {
		posicao++;
		if (p->getDado() == d) {
			return posicao;
		} else {
			p = p->getProximo();
		}
	}
	return posicao;
}

#endif