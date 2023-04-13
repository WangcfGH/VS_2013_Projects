#include "stdafx.h"
#include <iostream>					// std::cout
#include <list>
#include <map>
#include <thread>					// std::thread
#include <mutex>					// std::mutex, std::unique_lock
#include <condition_variable>		// std::condition_variable

std::mutex mtx; // ȫ�ֻ�����.
std::condition_variable cv; // ȫ����������.
bool ready = false; // ȫ�ֱ�־λ.

void do_print_id(int id)
{
	std::unique_lock <std::mutex> lck(mtx);
	while (!ready) // �����־λ��Ϊ true, ��ȴ�...
		cv.wait(lck); // ��ǰ�̱߳�����, ��ȫ�ֱ�־λ��Ϊ true ֮��,
	// �̱߳�����, ��������ִ�д�ӡ�̱߳��id.
	std::cout << "thread " << id << '\n';
}

void go()
{
	std::unique_lock <std::mutex> lck(mtx);
	ready = true; // ����ȫ�ֱ�־λΪ true.
	cv.notify_all(); // ���������߳�.
}

int main()
{
	// ����һ
// 	std::thread threads[10];
// 	// spawn 10 threads:
// 	for (int i = 0; i < 10; ++i)
// 		threads[i] = std::thread(do_print_id, i);
// 
// 	std::cout << "10 threads ready to race...\n";
// 	go(); // go!
// 
// 	for (auto & th : threads)
// 		th.join();
	
	// ���Զ�
// 	std::list<int>		m_listThreadID;
// 	for (int i = 0; i < 10; i++)
// 		m_listThreadID.push_back(NULL);
// 
// 	for (int i = 0; i < 10; i++)
// 	{
// 		std::cout << m_listThreadID.size() << std::endl;
// 		m_listThreadID.pop_front();
// 	}	
// 
	std::map<int, int > mpTest;
	mpTest.clear();
	mpTest.find(1);

	getchar();
 	getchar();

	return 0;
}