// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;

// һά����ת��Ϊ��ά
int a[10] = { 0,1,2,3,4,5,6 };	// һά����

void fn(int a[][5]) {		// �β��Ƕ�ά���飨ʵ���˻�Ϊָ��һά�����ָ�룩
	cout << a[0][1];
}
int main() {
	fn((int (*)[5])a);	// ��һά����ת��Ϊ��ά���ݸ�����
}