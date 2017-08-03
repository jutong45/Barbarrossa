// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>

using namespace std;
// -------------------------

// ģ��������͵�const������ȥƽ����void ���͵İ�ȫʹ�ýӿ�
template <typename T>	// ����ģ��
class TypeOp {	
public:
	typedef T ArgT;
	typedef T & RefT;
	typedef T const ConstT;
	typedef T const & RefConstT;
};

template <typename T>
class TypeOp<T const> {	// ��� const ��ģ��������ػ�
	typedef T const ArgT;
	typedef T & RefT;
	typedef T const ConstT;
	typedef T const & RefConstT;
};

template <typename T>
class TypeOp<T &> {	// ��������� ģ��������ػ�
	typedef T & ArgT;
	typedef T & RefT;
	typedef T const ConstT;
	typedef T const & RefConstT;
};

 template<> 
 class TypeOp<void> {	// ��� void ģ��������ػ�����Ϊ C++ ������ void & ����:
	 typedef void ArgT;
	 typedef void const ConstT;
	 typedef void	RefT;
	 typedef void const RefConstT;
 };

// ���ϴ��벢δ����������õ� 
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
		P4 const & a4 = NullT())	// ��3��Ĭ�ϲ���ֵ��Ԫ��������������Ԫ��
		:BaseT (a0, Tuple<P1,P2,P3,P4,NullT>(a1,a2,a3,a4)){}
};

template <typename p1,typename p2>
class Tuple<p1, p2, NullT, NullT, NullT> :public Duo<p1,p2> {	// ����ģ���Ĭ�ϲ�����Ч������Ϊ��Ҫ��ʽд����3��Ĭ��ģ�����ֵ��
public:
	typedef Duo<p1, p2> BaseT;
	Tuple(p1 const & a0,
		p2 const & a1,
		NullT const & a2 = NullT(),
		NullT const & a3 = NullT(),
		NullT const & a4 = NullT())	// Ϊʲô��3��Ĭ�ϲ���ֵ��
		:BaseT () {}
};

int main() {
	Tuple<bool, int, bool, double> t4(true, 3, true, 0.9);
}
