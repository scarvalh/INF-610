
#ifndef MyList3_H__
#define MyList3_H__

#include <iostream>
#include <string>
#include <ostream>

using std::cout;
using std::endl;



template<class T>
class Node3;

template<class T>
class Node3 { 
	public:
		Node3(const T&elem = T()): data(elem), next(NULL) {}
		T data;
		Node3<T> *next;
};

template<class T>
class MyList3 {
public:
	typedef Node3<T> * iterator; 

	MyList3();
	MyList3(int n, const T&init=T());
    MyList3(const MyList3 &);

	~MyList3() { destroy(); };

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
	Node3<T> *dataFirst, *dataLast;
	int dataSize; 

	void create();
	void destroy();
};


template<class T>
void MyList3<T>::destroy() { 
	if(dataFirst ==  NULL) return;
	else{
		Node3<T> *temp;
		temp = dataFirst->next;
		delete dataFirst;
		dataFirst = temp;
		dataSize--;
		destroy();
	}
}

template<class T>
void MyList3<T>::create() {
	dataFirst = dataLast = new Node3<T>();
	dataSize = 0;
}

template<class T>
MyList3<T>::MyList3() {
	create();
}

template<class T>
MyList3<T>::MyList3(int n, const T&init) {
	create();
	for(int i=0;i<n;i++) push_back(init); 
}

template<class T>
MyList3<T>::MyList3(const MyList3 &other) {
	create(); 
	*this = other; 
}


template<class T>
bool MyList3<T>::push_back(const T&elem) {
	
    dataLast->next = new Node3<T>(elem);
    dataLast = dataLast->next;

	dataSize++;
	return true;
}

template<class T>
bool MyList3<T>::push_front(const T&elem) {
	
    iterator newNode3 = new Node3<T>(elem);
	newNode3->next = dataFirst->next;
	dataFirst->next = newNode3;
	
	dataSize++;
	return true;
}


template<class T>
bool MyList3<T>::insert(const T&elem, int p) {
	if(p > dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}
    
    Node3<T> *before = NULL;
    if(p == dataSize ) {
		return push_back(elem);
	} else if( p == 0 ){
        return push_front(elem);
    } else {
        before = dataFirst;
        for(int i=0;i<p-1;i++){
            before = before->next;
        }
    }
	iterator newNode3 = new Node3<T>(elem);
	newNode3->next = before->next;
	before->next = newNode3;

	dataSize++;
	return true;
}

template<class T>
bool MyList3<T>::erase(int p) { 

	if(p >= dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}

	dataSize--;
	
    Node3<T>* beforeElem = dataFirst;
    Node3<T>* curr = dataFirst->next;

    for(int i=0;i<p;i++){
        beforeElem = beforeElem->next;
        curr = curr->next;
    }

    beforeElem->next = curr->next; 
    if(curr==dataLast) {
        dataLast = beforeElem;
    }
    delete curr;        
    
    return true;
	
}

template<class T>
T& MyList3<T>::deref(iterator curr) { 
	return curr->data;
}

template<class T>
T& MyList3<T>::find(int i) {
	    
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