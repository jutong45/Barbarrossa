// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;


// 新标准下，枚举类型可以用“类型::值”的方式访问了

class A {

public:
	static enum E { e1 };	// static 类型是什么鬼？
};


int main(){
	cout << A::E::e1;	// 没错，枚举值可以用“类型::值”的方式访问了，可以避免重名混乱
	cout << A::e1;	// 老方式
    return 0;
}

