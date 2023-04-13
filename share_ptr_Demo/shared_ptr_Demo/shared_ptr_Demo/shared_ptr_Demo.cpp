// shared_ptr_Demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>

using namespace std;

class Parent;
class Child;

typedef shared_ptr<Parent> parent_ptr;
typedef shared_ptr<Child> child_ptr;

class Parent
{
public:
	~Parent() {
		cout << "~Parent()" << endl;
	}
public:
	child_ptr children;
};

class Child
{
public:
	~Child() {
		cout << "~Child()" << endl;
	}
public:
	//parent_ptr parent;		// 这样就导致循环引用，最终内存泄漏
	weak_ptr<Parent> parent;	// 通过weak_ptr解决循环引用问题，不再导致内存泄漏
};

int _tmain(int argc, _TCHAR* argv[])
{	
	{		
		parent_ptr father(new Parent);
		child_ptr son(new Child);

		// 父子互相引用
		father->children = son;
		son->parent = father;

		cout << father.use_count() << endl;  // 引用计数为2
		cout << son.use_count() << endl;     // 引用计数为2
	}

	getchar();
	getchar();
	return 0;
}



/*
#include "stdafx.h"
#include <iostream>
#include <memory>

int _tmain(int argc, _TCHAR* argv[])
{
	//指针悬空的老问题
	//问题：ref将指向未定义的数据！
	int* ptr = new int(10);
	int* ref = ptr;
	delete ptr;

	//新的
	//解决方案：检查expired（）或lock（）以确定指针是否有效

	//空定义
	std::shared_ptr<int> sptr;

	//取得指针的所有权
	sptr.reset(new int);
	*sptr = 10;

	//获取指向数据的指针而不获取所有权
	std::weak_ptr<int> weak1 = sptr;

	//删除托管对象，获取新指针
	sptr.reset(new int);
	*sptr = 5;

	//获取指向新数据的指针而不获取所有权
	std::weak_ptr<int> weak2 = sptr;
	std::cout << "value is " << *sptr << "	use_count " << sptr.use_count() << '\n';

	//weak1过期了！
	if (auto tmp = weak1.lock())
		std::cout << "value is " << *tmp << "use_count " << tmp.use_count() << '\n';
	else
		std::cout << "weak1 is expired\n";

	//weak2指向新数据（5）
	if (auto tmp = weak2.lock())
		std::cout << "value is " << *tmp << "	tmp use_count " << tmp.use_count() << "		sptr use_count " << sptr.use_count() << '\n';
	else
		std::cout << "weak2 is expired\n";

	getchar();
	getchar();
	return 0;
}
*/

/*
#include "stdafx.h"
#include <iostream>
#include <type_traits>
int _tmain(int argc, _TCHAR* argv[])
{
	class A {};
	class B : public A {};
	class C {};

	bool b2a = std::is_convertible<B*, A*>::value;
	bool a2b = std::is_convertible<A*, B*>::value;
	bool b2c = std::is_convertible<B*, C*>::value;
	bool voidToVoid = std::is_convertible<void, void>::value;

	std::cout << std::boolalpha;
	std::cout << b2a << '\n';
	std::cout << a2b << '\n';
	std::cout << b2c << '\n';
	std::cout << voidToVoid << '\n';

	std::cout << "int to const int:"
		<< std::is_convertible<int, const int>::value
		<< std::endl;


	std::cout << "const int to int:"
		<< std::is_convertible<const int, int>::value
		<< std::endl;

	getchar();
	getchar();
	return 0;
}
*/

