
#ifndef MyList2_H__
#define MyList2_H__

#include <iostream>
#include <string>
#include <ostream>

using std::cout;
using std::endl;



template<class T>
class Node2;

template<class T>
class Node2 { 
	public:
		Node2(const T&elem = T()): data(elem), next(NULL) {}
		T data;
		Node2<T> *next;
};

template<class T>
class MyList2 {
public:
	typedef Node2<T> * iterator; 

	MyList2();
	MyList2(int n, const T&init=T());
    MyList2(const MyList2 &);
	~MyList2() { destroy(); };

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
	Node2<T> *dataFirst, *dataLast;
	int dataSize; 

	void create();
	void destroy();
};


template<class T>
void MyList2<T>::destroy() { 
	if(dataFirst ==  NULL) return;
	else{
		Node2<T> *temp;
		temp = dataFirst->next;
		delete dataFirst;
		dataFirst = temp;
		dataSize--;
		destroy();
	}
}

template<class T>
void MyList2<T>::create() {
	dataFirst = dataLast = NULL;
	dataSize = 0;
}

template<class T>
MyList2<T>::MyList2() {
	create();
}

template<class T>
MyList2<T>::MyList2(const MyList2 &other) {
	create(); 
	*this = other; 
}

template<class T>
MyList2<T>::MyList2(int n, const T&init) {
	create();
	for(int i=0;i<n;i++) push_back(init); 
}


template<class T>
bool MyList2<T>::push_back(const T&elem) {
    
	if(dataFirst==NULL) { 
		dataFirst = dataLast = new Node2<T>(elem);
	} else {
		dataLast->next = new Node2<T>(elem);
		dataLast = dataLast->next;
	}

	dataSize++;
	return true;
}

template<class T>
bool MyList2<T>::push_front(const T&elem) {
	if(dataFirst==NULL) { 
		dataFirst = dataLast = new Node2<T>(elem);
	} else {
		Node2<T> *temp = new Node2<T>(elem);
		temp->next = dataFirst;

		dataFirst = temp;
	}
	dataSize++;
	return true;
}


template<class T>
bool MyList2<T>::insert(const T&elem, int p) {
	if(p > dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}
    
    Node2<T> *before = NULL;
    if(p == dataSize ) {
		before = dataLast;
	} else if(p == 0){
        return push_front(elem);
    } else {
        before = dataFirst;
        for(int i=0;i<p-1;i++){
            before = before->next;
        }
    }
	iterator newNode2 = new Node2<T>(elem);
	newNode2->next = before->next;
	before->next = newNode2;

    if(before == dataLast) { 
		dataLast = newNode2;
	}

	dataSize++;
	return true;
}

template<class T>
bool MyList2<T>::erase(int p) { 

	if(p >= dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}

	dataSize--;
	if( dataFirst != NULL && dataFirst == dataLast ) { 
        iterator elem = dataFirst;
		delete elem;
		dataFirst = dataLast = NULL;
		return NULL;
	} else if(p == 0) {
		iterator temp = dataFirst;
		dataFirst = dataFirst->next;
		delete temp;
		return true;
	} else {
		Node2<T>* beforeElem = dataFirst;
		Node2<T>* curr = dataFirst->next;

		for(int i=0;i<p-1;i++){
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
}

template<class T>
T& MyList2<T>::deref(iterator curr) { 
	return curr->data;
}

template<class T>
T& MyList2<T>::find(int i) {
	    
    if(i == dataSize-1) {
        return deref(dataLast);
    }

    if(i == 0) {
        return deref(dataFirst);
    }

    iterator p = dataFirst;
	for(int j=0;j<i;j++){
		p = p->next;
	}

	return deref(p);
}

#endif