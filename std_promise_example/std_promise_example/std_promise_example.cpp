// std_promise_example.cpp : 定义控制台应用程序的入口点。

//一、std::promise介绍

//std::promise 是C++11并发编程中常用的一个类，常配合std::future使用。其作用是在一个线程t1中保存一个类型typename T的值，可供相绑定的std::future对象在另一线程t2中获取。

//二、代码示例：
//下面我们通过几个简单小例子逐渐深入了解std::promise的使用方法。

/*
//示例1：
#include "stdafx.h"
#include <iostream>
#include <future>
#include <chrono>

void Thread_Fun1(std::promise<int> &p)
{
	//为了突出效果，可以使线程休眠5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	int iVal = 233;
	std::cout << "传入数据(int)：" << iVal << std::endl;

	//传入数据iVal
	p.set_value(iVal);
}

void Thread_Fun2(std::future<int> &f)
{
	//阻塞函数，直到收到相关联的std::promise对象传入的数据
	auto iVal = f.get();		//iVal = 233

	std::cout << "收到数据(int)：" << iVal << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//声明一个std::promise对象pr1，其保存的值类型为int
	std::promise<int> pr1;
	//声明一个std::future对象fu1，并通过std::promise的get_future()函数与pr1绑定
	std::future<int> fu1 = pr1.get_future();

	//创建一个线程t1，将函数Thread_Fun1及对象pr1放在线程里面执行
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//创建一个线程t2，将函数Thread_Fun2及对象fu1放在线程里面执行
	std::thread t2(Thread_Fun2, std::ref(fu1));

	//阻塞至线程结束
	t1.join();
	t2.join();
	getchar();
	getchar();
	return 1;
}
//可以看到std::future对象fu1先是通过std::promise的函数get_future()与std::promise对象pr1相绑定，pr1在线程t1中通过set_value()传入共享数据，fu1在线程t2中通过阻塞函数get()获取到传入的数据。
//示例1中传入的数据类型是int，前面介绍中说std::promise可以保存typename T的数据，那么可以保存函数指针吗？答案是可行的，请看示例。
*/




//示例2：
#include "stdafx.h"
#include <iostream>
#include <future>
#include <chrono>
#include <functional>

//声明一个可调对象T
using T = std::function < int(int) > ;		//等同于typedef std::function<int(int)> T;

int Test_Fun(int iVal)
{
	std::cout << "Value is:" << iVal << std::endl;
	return iVal + 232;
}

void Thread_Fun1(std::promise<T> &p)
{
	//为了突出效果，可以使线程休眠5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	std::cout << "传入函数Test_Fun" << std::endl;

	//传入函数Test_Fun
	p.set_value(std::bind(&Test_Fun, std::placeholders::_1));
}

void Thread_Fun2(std::future<T> &f)
{
	//阻塞函数，直到收到相关联的std::promise对象传入的数据
	auto fun = f.get();		//iVal = 233

	int iVal = fun(1);

	std::cout << "收到函数并运行，结果：" << iVal << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//声明一个std::promise对象pr1，其保存的值类型为int
	std::promise<T> pr1;
	//声明一个std::future对象fu1，并通过std::promise的get_future()函数与pr1绑定
	std::future<T> fu1 = pr1.get_future();

	//创建一个线程t1，将函数Thread_Fun1及对象pr1放在线程里面执行
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//创建一个线程t2，将函数Thread_Fun2及对象fu1放在线程里面执行
	std::thread t2(Thread_Fun2, std::ref(fu1));

	//阻塞至线程结束
	t1.join();
	t2.join();
	getchar();
	getchar();
	return 1;
}
//既然可以传函数对象，那么是否可以通过模板魔改，传入可变元函数？请看示例。





/*
//示例3：
#include "stdafx.h"
#include <iostream>
#include <future>
#include <chrono>
#include <functional>

//声明一个可调对象F
using F = std::function < int(int, int, int&) > ;		//等同于typedef std::function<int(int, int, int&)> F;

//函数可以改成任意参数，任意返回类型
int Test_Fun(int a, int b, int &c)
{
	//a = 1, b = 2
	c = a + b + 230;
	return c;
}

void Thread_Fun1(std::promise<F> &p)
{
	//为了突出效果，可以使线程休眠5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	std::cout << "传入函数Test_Fun" << std::endl;

	//传入函数Test_Fun
	p.set_value(std::bind(&Test_Fun, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

template<typename T, typename ...Args>
void Thread_Fun2(std::future<T> &f, Args ...args)
{
	//阻塞函数，直到收到相关联的std::promise对象传入的数据
	auto fun = f.get();		//fun等同于Test_Fun

	auto fResult = fun(std::forward<Args>(args)...);

	std::cout << "收到函数并运行，结果：" << fResult << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//声明一个std::promise对象pr1，其保存的值类型为int
	std::promise<F> pr1;
	//声明一个std::future对象fu1，并通过std::promise的get_future()函数与pr1绑定
	std::future<F> fu1 = pr1.get_future();

	//声明一个变量
	int iVal = 0;

	//创建一个线程t1，将函数Thread_Fun1及对象pr1放在线程里面执行
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//创建一个线程t2，将函数Thread_Fun2及对象fu1放在线程里面执行
	std::thread t2(Thread_Fun2<F, int, int, int&>, std::ref(fu1), 1, 2, std::ref(iVal));	

	//阻塞至线程结束
	t1.join();
	t2.join();

	//输出引用后的iVal
	std::cout << "iVal Is " << iVal << std::endl;

	getchar();
	getchar();
	//此时iVal的值变成233

	return 1;
}
*/