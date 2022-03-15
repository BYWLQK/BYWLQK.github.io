#pragma once
#ifndef _ChainStzck
#define _ChainStzck
#include"MyDoublyLinkedList.cpp"

/**
* ���ڶ�̬������DynamicArray����˳��ջ��ChainStzck
*/
template<class T>
class ChainStzck {
private:
	DoublyLinkedList<T> _DLinkedList;
	int _top;
public:
	ChainStzck();
	~ChainStzck();
	ChainStzck<T>* initStack();
	bool destoryStack(ChainStzck<T>* _pArr);
	bool StackEmpty();
	bool push(T value);
	T pop();
	T GetTop();
};

#endif