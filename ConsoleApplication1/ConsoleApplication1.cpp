// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;


// 类对象用传统写法（C）初始化

class A {

public:	// 如果含有 private 数据成员则不能
	int n;
private:
	int j;
public:
	int m;
	A(int n, int m) :n(n), m(m) {};	// 决定了后面初始化的写法是合法的

};

A aa[] = { {1,2},{3,4} };	// 其实是 ctor 的参数列表
int main(){
	
	cout << aa[1].m;
    return 0;
}

