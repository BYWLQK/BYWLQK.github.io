#pragma once
#include"ChainStack.h"

template<class T>
ChainStzck<T>::ChainStzck() {
	_top = 0;
}

template<class T>
ChainStzck<T>::~ChainStzck() {
	_top = 0;
}

template<class T>
ChainStzck<T>* ChainStzck<T>::initStack() {
	return new ChainStzck;
}

template<class T>
bool ChainStzck<T>::destoryStack(ChainStzck<T>* _pDLinkedList) {
	return delete _pDLinkedList;
}

template<class T>
bool ChainStzck<T>::StackEmpty() {
	return _top == 0;
}

template<class T>
bool ChainStzck<T>::push(T value) {
	_DLinkedList.insert(_top, value);
	_top++;
	return true;
}

template<class T>
T ChainStzck<T>::pop() {
	if (_top != 0) {
		T t = _DLinkedList.getValue(--_top);
		_DLinkedList.remove(_top);
		return t;
	}
	else {
		return _DLinkedList.getValue(0);
	}
}

template<class T>
T ChainStzck<T>::GetTop() {
	return _DLinkedList.getValue(_top-1);
}