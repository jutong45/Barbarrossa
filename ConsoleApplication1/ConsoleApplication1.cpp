// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;


// delete[]到底是什么，为什么说它是表达式？


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
	delete[] pb;	// 这可不是 operator delete[]，确实是表达式

	cout << "!\n";
}