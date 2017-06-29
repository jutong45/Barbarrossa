// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;


// delete[]������ʲô��Ϊʲô˵���Ǳ��ʽ��


struct B {
public:
	virtual ~B() { 
		cout << "B's dtor\n"; 
	}
	void operator delete[](void* p, std::size_t n) {
		cout << "B's operator delete[]\n";
		::operator delete[](p); 
	}
};
struct D : B {
public:
	~D() { 
		cout << "D's dtor\n"; 
	}
	void operator delete[](void* p, std::size_t n) {
		cout << "D's operator delete[]\n";
		::operator delete[](p); 
	}
};
int main() {
	/*
	D* dp = new D[3];
	delete[] dp; // uses D::operator delete[](void*, std::size_t)
	B* bp = new D[3];
	delete[] bp; // undefined behavior
	*/

	B* pb = new B[3];
	delete[] pb;	// ��ɲ��� operator delete[]��ȷʵ�Ǳ��ʽ

	cout << "!\n";
}