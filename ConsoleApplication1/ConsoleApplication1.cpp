// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;


// �±�׼�£�ö�����Ϳ����á�����::ֵ���ķ�ʽ������

class A {

public:
	static enum E { e1 };	// static ������ʲô��
};


int main(){
	cout << A::E::e1;	// û��ö��ֵ�����á�����::ֵ���ķ�ʽ�����ˣ����Ա�����������
	cout << A::e1;	// �Ϸ�ʽ
    return 0;
}

