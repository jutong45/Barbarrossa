// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;
using std::string;

// ����ģ��������ܣ�ƥ��ģ�����ʱ�����ǰ���ģ��ʵ�ε�λ�ã����Ǹ����ṩ������

// ���ȣ�����һ���࣬�����������Ĭ��ֵ���������า��
class AllDefaultParam {	// �������б�ѡĬ��ֵ
public:
	typedef int SKY;
	typedef char EARTH;
	typedef double HUMAN;
};

// Ȼ��Ϊÿ��ģ�����������һ�������޸�Ĭ��ֵ����ģ�塣����������Ĭ��ֵ�࣬ͨ�����ǻ���ĳ�Ա���͵ķ�ʽ����һ����ֵ�滻����Ӧ��Ĭ��ֵ
template <typename T>
class Sky_is :public virtual AllDefaultParam {	// ���ڸ��ǻ����е�ͬ������
public:
	typedef T SKY;
};
template <typename T>
class Earth_is :public virtual AllDefaultParam {
public:
	typedef T EARTH;
};
template<typename T>
class Human_is :public virtual AllDefaultParam {
public:
	typedef T HUMAN;
};

// ����ÿ�滻һ��Ĭ��ֵ����Ҫ�̳�һ��Ĭ��ֵ�࣬���κ���ֻ��ֱ�Ӽ̳�һ�Σ�������Ҫ��һ�����ͱ�ɲ�ͬ����
template <typename T, int Luanshu>
class LuanshuBaozhuang :public virtual T {	// ��������װһ���࣬���Ա���ֱ�ӻ����ͻ���ò�ͬ������������������ʵ��ȫ��ͬ����ȴ����Ϊ��ͬ���͡�
};

// ͨ��������ϳ����������� 
template <typename SKY, typename EARTH, typename HUMAN>	
class Param :public SKY,public EARTH,public HUMAN {	// ���ںϳ�����ʵ��
};


// �����������û�ʹ�øû��ƵĴ��룬1�����ǵİ汾��2�ǡ�Template���İ汾
template <typename SKY= LuanshuBaozhuang<AllDefaultParam, 1>, 
		  typename EARTH= LuanshuBaozhuang<AllDefaultParam, 33>, 
		  typename HUMAN= LuanshuBaozhuang<AllDefaultParam, 555>>
class UserClass :public Param<SKY,EARTH,HUMAN> {	// �û���
public:
	static void fn() {
		cout << typeid(EARTH).name();	// ͨ�� SKY��EARTH��HUMAN ������ģ���������Ա���ֱ�ģ��������ֵ����ȼ��ߣ������˺���
	}
};

template <typename Sky = LuanshuBaozhuang<AllDefaultParam, 1>,
	typename Earth = LuanshuBaozhuang<AllDefaultParam, 33>,
	typename Human = LuanshuBaozhuang<AllDefaultParam, 555>>
class UserClass2 {	// �û���
public:
	typedef  Param<Sky, Earth, Human> Arg;	// ͨ�� Arg::SKY��Arg::EARTH��Arg::HUMAN ������ģ�����
};


int main() {
	UserClass<Earth_is<char *>>::fn();	// д���򵥣������ü̳з�ʽ�ᵼ���ڴ濪��

	cout << typeid(UserClass2<Earth_is<char *>>::Arg::EARTH).name();	// д�����Է���������������������
}
