// shared_ptr_Demo.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//parent_ptr parent;		// �����͵���ѭ�����ã������ڴ�й©
	weak_ptr<Parent> parent;	// ͨ��weak_ptr���ѭ���������⣬���ٵ����ڴ�й©
};

int _tmain(int argc, _TCHAR* argv[])
{	
	{		
		parent_ptr father(new Parent);
		child_ptr son(new Child);

		// ���ӻ�������
		father->children = son;
		son->parent = father;

		cout << father.use_count() << endl;  // ���ü���Ϊ2
		cout << son.use_count() << endl;     // ���ü���Ϊ2
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
	//ָ�����յ�������
	//���⣺ref��ָ��δ��������ݣ�
	int* ptr = new int(10);
	int* ref = ptr;
	delete ptr;

	//�µ�
	//������������expired������lock������ȷ��ָ���Ƿ���Ч

	//�ն���
	std::shared_ptr<int> sptr;

	//ȡ��ָ�������Ȩ
	sptr.reset(new int);
	*sptr = 10;

	//��ȡָ�����ݵ�ָ�������ȡ����Ȩ
	std::weak_ptr<int> weak1 = sptr;

	//ɾ���йܶ��󣬻�ȡ��ָ��
	sptr.reset(new int);
	*sptr = 5;

	//��ȡָ�������ݵ�ָ�������ȡ����Ȩ
	std::weak_ptr<int> weak2 = sptr;
	std::cout << "value is " << *sptr << "	use_count " << sptr.use_count() << '\n';

	//weak1�����ˣ�
	if (auto tmp = weak1.lock())
		std::cout << "value is " << *tmp << "use_count " << tmp.use_count() << '\n';
	else
		std::cout << "weak1 is expired\n";

	//weak2ָ�������ݣ�5��
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

