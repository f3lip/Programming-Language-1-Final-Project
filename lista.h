#ifndef LISTA_H
#define LISTA_H

#include "no.h"
#include "animal.h"
#include "funcionario.h"

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
		void inserirId(T d, int id);
		void inserirFim(T d);
		void removerInicio();
		void removerId(int id);
		void removerFim();
		bool listaVazia();
		void listarElementos();
		int buscar(T d);
		void buscarObj(int id);
		T buscarObj1(int id);
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
void Lista<T>::inserirId(T d, int id) {
	if (listaVazia()) {
		inserirInicio(d);
	} else {
		int posicao = -1, tamanho;
		No<T>* p = this->inicio;
		T c = p->getDado();
		tamanho = c->getTamanho();
		while (posicao < (tamanho - 1) ) {
			posicao++;
			if (c->getId() == id) {
				p->setDado(d);
			} else {
				p = p->getProximo();
			}
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
void Lista<T>::removerId(int id) {
	if (listaVazia()) {
		cerr << "Nao e possivel remover: lista vazia" << endl;
	} else {
		int posicao = -1;
		No<T>* p = this->inicio;
		T d = p->getDado();
		while (id != d->getId() ) {
			posicao++;
			if (d->getId() == id) {
				delete p;
			} else {
				p = p->getProximo();
			}
		}
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
			cout << *(p->getDado()) << " -> ";
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

template<class T>
void Lista<T>::buscarObj(int id) {
	int posicao = -1;
	int tamanho = getTamanho();
	No<T>* p = this->inicio;
	T d = p->getDado();
	while (posicao < (tamanho-1)) {
		posicao++;
		if (d->getId() == id) {
			cout << (*d);
		} else {
			p = p->getProximo();
		}
	}
}

template<class T>
T Lista<T>::buscarObj1(int id) {
	int posicao = -1;
	No<T>* p = this->inicio;
	T d = p->getDado();
	while (id != d->getId() ) {
		posicao++;
		if (d->getId() == id) {
			return d;
		} else {
			p = p->getProximo();
		}
	}

}

#endif