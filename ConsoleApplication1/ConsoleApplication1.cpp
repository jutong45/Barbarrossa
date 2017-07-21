// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
using std::string;

template <int N=8>
class B {
	// static int n=N;
public:
	B() {
		cout << "B's ctor\n";
	}
};

template <template <int>class T,int N=10>
class D :public T<N> {
public:
	D():T<N>() {
		cout << "the ctor of D \n";
	};
};
// template void A<int>::fn<int>(int,int);	// 显式实例化

int main() {
	D<B> *pD = new D<B>;
}
