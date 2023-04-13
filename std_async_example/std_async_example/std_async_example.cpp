// std_async_example.cpp : �������̨Ӧ�ó������ڵ㡣

//1��std::async����ԭ�ͣ�
//
//template<class Fn, class... Args>
//future<typename result_of<Fn(Args...)>::type> async(launch policy, Fn&& fn, Args&&...args);
//���ܣ��ڶ�����������һ���ɵ��ö��󣨷º�����lambda���ʽ�����Ա��������ͨ����......����Ϊ����, �����첽����ͬ��ִ�����ǡ�
//
//a���������첽ִ�л���ͬ��ִ�У��ɵ�һ��������ִ�в��Ծ�����
//
//��1����std::launch::async ���ݵĿɵ��ö����첽ִ�У�
//
//��2����std::launch::deferred ���ݵĿɵ��ö���ͬ��ִ�У�
//
//��3����std::launch::async | std::launch::deferred �����첽����ͬ����ȡ���ڲ���ϵͳ�������޷����ƣ�
//
//��4����������ǲ�ָ�����ԣ����൱�ڣ�3����
//
//
//
//b������ִ�н����
//
//���ǿ���ʹ��get��wait��wait_for��wait_until�ȴ�ִ�н�����������get���Ի��ִ�еĽ�������ѡ���첽ִ�в��ԣ�����getʱ������첽ִ��û�н�����
//get��������ǰ�����̣߳�ֱ���첽ִ�н�������ý��������첽ִ���Ѿ����������ȴ���ȡִ�н�������ѡ��ͬ��ִ�в��ԣ�ֻ�е�����get����ʱ��ͬ�����ò�����ִ�У���Ҳ����Ϊ�������ñ��ӳ١�
//
//c�����ؽ��std::future��״̬��
//
//��1����deffered���첽������û�п�ʼ��
//
//��2����ready���첽�����Ѿ���ɣ�
//
//��3����timeout���첽������ʱ��





/*
//ʵ��1���첽ִ�к�ͬ��ִ�У���
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

	//��ȡ��ʼʱ��
	system_clock::time_point start = system_clock::now();

	std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");

	//���ļ���ȡ����
	std::future<std::string> fileData = std::async(std::launch::deferred, fetchDataFromFile, "Data");

	//֪������get����fetchDataFromFile�ſ�ʼִ��
	std::string FileData = fileData.get();
	//���fetchDataFromDB()ִ��û����ɣ�get��һֱ������ǰ�߳�
	std::string dbData = resultFromDB.get();

	//��ȡ����ʱ��
	auto end = system_clock::now();

	auto diff = duration_cast<std::chrono::seconds>(end - start).count();
	std::cout << "Total Time taken= " << diff << "Seconds" << std::endl;

	//��װ����
	std::string data = dbData + " :: " + FileData;

	//�����װ������
	std::cout << "Data = " << data << std::endl;

	getchar();
	getchar();

	return 0;
}
*/




//ʵ��2����ѯfuture��״̬��ȡ�첽ִ�еĽ������
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

	//��ȡ��ʼʱ��
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
			//��ȡ���
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


	//��ȡ����ʱ��
	auto end = system_clock::now();

	auto diff = duration_cast<std::chrono::seconds>(end - start).count();
	std::cout << "Total Time taken= " << diff << "Seconds" << std::endl;

	getchar();
	getchar();

	return 0;
}
