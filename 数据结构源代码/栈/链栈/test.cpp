#include"ChainStack.cpp"

int main() {
	
	ChainStzck<int> cStack;
	for (int i = 0; i < 10; i++) {
		cStack.push(i);
	}
	for (int i = 0; i < 11; i++) {
		std::cout << cStack.pop();
	}

	return 0;

}