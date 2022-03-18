#include"SequentialStack.cpp"

//bug描述：SequentialStack中的动态数组new的数
SequentialStack<int> test() {
	SequentialStack<int> a;
	return a;
}
int main() {

	test();

	return 0;
}