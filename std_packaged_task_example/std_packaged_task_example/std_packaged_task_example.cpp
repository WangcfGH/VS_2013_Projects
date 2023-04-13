// std_packaged_task_example.cpp : �������̨Ӧ�ó������ڵ㡣

/*
����һƪ�����ǽ�����std::promise��ʹ�÷�������ʵstd::packaged_task��std::promise�ǳ����ƣ�
����˵std::packaged_task<F>�Ƕ�std::promise<T = std::function<F>>��T = std::function<F>��һ�ɵ�����(�纯����lambda���ʽ��)�����˰�װ��
����ʹ�÷�����������һ�ɵ�����ķ��ؽ�����ݸ�������std::future����
������һƪ������std::promise����д��
//����һ���ɵ�����T  
using T = std::function < int(int) > ;        //��ͬ��typedef std::function<int(int)> T;

//����
int Test_Fun(int iVal)
{
	std::cout << "Value is:" << iVal << std::endl;
	return iVal + 232;
}

//����һ��std::promise����pr1���䱣���ֵ����Ϊint  
std::promise<T> pr1;
//����һ��std::future����fu1����ͨ��std::promise��get_future()������pr1��  
std::future<T> fu1 = pr1.get_future();



��ôʹ��std::packaged_task�ͼ��˺ࣺܶ
//����
int Test_Fun(int iVal)
{
	std::cout << "Value is:" << iVal << std::endl;
	return iVal + 232;
}

//����һ��std::packaged_task����pt1����װ����Test_Fun
std::packaged_task<int(int)> pt1(Test_Fun);
//����һ��std::future���󣬰�װTest_Fun�ķ��ؽ��������pt1����
std::future<int> fu1 = pt1.get_future();
ע�⣺ʹ��std::packaged_task������std::future���󱣴�����������ǿɵ�����ķ��ؽ�����ͣ�
��ʾ�������ķ��ؽ��������int����ô����Ϊstd::future<int>��������std::future<int(int)>��
*/






//����ʾ��
#include "stdafx.h"
#include <iostream>
#include <future>
#include <chrono>
#include <functional>

int Test_Fun(int a, int b, int &c)
{
	//a=1,b=2,c=0

	//ͻ��Ч��������5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	//c=233
	c = a + b + 230;

	return c;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//����һ��std::packaged_task����pt1����װ����Test_Fun
	std::packaged_task<int(int, int, int&)> pt1(Test_Fun);
	//����һ��std::future����fu1����װTest_Fun�ķ��ؽ�����ͣ�����pt1����
	std::future<int> fu1 = pt1.get_future();

	//����һ������
	int c = 0;

	//����һ���߳�t1����pt1����Ӧ�Ĳ����ŵ��߳�����ִ��
	std::thread t1(std::move(pt1), 1, 2, std::ref(c));

	//�������߳�t1����(����Test_Fun���ؽ��)
	//int iResult = fu1.get();

	//std::cout << "ִ�н����" << iResult << std::endl;	//ִ�н����233
	std::cout << "c��" << c << std::endl;	//c��233


	getchar();
	getchar();

	return 1;
}
