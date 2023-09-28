
#ifndef MyList_H__
#define MyList_H__

#include <iostream>
#include <string>
#include <ostream>

using std::cout;
using std::endl;



template<class T>
class Node;

template<class T>
class Node { 
	public:
		Node(const T&elem = T()): data(elem), next(NULL) {}
		T data;
		Node<T> *next;
};

template<class T>
class MyList {
public:
	typedef Node<T> * iterator; 

	MyList();
	MyList(int n, const T&init=T());
	MyList(const MyList &);
	~MyList() { destroy(); };

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
	Node<T> *dataFirst;
	int dataSize; 

	void create();
	void destroy();
};


template<class T>
void MyList<T>::destroy() { 
	if(dataFirst ==  NULL) return;
	else{
		Node<T> *temp;
		temp = dataFirst->next;
		delete dataFirst;
		dataFirst = temp;
		dataSize--;
		destroy();
	}
}

template<class T>
void MyList<T>::create() {
	dataFirst = NULL;
	dataSize = 0;
}

template<class T>
MyList<T>::MyList() {
	create();
}

template<class T>
MyList<T>::MyList(int n, const T&init) {
	create();
	for(int i=0;i<n;i++) push_back(init); 
}

template<class T>
MyList<T>::MyList(const MyList &other) {
	create(); 
	*this = other; 
}

template<class T>
bool MyList<T>::push_back(const T&elem) {
    
	if(dataFirst==NULL) { 
		dataFirst = new Node<T>(elem);
	} else {
		iterator last = dataFirst;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = new Node<T>(elem);
	}
	dataSize++;
	return true;
}

template<class T>
bool MyList<T>::push_front(const T&elem) {
	if(dataFirst==NULL) { 
		dataFirst = new Node<T>(elem);
	} else {
		Node<T> *temp = new Node<T>(elem);
		temp->next = dataFirst;

		dataFirst = temp;

	}
	dataSize++;
	return true;
}


template<class T>
bool MyList<T>::insert(const T&elem, int p) {
	if(p > dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}

	if(p == 0){
		return push_front(elem);
	}

    Node<T> *before = dataFirst;
    for(int i=0;i<p-1;i++){
        before = before->next;
    }

	iterator newNode = new Node<T>(elem);
	newNode->next = before->next;
	before->next = newNode;

	dataSize++;
	return true;
}

template<class T>
bool MyList<T>::erase(int p) { 

	if(p >= dataSize) {
		cout << "Erro, insercao em posicao invalida da lista";
        throw;
	}

	dataSize--;
	if(p == 0) {
		iterator temp = dataFirst;
		dataFirst = dataFirst->next;
		delete temp;
		return true;
	} else {
		Node<T>* beforeElem = dataFirst;
		Node<T>* curr = dataFirst->next;

		for(int i=0;i<p-1;i++){
			beforeElem = beforeElem->next;
			curr = curr->next;
		}

		beforeElem->next = curr->next; 
		delete curr;
		
		return true;
	}
}

template<class T>
T& MyList<T>::deref(iterator curr) { 
	return curr->data;
}

template<class T>
T& MyList<T>::find(int i) {

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