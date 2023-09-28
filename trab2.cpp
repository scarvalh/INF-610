#include <iostream>
#include "QueueStatic.h"
#include "QueueDinamic1.h"
#include "QueueDinamic2.h"
#include "QueueDinamic3.h"
#include "QueueDinamic4.h"
#include "MyMap.h"

using namespace std;


int main() {
	
	
	int x = 10;
	for(int j=1;j<=20;j = j+10) {
		MyMap<int, int> *mapTest = new MyMap<int, int>();
		for(int i=0;i<j;i++){
			mapTest->insert(i, i*10);
		}
		// cout << j << " ";
		mapTest->find(j/2);
	}

	
	
	cout<< endl;
	
	
}