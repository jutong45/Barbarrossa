// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define ACCU(x) accu<x>::result

using namespace std;
using std::string;
template <int N>
class accu {
public:
	enum {result= accu<N-1>::result*N};
};


template<>
class accu<1> {
public:
	enum {result=1};
};

int main() {
	cout << ACCU(6);
}
