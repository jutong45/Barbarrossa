// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

// 引用型成员的初始化问题

class A {
public:
	int & rn;
	int const N;
	int * pn;
	
//	A(int & rn) :rn(rn) { cout << "in my ctor"; };
	A(int & rn,int *pn=NULL,int n=0) :rn(rn),pn(pn),N(n) { cout << "in my ctor\n"; };

};
int gn;

// A a;	// 在存在引用成员的情况下，无法生成无参构造函数，A::A(void)不存在。
// A a={}; 错，理由同上


A aa ={gn};
A a = {gn, &gn};

int main(){
	cout << "!";
    return 0;
}

