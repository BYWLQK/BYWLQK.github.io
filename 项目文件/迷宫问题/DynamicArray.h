#pragma once
#ifndef _DynamicArray
#define _DynamicArray
/**
* 定义动态数组类DynamicArray
*/
template<class T>
class DynamicArray {
private:
	T* _pArr;
	int _pos;
	size_t _size;
public:
	DynamicArray();
	~DynamicArray();
	DynamicArray<T>* initDArr();
	bool destoryDArr(DynamicArray<T>* _pArr);
	bool add(T value);
	bool out();
	size_t getSize();

	T& operator [] (int i);
	DynamicArray& operator = (DynamicArray& rhs);
};

#endif