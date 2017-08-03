// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

using namespace std;
// -------------------------

// 模板参数类型的const、引用去平方，void 类型的安全使用接口
template <typename T>	// 基本模板
class TypeOp {	
public:
	typedef T ArgT;
	typedef T & RefT;
	typedef T const ConstT;
	typedef T const & RefConstT;
};

template <typename T>
class TypeOp<T const> {	// 针对 const 型模板参数的特化
	typedef T const ArgT;
	typedef T & RefT;
	typedef T const ConstT;
	typedef T const & RefConstT;
};

template <typename T>
class TypeOp<T &> {	// 针对引用型 模板参数的特化
	typedef T & ArgT;
	typedef T & RefT;
	typedef T const ConstT;
	typedef T const & RefConstT;
};

 template<> 
 class TypeOp<void> {	// 针对 void 模板参数的特化，因为 C++ 不允许 void & 类型:
	 typedef void ArgT;
	 typedef void const ConstT;
	 typedef void	RefT;
	 typedef void const RefConstT;
 };

// 以上代码并未被后面程序用到 
// -------------------------

template <typename T1,typename T2>
class Duo {
public:
	Duo() {
		cout << "Duo ctor\n";
	}
	Duo(T1,T2) {
		cout << "Duo ctor with 2 arg\n";
	}
};

class NullT {
};

template <typename P0,typename P1 = NullT,typename P2 = NullT,typename P3 = NullT,typename P4 = NullT>
class Tuple :public Duo < P0, typename Tuple<P1, P2, P3, P4, NullT>::BaseT>{
public:
	typedef Duo < P0, typename Tuple<P1, P2, P3, P4, NullT> ::BaseT> BaseT;
	Tuple() {}
	Tuple( P0 const & a0,
		P1 const & a1, 
		P2 const & a2 = NullT(), 
		P3 const & a3 = NullT(),
		P4 const & a4 = NullT())	// 有3个默认参数值，元组允许最少两个元素
		:BaseT (a0, Tuple<P1,P2,P3,P4,NullT>(a1,a2,a3,a4)){}
};

template <typename p1,typename p2>
class Tuple<p1, p2, NullT, NullT, NullT> :public Duo<p1,p2> {	// 基本模板的默认参数无效吗，这里为何要显式写出后3个默认模板参数值？
public:
	typedef Duo<p1, p2> BaseT;
	Tuple(p1 const & a0,
		p2 const & a1,
		NullT const & a2 = NullT(),
		NullT const & a3 = NullT(),
		NullT const & a4 = NullT())	// 为什么有3个默认参数值？
		:BaseT () {}
};

int main() {
	Tuple<bool, int, bool, double> t4(true, 3, true, 0.9);
}
