
#ifndef MyList4_H__
#define MyList4_H__

#include <iostream>
#include <string>
#include <ostream>

using std::cout;
using std::endl;



template<class T>
class Node4;

template<class T>
class Node4 { 
	public:
		Node4(const T&elem = T()): data(elem), next(NULL), prev(NULL) {}
		T data;
		Node4<T> *next;
        Node4<T> *prev;
};

template<class T>
class MyList4 {
public:
	typedef Node4<T> * iterator; 

	MyList4();
	MyList4(int n, const T&init=T());
    MyList4(const MyList4 &);

	~MyList4() { destroy(); };

	//funcoes de acesso
	bool push_back(const T&);
	bool push_front(const T&);
	bool insert(const T&,int p); 	
	bool erase(int p); 
	T& find(int i);

	iterator begin() {return dataFirst;} 
	T& deref(iterator curr); 

	bool empty() const {return size() == 0;};
	int size() const {return dataSize;}; 
private:
	Node4<T> *dataFirst, *dataLast;
	int dataSize; 

	void create();
	void destroy();
};


template<class T>
void MyList4<T>::destroy() { 
	if(dataFirst ==  NULL) return;
	else{
		Node4<T> *temp;
		temp = dataFirst->next;
		delete dataFirst;
		dataFirst = temp;
		dataSize--;
		destroy();
	}
}

template<class T>
void MyList4<T>::create() {
	dataFirst = dataLast = new Node4<T>();
	dataSize = 0;
}

template<class T>
MyList4<T>::MyList4() {
	create();
}

template<class T>
MyList4<T>::MyList4(int n, const T&init) {
	create();
	for(int i=0;i<n;i++) push_back(init); 
}

template<class T>
MyList4<T>::MyList4(const MyList4 &other) {
	create(); 
	*this = other; 
}


template<class T>
bool MyList4<T>::push_back(const T&elem) {
	
    dataLast->next = new Node4<T>(elem);
    dataLast->next->prev = dataLast;
    dataLast = dataLast->next;

	dataSize++;
	return true;
}

template<class T>
bool MyList4<T>::push_front(const T&elem) {
	
    dataFirst->prev = new Node4<T>(elem);
    dataFirst->prev->next = dataFirst;
    dataFirst = dataFirst->prev;
	
	dataSize++;
	return true;
}


template<class T>
bool MyList4<T>::insert(const T&elem, int p) {
	if(p > dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}

    Node4<T> *pos = NULL;

    if(p == dataSize ) {
		return push_back(elem);
	} else if( p == 0 ){
        return push_front(elem);
    } else {
        pos = dataFirst;
        for(int i=0;i<p+1;i++){
            pos = pos->next;
        }
    }
	pos->prev->next = new Node4<T>(elem);
    pos->prev->next->next = pos;
    pos->prev = pos->prev->next;

	dataSize++;
	return true;
}

template<class T>
bool MyList4<T>::erase(int p) { 

	if(p >= dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}

	dataSize--;
	
    Node4<T>* beforeElem = dataFirst;
    Node4<T>* curr = dataFirst->next;

    for(int i=0;i<p;i++){
        beforeElem = beforeElem->next;
        curr = curr->next;
    }

    beforeElem->next = curr->next;
		if(curr==dataLast) { 
			dataLast = beforeElem;
		} else {
			curr->next->prev = beforeElem;
        }
		delete curr;       
    
    return true;
	
}

template<class T>
T& MyList4<T>::deref(iterator curr) { 
	return curr->data;
}

template<class T>
T& MyList4<T>::find(int i) {
	    
    if(i == dataSize-1) {
        return deref(dataLast);
    }

    if(i == 0) {
        return deref(dataFirst->next);
    }

    iterator p = dataFirst->next;
	for(int j=0;j<i;j++){
		p = p->next;
	}

	return deref(p);
}

#endif