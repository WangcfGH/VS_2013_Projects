// std_async_example.cpp : 定义控制台应用程序的入口点。

//1、std::async函数原型：
//
//template<class Fn, class... Args>
//future<typename result_of<Fn(Args...)>::type> async(launch policy, Fn&& fn, Args&&...args);
//功能：第二个参数接收一个可调用对象（仿函数、lambda表达式、类成员函数、普通函数......）作为参数, 并且异步或是同步执行他们。
//
//a、对于是异步执行还是同步执行，由第一个参数的执行策略决定：
//
//（1）、std::launch::async 传递的可调用对象异步执行；
//
//（2）、std::launch::deferred 传递的可调用对象同步执行；
//
//（3）、std::launch::async | std::launch::deferred 可以异步或是同步，取决于操作系统，我们无法控制；
//
//（4）、如果我们不指定策略，则相当于（3）。
//
//
//
//b、对于执行结果：
//
//我们可以使用get、wait、wait_for、wait_until等待执行结束，区别是get可以获得执行的结果。如果选择异步执行策略，调用get时，如果异步执行没有结束，
//get会阻塞当前调用线程，直到异步执行结束并获得结果，如果异步执行已经结束，不等待获取执行结果；如果选择同步执行策略，只有当调用get函数时，同步调用才真正执行，这也被称为函数调用被延迟。
//
//c、返回结果std::future的状态：
//
//（1）、deffered：异步操作还没有开始；
//
//（2）、ready：异步操作已经完成；
//
//（3）、timeout：异步操作超时。





/*
//实例1（异步执行和同步执行）：
#include "stdafx.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std::chrono;

std::string fetchDataFromDB(std::string recvData) {

	std::cout << "fetchDataFromDB start" << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(seconds(5));
	return "DB_" + recvData;
}

std::string fetchDataFromFile(std::string recvData) {

	std::cout << "fetchDataFromFile start" << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(seconds(3));
	return "File_" + recvData;
}

int _tmain(int argc, _TCHAR* argv[])
{

	std::cout << "main start" << std::this_thread::get_id() << std::endl;

	//获取开始时间
	system_clock::time_point start = system_clock::now();

	std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");

	//从文件获取数据
	std::future<std::string> fileData = std::async(std::launch::deferred, fetchDataFromFile, "Data");

	//知道调用get函数fetchDataFromFile才开始执行
	std::string FileData = fileData.get();
	//如果fetchDataFromDB()执行没有完成，get会一直阻塞当前线程
	std::string dbData = resultFromDB.get();

	//获取结束时间
	auto end = system_clock::now();

	auto diff = duration_cast<std::chrono::seconds>(end - start).count();
	std::cout << "Total Time taken= " << diff << "Seconds" << std::endl;

	//组装数据
	std::string data = dbData + " :: " + FileData;

	//输出组装的数据
	std::cout << "Data = " << data << std::endl;

	getchar();
	getchar();

	return 0;
}
*/




//实例2（查询future的状态获取异步执行的结果）：
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std::chrono;

std::string fetchDataFromDB(std::string recvData) {

	std::cout << "fetchDataFromDB start" << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(seconds(5));
	return "DB_" + recvData;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "main start" << std::this_thread::get_id() << std::endl;

	//获取开始时间
	system_clock::time_point start = system_clock::now();

	std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");

	std::future_status status;
	std::string dbData;
	do
	{
		status = resultFromDB.wait_for(std::chrono::seconds(1));

		switch (status)
		{
		case std::future_status::ready:
			std::cout << "Ready..." << std::endl;
			//获取结果
			dbData = resultFromDB.get();
			std::cout << dbData << std::endl;
			break;
		case std::future_status::timeout:
			std::cout << "timeout..." << std::endl;
			break;
		case std::future_status::deferred:
			std::cout << "deferred..." << std::endl;
			break;
		default:
			break;
		}

	} while (status != std::future_status::ready);


	//获取结束时间
	auto end = system_clock::now();

	auto diff = duration_cast<std::chrono::seconds>(end - start).count();
	std::cout << "Total Time taken= " << diff << "Seconds" << std::endl;

	getchar();
	getchar();

	return 0;
}
