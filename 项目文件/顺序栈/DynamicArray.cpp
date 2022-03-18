#pragma once
#include"DynamicArray.h"

template<class T>
DynamicArray<T>::DynamicArray() {
	_pArr = new T[10];
	_pos = 0;
	_size = 10;
}

template<class T>
DynamicArray<T>::~DynamicArray() {
	delete _pArr;
	_pos = 0;
	_size = 10;
}

template<class T>
DynamicArray<T>* DynamicArray<T>::initDArr() {
	return new DynamicArray;
}

template<class T>
bool DynamicArray<T>::destoryDArr(DynamicArray<T>* pArr) {
	delete pArr;
	return true;
}

template<class T>
bool DynamicArray<T>::add(T value) {
	if (_pos == _size) {
		size_t st = size_t(1.5 * _size);
		T* pt = new T[st];
		for (int i = 0; i < _size; i++) {
			pt[i] = _pArr[i];
		}
		delete _pArr;
		_pArr = pt;
		_size = st;
		_pArr[_pos++] = value;
	}
	else {
		_pArr[_pos++] = value;
	}
	return true;
}

template<class T>
bool DynamicArray<T>::out() {
	_pos--;
	return true;
}

template<class T>
T& DynamicArray<T>::operator [] (int i) {
	return _pArr[i];
};

template<class T>
DynamicArray<T>& DynamicArray<T>::operator = (DynamicArray<T>& rhs) {
	_pos = 0;
	_size = 10;
	for (int i = 0; i < rhs._size;i++) {
		this->add(rhs[i]);
	}
	return *this;
}
