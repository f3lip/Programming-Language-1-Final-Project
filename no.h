#ifndef NO_H
#define NO_H

template<class T>
class No {
	private:
		T dado;
		No* proximo;

	public:
		No();
		No(T d, No<T>* p);
		No(T d);
		~No();

		T getDado();
		No* getProximo();

		void setDado(T d);
		void setProximo(No*<T> p);
};

template<class T>
No<T>::No(){
	this->proximo = NULL;
}

template<class T>
No<T>::No(T d, No<T>* p){
	dado = d;
	this->proximo = p;
}

template<class T>
No<T>::No(T d){
	dado = d;
	this->proximo = NULL;
}

template<class T>
No<T>::~No() {}

template<class T>
T No<T>::getDado() {
	return dado;
}

template<class T>
No<T>* No<T>::getProximo() {
	return this->proximo;
}

template<class T>
void No<T>::setDado(T d) {
	dado = d;
}

template<class T>
void No<T>::setProximo(No<T>* p) {
	this->proximo = p;
}

#endif
