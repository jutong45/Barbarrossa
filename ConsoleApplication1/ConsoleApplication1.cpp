// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;



class A {
protected:
	int n;
	friend void fn(A *pa);	// 友元
};
void fn(A *pa) {
	pa->n = 10;	// 可以访问 protected 成员
	cout << "赋值 proteced 成员";
}

int main(){
	A a;
	fn(&a);

	cout << "!";
    return 0;
}

