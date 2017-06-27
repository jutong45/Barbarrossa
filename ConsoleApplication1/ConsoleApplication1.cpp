// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

// 引用型成员的初始化问题

int gn;
int *pn = NULL;	// 依然只有 NULL 宏，并没有“null”保留字，别和 JavaScript 混了

int main(){
	cout << "!";
    return 0;
}

