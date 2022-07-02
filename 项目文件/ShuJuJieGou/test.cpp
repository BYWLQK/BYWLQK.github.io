#include"MyLinkedList.h"
#include<iostream>

int main() {

	int* p;
	p = new int[10];
	for (int i = 0; i < 10;i++) {
		p[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << p[i]<<" ";
	}
	delete p;
	return 0;
}