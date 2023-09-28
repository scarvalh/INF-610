

#ifndef MyStaticList_H__
#define MyStaticList_H__

#include <iostream>

using namespace std;

template<class T>
class MyStaticList {
public: 

    MyStaticList();
    MyStaticList(int, const T&init = T());

    bool vazia();
	bool cheia();
	bool insere( const T &);
	bool insere( const T &, int);
	bool remove(int);
	T localiza(int);
	int size() { return dataSize;};

    
private:
    int dataSize;
    T data[10000];
    

};

template<class T>
MyStaticList<T>::MyStaticList(){
	this->dataSize = 0;
}

template<class T>
MyStaticList<T>::MyStaticList(int n, const T & init){
	this->dataSize = n;
	for(int i=0;i<n;i++) this->data[i] = init;
    
}

template<class T> 
bool MyStaticList<T>::vazia(){
		return this->dataSize == 0;
}

template<class T> 
bool MyStaticList<T>::cheia(){
		return this->dataSize == 10000;
}


template<class T>
T MyStaticList<T>::localiza(int p){
	if(p >= this->dataSize){
		cout << "POSICAO INVALIDA!";
        throw;
	}

	return this->data[p];
}

template<class T>
bool MyStaticList<T>::remove(int p){
	if(this->cheia()){
		cout << "LISTA CHEIA!";
		return false;
	} else if(p >= this->dataSize){
		cout << "POSICAO INVALIDA!";
		return false;
	} else {
		for(int i=p; i < this->dataSize; i++){
			this->data[i] = this->data[i+1];
		}
		this->dataSize--;
		return true;
	}
}

template<class T>
bool MyStaticList<T>::insere(const T &elem, int p){
	if(this->cheia()){
			cout << "LISTA CHEIA!";
			return false;
		} else if(p >= this->dataSize){
			cout <<  "POSICAO INVALIDA!";
			return false;
		} else {
			for(int i=this->dataSize-1; i >= p; i--){
				this->data[i+1] = this->data[i];
			}
			this->data[p] = elem;
			this->dataSize++;
			return true;
		}
}

template<class T>
bool MyStaticList<T>::insere(const T &elem){
		if(this->cheia()){
			cout << "LISTA CHEIA!";
			return false;
		} 
		this->data[this->dataSize] = elem;
		this->dataSize++;
		return true;
	}

#endif