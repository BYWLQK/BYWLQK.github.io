#include"SequentialStack.cpp"
#include<iostream>
#include<string>
using namespace std;

int toInt(SequentialStack<char>& stackT);
int result(SequentialStack<char>& stackT);

int toBool(char m) {
	if (m == '*' || m == '/') {
		return 2;
	}
	else {
		return 1;
	}
}

int main() {

	SequentialStack<char> sStack,postexp;
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
				postexp.push(cht);
				if (postexp.GetTop() >= '0' && postexp.GetTop() <= '9') {
					s2 += '#';
					postexp.push('#');
				}
			}
			else {
				s2+=cht;
				postexp.push(cht);
			}
		}
		else if (sStack.StackEmpty()) {
			if (cht != '('){
				if (postexp.GetTop() >= '0' && postexp.GetTop() <= '9') {
					s2 += '#';
					postexp.push('#');
				}
			}
				
			sStack.push(cht);
		}
		else if (sStack.GetTop() == '(') {
			if (postexp.GetTop() >= '0' && postexp.GetTop() <= '9') {
				s2 += '#';
				postexp.push('#');
			}
			sStack.push(cht);
		}
		else if (cht != '(' && cht != ')') {
			if (toBool(cht) > toBool(sStack.GetTop())) {
				if (postexp.GetTop() >= '0' && postexp.GetTop() <= '9') {
					s2 += '#';
					postexp.push('#');
				}
				sStack.push(cht);
			}
			else {
				if(postexp.GetTop()>='0'&&postexp.GetTop()<='9'){
					s2+='#';
					postexp.push('#');
				}
				char t = sStack.pop();
				s2 += t;
				postexp.push(t);
				sStack.push(cht);
			}
		}
		else if (cht=='(') {	
			sStack.push(cht);
		}
		else if (cht==')') {
			if (postexp.GetTop() >= '0' && postexp.GetTop() <= '9') {
				s2 += '#';
				postexp.push('#');
			}
			char t = sStack.pop();
			s2 += t;
			postexp.push(t);
			sStack.pop();
		}
	}
	while (!sStack.StackEmpty()) {
		char t = sStack.pop();
		s2 += t;
		postexp.push(t);
	}
	cout<<s2<<endl;
	cout<<"结果为：";
	cout<<result(postexp);

	getchar();
	getchar();


	return 0;
}

int result(SequentialStack<char>& stackT){
	int m,n;
	char ch =stackT.pop();
	if (!stackT.StackEmpty()) {
		m = stackT.GetTop() == '#' ? toInt(stackT) : result(stackT);
		n = stackT.GetTop() == '#' ? toInt(stackT) : result(stackT);
	}
	else {
		return 0;
	}
	switch(ch){
	case'+':
		return n+m;
	case'-':
		return n-m;
	case'*':
		return n*m;
	case'/':
		return n/m;
	default: return 0;
	}
}

int toInt(SequentialStack<char>& stackT){
	int x=0;
	int k=1;
	stackT.pop();
	while(!stackT.StackEmpty()&&stackT.GetTop()>='0'&&stackT.GetTop()<='9'){
		x+=(stackT.pop()-'0')*k;
		k*=10;
	}
	return x;
}