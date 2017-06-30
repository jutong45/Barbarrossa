// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;


// operator++()

class Point {
public:
	int x;
	int y;
	Point& operator ++() {
		this->x++;
		this->y++;

		cout <<"x:" <<this->x <<"\t y:" << this -> y <<"\n";
		return (*this);
	}
};
void Show(Point &p) {
	cout << "x:" << p.x << "\t y:" << p.y <<"\n";
}
int main() {
	int n = 5;
	cout << ++n++ << "\n";	// 错误语句，因为 n++ 的值不是左值，不能作为 ++n 的操作数

	Point pixel = {3,9};
	Show(pixel);
	Show(++pixel);
}