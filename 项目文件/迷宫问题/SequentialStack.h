#pragma once
#ifndef _SequentialStack
#define _SequentialStack
#include"DynamicArray.cpp"

/**
* ���ڶ�̬������DynamicArray����˳��ջ��SequentialStack
*/
template<class T>
class SequentialStack {
private:
	DynamicArray<T> _DArr;
	size_t _top;
public:
	SequentialStack();
	~SequentialStack();
	SequentialStack<T>* initStack();
	bool destoryStack(SequentialStack<T>* _pArr);
	bool StackEmpty();
	bool push(T value);
	T pop();
	T GetTop();
	size_t size();
	SequentialStack& operator = (SequentialStack rhs);
};

#endif