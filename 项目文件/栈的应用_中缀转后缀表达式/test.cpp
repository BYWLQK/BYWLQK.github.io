#include"SequentialStack.cpp"
#include<iostream>
#include<string>
using namespace std;

int toInt(char m) {
	if (m == '*' || m == '/') {
		return 2;
	}
	else {
		return 1;
	}
}

int main() {

	SequentialStack<char> sStack;
	string s1 = "";
	string s2 = "";
	cout << "请输入表达式：" << endl;
	cin >> s1;

	for (int i = 0; i < s1.size(); i++) {
		char cht = s1.at(i);
		int it = -1;
		if (cht >= '0' && cht <= '9') {
			if (i == s1.size() - 1) {
				s2 += cht;
				s2 += "#";
			}
			else {
				s2 += cht;
			}
			
		}
		else if (sStack.StackEmpty()) {
			if (cht != '('&&s1.at(i)<='9'&&s1.at(i)>='0')
				s2 += "#";
			sStack.push(cht);
		}
		else if (sStack.GetTop() == '(') {
			s2 += "#";
			sStack.push(cht);
		}
		else if (cht != '(' && cht != ')') {
			s2 += "#";
			if (toInt(cht) > toInt(sStack.GetTop())) {
				sStack.push(cht);
			}
			else {
				s2 += sStack.pop();
				sStack.push(cht);
			}
		}
		else if (cht=='(') {	
			sStack.push(cht);
		}
		else if (cht==')') {
			s2 += "#";
			s2+=sStack.pop();
			sStack.pop();
		}
	}
	while (!sStack.StackEmpty()) {
		s2 += sStack.pop();
	}
	cout << s2 << endl;

	return 0;
}