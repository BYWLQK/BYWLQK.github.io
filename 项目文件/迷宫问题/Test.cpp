#include"SequentialStack.cpp"
#include<iostream>

using namespace std;

struct Point
{
	size_t m=0;
	size_t n=0;
};

void MazePath(SequentialStack<Point>&path,int maze[][9], Point en, Point ex);

int main() {

	//1、创建迷宫
	int maze[9][9] = { 1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << maze[i][j];
		cout << endl;
	}

	Point en; en.m = 1; en.n = 1; 
	Point ex; ex.m = 6; ex.n = 7;
	SequentialStack<Point> path;
	MazePath(path,maze,en,ex);
	int n = path.size();
	for (int i = 0; i < n; i++) {
		Point t = path.pop();
		cout << "(" << t.m << "," << t.n << ") ";
	}

	return 0;
}

//2、利用栈构建深度优先算法
void MazePath(SequentialStack<Point>&path,int maze[][9], Point en, Point ex) {
	path.push(en);
	Point t;
	while (true) {
		t = path.GetTop();
		if (maze[t.m-1][t.n]==0) {
			maze[t.m][t.n] = -1;
			t.m -= 1;
			path.push(t);
		}
		else if (maze[t.m][t.n+1] == 0) {
			maze[t.m][t.n] = -1;
			t.n += 1;
			path.push(t);
		}
		else if (maze[t.m+1][t.n] == 0) {
			maze[t.m][t.n] = -1;
			t.m += 1;
			path.push(t);
		}
		else if (maze[t.m][t.n-1] == 0) {
			maze[t.m][t.n] = -1;
			t.n -= 1;
			path.push(t);
		}
		else {
			maze[t.m][t.n] = -2;
			path.pop();
			if (path.StackEmpty()) {
				break;
			}
		}
		if (t.m == ex.m && t.n == ex.n)
			break;
	}
}