#pragma once
#ifndef _ChainStzck
#define _ChainStzck
#include"MyDoublyLinkedList.cpp"

/**
* 基于动态数组类DynamicArray定义顺序栈类ChainStzck
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