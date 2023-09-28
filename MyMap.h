#ifndef MY_MAP_H
#define MY_MAP_H

#include "dinamicList4.h"

using namespace std;


template  <class K, class V>
class NodeMap {
	public: 
		NodeMap(const K &key_ = K(), const V&value_ = V()) : key(key_), value(value_) {}
		K key;
		V value;
};

template  <class K, class V>
class MyMap {
public:

	int size() const;
	MyMap();

	void insert(const K &key, const V &value); 
	void remove(const K &key);
	V find(const K&key);
	int count(const K&key) const; 
	
	MyMap(const MyMap &other);
	~MyMap();


private:
	MyQueue5<NodeMap<K,V>> *queue;
};

template  <class K, class V>
MyMap<K,V>::MyMap() {
	queue = new MyQueue5<NodeMap<K,V>>();
}

template  <class K, class V>
MyMap<K,V>::MyMap(const MyMap &other) {
	queue = new MyQueue5<NodeMap<K,V>>();
	*this = other;
}

template  <class K, class V>
MyMap<K,V>::~MyMap() {
	delete queue;
}


template  <class K, class V>
int MyMap<K,V>::size() const {
	return queue->size(); 
}


template  <class K, class V>
void MyMap<K,V>::insert(const K &key, const V &value) { 
	NodeMap<K,V> * elem = new NodeMap<K,V>(key,value);
	queue->push(*elem);
}

template  <class K, class V>
V MyMap<K,V>::find(const K &key) { 
	int cont = 0;
	MyQueue5<NodeMap<K,V>> *aux = new MyQueue5<NodeMap<K,V>>();
	NodeMap<K,V> *elem = NULL;

	while(!queue->empty()){
		NodeMap<K,V> front = queue->front();
		cont++;
		if(front.key == key){
			elem = &front;
			break;
		}	
		cont += aux->push(queue->front());
		cont++;
		queue->pop();
		cont++;
	}

	while(!queue->empty()){
		cont += aux->push(queue->front());
		cont++;
		queue->pop();
		cont++;
	}
	
	queue = aux;
	cout << cont << endl;

	if(elem != NULL){
		return elem->value;
	} 
	
	return -1;
}


template  <class K, class V>
void MyMap<K,V>::remove(const K &key) {
	MyQueue5<NodeMap<K,V>> *aux = new MyQueue5<NodeMap<K,V>>();

	while(!queue->empty()){
		NodeMap<K,V> *front = queue->front();
		if(front->key != key){
			aux->push(queue->front());
			queue->pop();
		}	
	}

	queue = aux;
}

template  <class K, class V>
int MyMap<K,V>::count(const K&key) const {
	MyQueue5<NodeMap<K,V>> *aux = new MyQueue5<NodeMap<K,V>>();
	int count = 0;
	while(!queue->empty()){
		NodeMap<K,V> *front = queue->front();

		if(front->key == key) count++;

		aux->push(queue->front());
		queue->pop();
	}

	queue = aux;
	return count;
}

#endif
