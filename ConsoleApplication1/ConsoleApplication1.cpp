// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define ACCU(x) accu<x>::result

using namespace std;
using std::string;
template <typename T>
class A{
public:
	A<T> & operator=(A<T> &);
};

template <typename T>
A<T>& A<T> :: operator=(A &) {	// ������A<T>�Ĳ��������ԣ���ʡ�ԣ���Ϊ�������ֺ��汻��Ϊ�����ڲ�
	cout << "operator=()";
	return * this;
}
int main() {
	A<int> a1;
	A<int> a2;
	a2= a1;
}
