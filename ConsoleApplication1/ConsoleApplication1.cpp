// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;


// ������ô�ͳд����C����ʼ��

class A {

public:	// ������� private ���ݳ�Ա����
	int n;
private:
	int j;
public:
	int m;
	A(int n, int m) :n(n), m(m) {};	// �����˺����ʼ����д���ǺϷ���

};

A aa[] = { {1,2},{3,4} };	// ��ʵ�� ctor �Ĳ����б�
int main(){
	
	cout << aa[1].m;
    return 0;
}

