// std_promise_example.cpp : �������̨Ӧ�ó������ڵ㡣

//һ��std::promise����

//std::promise ��C++11��������г��õ�һ���࣬�����std::futureʹ�á�����������һ���߳�t1�б���һ������typename T��ֵ���ɹ���󶨵�std::future��������һ�߳�t2�л�ȡ��

//��������ʾ����
//��������ͨ��������С�����������˽�std::promise��ʹ�÷�����

/*
//ʾ��1��
#include "stdafx.h"
#include <iostream>
#include <future>
#include <chrono>

void Thread_Fun1(std::promise<int> &p)
{
	//Ϊ��ͻ��Ч��������ʹ�߳�����5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	int iVal = 233;
	std::cout << "��������(int)��" << iVal << std::endl;

	//��������iVal
	p.set_value(iVal);
}

void Thread_Fun2(std::future<int> &f)
{
	//����������ֱ���յ��������std::promise�����������
	auto iVal = f.get();		//iVal = 233

	std::cout << "�յ�����(int)��" << iVal << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//����һ��std::promise����pr1���䱣���ֵ����Ϊint
	std::promise<int> pr1;
	//����һ��std::future����fu1����ͨ��std::promise��get_future()������pr1��
	std::future<int> fu1 = pr1.get_future();

	//����һ���߳�t1��������Thread_Fun1������pr1�����߳�����ִ��
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//����һ���߳�t2��������Thread_Fun2������fu1�����߳�����ִ��
	std::thread t2(Thread_Fun2, std::ref(fu1));

	//�������߳̽���
	t1.join();
	t2.join();
	getchar();
	getchar();
	return 1;
}
//���Կ���std::future����fu1����ͨ��std::promise�ĺ���get_future()��std::promise����pr1��󶨣�pr1���߳�t1��ͨ��set_value()���빲�����ݣ�fu1���߳�t2��ͨ����������get()��ȡ����������ݡ�
//ʾ��1�д��������������int��ǰ�������˵std::promise���Ա���typename T�����ݣ���ô���Ա��溯��ָ���𣿴��ǿ��еģ��뿴ʾ����
*/




//ʾ��2��
#include "stdafx.h"
#include <iostream>
#include <future>
#include <chrono>
#include <functional>

//����һ���ɵ�����T
using T = std::function < int(int) > ;		//��ͬ��typedef std::function<int(int)> T;

int Test_Fun(int iVal)
{
	std::cout << "Value is:" << iVal << std::endl;
	return iVal + 232;
}

void Thread_Fun1(std::promise<T> &p)
{
	//Ϊ��ͻ��Ч��������ʹ�߳�����5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	std::cout << "���뺯��Test_Fun" << std::endl;

	//���뺯��Test_Fun
	p.set_value(std::bind(&Test_Fun, std::placeholders::_1));
}

void Thread_Fun2(std::future<T> &f)
{
	//����������ֱ���յ��������std::promise�����������
	auto fun = f.get();		//iVal = 233

	int iVal = fun(1);

	std::cout << "�յ����������У������" << iVal << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//����һ��std::promise����pr1���䱣���ֵ����Ϊint
	std::promise<T> pr1;
	//����һ��std::future����fu1����ͨ��std::promise��get_future()������pr1��
	std::future<T> fu1 = pr1.get_future();

	//����һ���߳�t1��������Thread_Fun1������pr1�����߳�����ִ��
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//����һ���߳�t2��������Thread_Fun2������fu1�����߳�����ִ��
	std::thread t2(Thread_Fun2, std::ref(fu1));

	//�������߳̽���
	t1.join();
	t2.join();
	getchar();
	getchar();
	return 1;
}
//��Ȼ���Դ�����������ô�Ƿ����ͨ��ģ��ħ�ģ�����ɱ�Ԫ�������뿴ʾ����





/*
//ʾ��3��
#include "stdafx.h"
#include <iostream>
#include <future>
#include <chrono>
#include <functional>

//����һ���ɵ�����F
using F = std::function < int(int, int, int&) > ;		//��ͬ��typedef std::function<int(int, int, int&)> F;

//�������Ըĳ�������������ⷵ������
int Test_Fun(int a, int b, int &c)
{
	//a = 1, b = 2
	c = a + b + 230;
	return c;
}

void Thread_Fun1(std::promise<F> &p)
{
	//Ϊ��ͻ��Ч��������ʹ�߳�����5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	std::cout << "���뺯��Test_Fun" << std::endl;

	//���뺯��Test_Fun
	p.set_value(std::bind(&Test_Fun, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

template<typename T, typename ...Args>
void Thread_Fun2(std::future<T> &f, Args ...args)
{
	//����������ֱ���յ��������std::promise�����������
	auto fun = f.get();		//fun��ͬ��Test_Fun

	auto fResult = fun(std::forward<Args>(args)...);

	std::cout << "�յ����������У������" << fResult << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//����һ��std::promise����pr1���䱣���ֵ����Ϊint
	std::promise<F> pr1;
	//����һ��std::future����fu1����ͨ��std::promise��get_future()������pr1��
	std::future<F> fu1 = pr1.get_future();

	//����һ������
	int iVal = 0;

	//����һ���߳�t1��������Thread_Fun1������pr1�����߳�����ִ��
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//����һ���߳�t2��������Thread_Fun2������fu1�����߳�����ִ��
	std::thread t2(Thread_Fun2<F, int, int, int&>, std::ref(fu1), 1, 2, std::ref(iVal));	

	//�������߳̽���
	t1.join();
	t2.join();

	//������ú��iVal
	std::cout << "iVal Is " << iVal << std::endl;

	getchar();
	getchar();
	//��ʱiVal��ֵ���233

	return 1;
}
*/