// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;

// ��������

void Show() {
	cout << "hi\n";
}
int main() {
	void(*pfn)() =Show;
	void (&rfn) () = Show;
	pfn();
	rfn();
}