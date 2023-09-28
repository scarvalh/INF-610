#ifndef MyQueue_H__
#define MyQueue_H__

#include "staticList.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue {
public:
	MyQueue() : first(-1), last(-1), list(1000,0) {} 
	
	int push(const T&el);
	T front() { return list.localiza(first); }
	void pop() ;

	bool empty() { return first == -1; }
	int size();

	void print() ;
private:
	bool full() { return first == (last+1)%list.size(); }
	int first, last;
	MyStaticList<T> list;
};




template<class T>
int MyQueue<T>::push(const T&el) {
	int cont = 0;
	if(empty()) {
			first = last = 0;
			list.insere(el, last);
			cont++;
	} else {
        if(full()) {
            cout << "Fila Cheia!"<< endl;
            throw;		
        }

		last = (last+1)%list.size();
		list.insere(el, last);
		cont++;
	}	

	return cont;
}


template<class T>
void MyQueue<T>::pop() { 
	if(first==last) { 
		first = last = -1;
	} else
		first = (first+1)%list.size(); 
}

template<class T>
int MyQueue<T>::size()  {
	if(last>=first) return last-first+1;
	else return list.size() - (first-last-1);
}

template<class T>
void MyQueue<T>::print()  {
	cout << "First,last: " << first << " " << last << endl; 
	cout << "Size: " << size() << endl;
	for(int i=0;i<list.size();i++) cout << list.localiza(i) << " "; 
	cout << endl << endl;
}


#endif