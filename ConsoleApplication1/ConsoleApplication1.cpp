// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

// 一维数组转型为二维
int a[10] = { 0,1,2,3,4,5,6 };	// 一维数组

void fn(int a[][5]) {		// 形参是二维数组（实际退化为指向一维数组的指针）
	cout << a[0][1];
}
int main() {
	fn((int (*)[5])a);	// 将一维数组转型为二维传递给函数
}