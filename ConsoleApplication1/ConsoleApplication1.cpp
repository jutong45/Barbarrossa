// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;

// �����ͳ�Ա�ĳ�ʼ������

class A {
public:
	int & rn;
	int const N;
	int * pn;
	
//	A(int & rn) :rn(rn) { cout << "in my ctor"; };
	A(int & rn,int *pn=NULL,int n=0) :rn(rn),pn(pn),N(n) { cout << "in my ctor\n"; };

};
int gn;

// A a;	// �ڴ������ó�Ա������£��޷������޲ι��캯����A::A(void)�����ڡ�
// A a={}; ������ͬ��


A aa ={gn};
A a = {gn, &gn};

int main(){
	cout << "!";
    return 0;
}

