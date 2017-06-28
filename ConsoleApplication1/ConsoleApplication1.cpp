// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;


// 对象数组初始化

class A {
	int n;
public:
//	A() {};
	A (int n,int m) :n(n){};	// ctor
};


int main(){
	A *pa = new A[]{A(1,2), A(1,3), A(3,3)};	// 堆数组初始化，与栈数组的语法有区别

	delete ((A*)0);	// 可以删除空指针，效果等于空语句
	cout << "!";
    return 0;
}

