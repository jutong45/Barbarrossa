// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;


// ���������ʼ��

class A {
	int n;
public:
//	A() {};
	A (int n,int m) :n(n){};	// ctor
};


int main(){
	A *pa = new A[]{A(1,2), A(1,3), A(3,3)};	// �������ʼ������ջ������﷨������

	delete ((A*)0);	// ����ɾ����ָ�룬Ч�����ڿ����
	cout << "!";
    return 0;
}

