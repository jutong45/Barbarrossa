// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
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
A<T>& A<T> :: operator=(A &) {	// 第三个A<T>的参数表（可以）被省略，因为类域名字后面被视为类域内部
	cout << "operator=()";
	return * this;
}
int main() {
	A<int> a1;
	A<int> a2;
	a2= a1;
}
