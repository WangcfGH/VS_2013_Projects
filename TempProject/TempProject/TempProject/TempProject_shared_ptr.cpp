// TempProject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdarg>
#include <memory>
#include <iomanip>
#include <sstream>
#include <time.h>
using namespace std;

/******************C�ɱ����******************/
void print(int num ...)
{
	va_list ap;
	va_start(ap, num);
	for (int i = 0; i < num; i++)
	{
		cout << va_arg(ap, int) << endl;
	}
	va_end(ap);
}
/*********************************************/



/******C++�ɱ�ģ���������(std::forwardչ��������)******/
template<typename typeMySelf>
int expandPrint(typeMySelf agrsValue)
{
	cout << agrsValue << endl;
	return 3;
}

template<typename... Args>
void expand(Args... args)
{
	std::initializer_list<int> retList = std::initializer_list<int>{(expandPrint(std::forward<Args>(args)))...};
	//std::initializer_list<int> retList = std::initializer_list<int>{std::forward<Args>(args)...};
}
/*********************************************/



/******C++�ɱ�ģ���������(�ݹ麯����ʽչ��)******/
template <class T>
void printarg(T&& t)
{
	std::cout << t << std::endl;
}

template<typename T>
void processValues(T &&arg)
{
	printarg(std::forward<T>(arg));
}

template<typename T, typename... Ts>
void processValues(T &&arg, Ts&& ...args)
{
	printarg(std::forward<T>(arg));
	processValues(std::forward<Ts>(args)...);
}
/*********************************************/



/****************C++�ɱ����ģ��ʵ����ί�У�****************/
template<class T, class R, typename ...Args>
class MyDelegate
{
public:
	MyDelegate(T* t, R(T::*f)(Args...)) :m_t(t), m_f(f){}

	R operator()(Args&&... args)
	{
		return (m_t->*m_f)(std::forward<Args>(args)...);
	}

private:
	T* m_t;
	R(T::*m_f)(Args...);
};

template<class T, class R, typename... Args>
MyDelegate<T, R, Args...> CreateDelegate(T* t, R(T::*f)(Args...))
{
	return MyDelegate<T, R, Args...>(t, f);
}

struct A
{
	void Fun(int i){ cout << i << endl; }
	void Fun1(int i, double j){ cout << i + j << endl; }
};
/**************************************************************/








int _tmain(int argc, _TCHAR* argv[])
{
	// C�ɱ����
	print(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << std::endl;

	expand("Std::Forward Expand", 5.20, 1024);
	//expand(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << std::endl;

	// C++�ɱ�ģ���������(�ݹ麯����ʽչ��)
	processValues("DiGui Expand", 5.20, 1024);
	std::cout << std::endl;

	// C++�ɱ����ģ��ʵ����ί�У�
	A a;
	auto d = CreateDelegate(&a, &A::Fun);		//����ί��
	d(1);										//����ί�У������1
	auto d1 = CreateDelegate(&a, &A::Fun1);		//����ί��
	d1(1, 2.5);									//����ί�У������3.5
	std::cout << std::endl;

// 	tm tm_;
// 	time_t timestamp_ = time(nullptr);	
// 	localtime_s(&tm_, &timestamp_);
// 	tm t = std::move(tm_);
// 	std::stringstream ss;
// 	ss << std::put_time(&t, "%Y%m");
// 	std::string strTime = ss.str();
// 	std::cout << strTime << std::endl;
// 	std::string strTemp("ceshi");
// 	int nRet = strTemp.compare("ceshi");

	getchar();
	getchar();
	return 0;
}



///********************make_shared&&shared_ptr********************************/
//// TEMPLATE FUNCTION make_shared
//template<class _Ty, class... _Types>
//inline shared_ptr<_Ty> make_shared(_Types&&... _Args)
//{    // make a shared_ptr
//	_Ref_count_obj<_Ty> *_Rx = new _Ref_count_obj<_Ty>(_STD forward<_Types>(_Args)...);
//
//	shared_ptr<_Ty> _Ret;
//	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
//	return (_Ret);
//}
//
//template<class... _Types>
//_Ref_count_obj(_Types&&... _Args) : _Ref_count_base()
//{    // construct from argument list
//	::new ((void *)&_Storage) _Ty(_STD forward<_Types>(_Args)...);
//}
//
////std::shared_ptr<TestShared>(new TestShared()) ���룺
//template<class _Ux>
//explicit shared_ptr(_Ux *_Px)
//{    // construct shared_ptr object that owns _Px
//	_Resetp(_Px);
//}
//
//template<class _Ux>
//void _Resetp(_Ux *_Px)
//{    // release, take ownership of _Px
//	_TRY_BEGIN    // allocate control block and reset
//		_Resetp0(_Px, new _Ref_count<_Ux>(_Px));
//	_CATCH_ALL    // allocation failed, delete resource
//		delete _Px;
//	_RERAISE;
//	_CATCH_END
//}
///*************************************************************************/