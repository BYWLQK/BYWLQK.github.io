#include<iostream>
#include"DynamicArray.cpp"
#include"SequentialStack.cpp"

int main() {

	DynamicArray<int> DArr;
	for (int i = 0; i < 10; i++) {
		DArr.add(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << DArr[i];
	}
	std::cout << std::endl;

	SequentialStack<int> sStack;
	for (int i = 0; i < 15; i++) {
		sStack.push(i);
	}
	for (int i = 0; i < 15; i++) {
		std::cout<<sStack.pop()<<" ";
	}

	return 0;
}

