// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << ++n++ << "\n";	// ������䣬��Ϊ n++ ��ֵ������ֵ��������Ϊ ++n �Ĳ�����

	Point pixel = {3,9};
	Show(pixel);
	Show(++pixel);
}