// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define ACCU(x) accu<x>::result

using namespace std;
using std::string;

int n = 9;

auto pn = &n;

template <typename T>
class C {
public:

	T fn(int n) { 
		auto a = T(n);
		return a; 
	}
	
};

int main() {
	C<int> c;
	
	cout << c.fn(9);
}
