#include"SequentialStack.cpp"

//bug������SequentialStack�еĶ�̬����new����
SequentialStack<int> test() {
	SequentialStack<int> a;
	return a;
}
int main() {

	test();

	return 0;
}