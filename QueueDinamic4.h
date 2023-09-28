#ifndef MyQueue5_H__
#define MyQueue5_H__

#include "dinamicList4.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue5 {
public:
	MyQueue5() : first(0), last(-1), list() {} 

	int push( const T&el);
	T front() { return list.find(0); }
	void pop() ;

	bool empty() { return list.empty(); }
	int size();

	void print() ;
private:
	int first, last;
	MyList4<T> list;
};




template<class T>
int  MyQueue5<T>::push( const T&el) {
	
    list.push_back(el);
    last = list.size();
	
	return 1;
}


template<class T>
void MyQueue5<T>::pop() { 
	if(first==last) { 
		last = -1;
	} 

    list.erase(0);
}

template<class T>
int MyQueue5<T>::size()  {
	list.size();
}

template<class T>
void MyQueue5<T>::print()  {
	cout << "First,last: " << first << " " << last << endl; 
	cout << "Size: " << size() << endl;
	for(int i=0;i<list.size();i++) cout << list.find(i) << " "; 
	cout << endl << endl;
}


#endif