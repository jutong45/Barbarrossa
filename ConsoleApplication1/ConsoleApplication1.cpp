// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;



class A {
protected:
	int n;
	friend void fn(A *pa);	// ��Ԫ
};
void fn(A *pa) {
	pa->n = 10;	// ���Է��� protected ��Ա
	cout << "��ֵ proteced ��Ա";
}

int main(){
	A a;
	fn(&a);

	cout << "!";
    return 0;
}

