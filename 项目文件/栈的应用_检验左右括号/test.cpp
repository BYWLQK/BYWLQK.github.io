#include"SequentialStack.cpp"
#include<iostream>
#include<string>
using namespace std;

int main() {

	SequentialStack<char> sStack;
	string s = "";
	cout << "��������ʽ��" << endl;
	cin >> s;
	for (int i = 0; i < s.size();i++) {
		char ct = s.at(i);
		if (ct=='(') {
			sStack.push(ct);
		}
		else if(ct == ')') {
			sStack.pop();
		}
	}
	if (sStack.StackEmpty()) {
		cout << "��ȷ";
	}
	else {
		cout << "����";
	}

	return 0;
}