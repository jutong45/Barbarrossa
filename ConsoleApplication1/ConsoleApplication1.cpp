// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
using std::string;

// 命名模板参数功能：匹配模板参数时，不是按照模板实参的位置，而是根据提供的名字

// 首先，声明一个类，用来存放所有默认值，供派生类覆盖
class AllDefaultParam {	// 保存所有备选默认值
public:
	typedef int SKY;
	typedef char EARTH;
	typedef double HUMAN;
};

// 然后，为每个模板参数都构造一个用来修改默认值的类模板。它们派生自默认值类，通过覆盖基类的成员类型的方式，将一个新值替换掉对应的默认值
template <typename T>
class Sky_is :public virtual AllDefaultParam {	// 用于覆盖基类中的同名方法
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

// 由于每替换一个默认值就需要继承一个默认值类，而任何类只能直接继承一次，所以需要让一个类型变成不同类型
template <typename T, int Luanshu>
class LuanshuBaozhuang :public virtual T {	// 用乱数包装一个类，用以避免直接基类冲突。用不同乱数所生产的类型其实完全相同，但却被视为不同类型。
};

// 通过这个整合成完整参数表 
template <typename SKY, typename EARTH, typename HUMAN>	
class Param :public SKY,public EARTH,public HUMAN {	// 用于合成完整实参
};


// 下面是两种用户使用该机制的代码，1是我们的版本，2是《Template》的版本
template <typename SKY= LuanshuBaozhuang<AllDefaultParam, 1>, 
		  typename EARTH= LuanshuBaozhuang<AllDefaultParam, 33>, 
		  typename HUMAN= LuanshuBaozhuang<AllDefaultParam, 555>>
class UserClass :public Param<SKY,EARTH,HUMAN> {	// 用户类
public:
	static void fn() {
		cout << typeid(EARTH).name();	// 通过 SKY、EARTH、HUMAN 来引用模板参数。成员名字比模板参数名字的优先级高，覆盖了后者
	}
};

template <typename Sky = LuanshuBaozhuang<AllDefaultParam, 1>,
	typename Earth = LuanshuBaozhuang<AllDefaultParam, 33>,
	typename Human = LuanshuBaozhuang<AllDefaultParam, 555>>
class UserClass2 {	// 用户类
public:
	typedef  Param<Sky, Earth, Human> Arg;	// 通过 Arg::SKY、Arg::EARTH、Arg::HUMAN 来引用模板参数
};


int main() {
	UserClass<Earth_is<char *>>::fn();	// 写法简单，但采用继承方式会导致内存开销

	cout << typeid(UserClass2<Earth_is<char *>>::Arg::EARTH).name();	// 写法虽稍繁琐，但类内无垃圾开销
}
