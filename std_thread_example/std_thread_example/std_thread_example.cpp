// std_thread_example.cpp : 定义控制台应用程序的入口点。
//

/*
//Example1:std::thread 各种构造函数例子如下：
#include "stdafx.h"
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

void f1(int n)
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread " << n << " executing In f1\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void f2(int& n)
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread 2 executing In f2\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	std::thread t1;						// t1 is not a thread
	std::thread t2(f1, n + 1);			// pass by value
	std::thread t3(f2, std::ref(n));	// pass by reference
	std::thread t4(std::move(t3));		// t4 is now running f2(). t3 is no longer a thread
	t2.join();
	t4.join();
	std::cout << "Final value of n is " << n << '\n';
	std::getchar();
	std::getchar();
	return EXIT_SUCCESS;
}
*/


/*
//Example2:std::thread 赋值操作 ：
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for

void thread_task(int n) {
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "hello thread "
		<< std::this_thread::get_id()
		<< " paused " << n << " seconds" << std::endl;
}

int main(int argc, const char *argv[])
{
	std::thread threads[5];
	std::cout << "Spawning 5 threads...\n";
	for (int i = 0; i < 5; i++) {
		threads[i] = std::thread(thread_task, i + 1);
	}
	std::cout << "Done spawning threads! Now wait for them to join\n";
	for (auto& t : threads) {
		t.join();
	}
	std::cout << "All threads joined.\n";
	std::getchar();
	std::getchar();
	return EXIT_SUCCESS;
}
*/

 
/*
//Example3:std::thread 赋值操作 ：
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main()
{
	std::thread t;
	std::cout << "before starting, joinable: " << t.joinable() << '\n';

	t = std::thread(foo);
	std::cout << "after starting, joinable: " << t.joinable() << '\n';

	t.join();

	std::cout << "after join, joinable: " << t.joinable() << '\n';

	std::getchar();
	std::getchar();
	return EXIT_SUCCESS;
}
*/

/*
//Example4:std::thread 赋值操作 ：
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

void independentThread()
{
	std::cout << "Starting concurrent thread.\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "Exiting concurrent thread.\n";
}

void threadCaller()
{
	std::cout << "Starting thread caller.\n";
	std::thread t(independentThread);
	t.detach();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Exiting thread caller.\n";
	std::cout << "t.jionable is " << t.joinable() << "\n";
}

int main()
{
	threadCaller();
	std::this_thread::sleep_for(std::chrono::seconds(5));

	std::getchar();
	std::getchar();
	return EXIT_SUCCESS;
}
*/


/*
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include<thread>  
#include<atomic>  
using namespace std;
const int N = 1000000;
atomic_int num{ 0 };//不会发生线程冲突，线程安全  
void run()
{
	for (int i = 0; i < N; i++)
	{
		num++;
	}
}
int main()
{
	clock_t start = clock();
	thread t1(run);
	thread t2(run);
	t1.join();
	t2.join();
	clock_t end = clock();
	cout << "num=" << num << ",用时 " << end - start << " ms" << endl;

	getchar();
	getchar();
	return 0;
}



#include "stdafx.h"
#include <iostream>
#include <chrono>
#include<thread>  
using namespace std;
const int N = 100000000;
int num = 0;
void run()
{
	for (int i = 0; i < N; i++)
	{
		num++;
	}
}
int main()
{
	clock_t start = clock();
	
	thread t1(run);
	thread t2(run);
	t1.join();
	t2.join();

	
	//thread t1(run);
	//t1.join();
	//thread t2(run);
	//t2.join();
	
	clock_t end = clock();
	cout << "num=" << num << ",用时 " << end - start << " ms" << endl;

	getchar();
	getchar();

	return 0;
}
*/

/*
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

// "busy sleep" while suggesting that other threads run 
// for a small amount of time
void little_sleep(std::chrono::microseconds us)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = start + us;
	do {
		std::this_thread::yield();
	} while (std::chrono::high_resolution_clock::now() < end);
}

void SleepUntil(std::chrono::microseconds us)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = start + us;
	std::this_thread::sleep_until(end);
}

void SleepFor(std::chrono::microseconds us)
{	
	std::this_thread::sleep_for(us);
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	//little_sleep(std::chrono::microseconds(3000000));
	//SleepUntil(std::chrono::microseconds(3000000));
	SleepFor(std::chrono::microseconds(3000000));

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "waited for "
		<< std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
		<< " microseconds\n";

	getchar();
	getchar();
}
*/


/*
#include "stdafx.h"
#include <mutex>
#include <thread>
#include <chrono>

struct Box {
	explicit Box(int num) : num_things{ num } {}

	int num_things;
	std::mutex m;
};

void transfer(Box &from, Box &to, int num)
{
	// 仍未实际取锁
	std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
	std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

	// 锁两个 unique_lock 而不死锁
	std::lock(lock1, lock2);

	from.num_things -= num;
	to.num_things += num;

	// 'from.m' 与 'to.m' 互斥解锁于 'unique_lock' 析构函数
}

int main()
{
	Box acc1(100);
	Box acc2(50);

	std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
	std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

	t1.join();
	t2.join();


	printf("acc1.num_things %d \n", acc1.num_things);
	printf("acc2.num_things %d \n", acc2.num_things);
	getchar();
	getchar();
	return 1;
}
*/


#include "stdafx.h"
#include<iostream>
#include< thread>

using namespace std;

thread_local int tcount = 0;
int flag = 1;

void fThread() {
	tcount++;
	cout << tcount << endl;
	while (flag) {
		;
	}
}

int main()
{
	thread t1(fThread);
	thread t2(fThread);
	t1.join();
	t2.join();
	return 0;
}


#include "stdafx.h"
#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cv;
std::mutex cv_m; // 此互斥用于三个目的：
// 1) 同步到 i 的访问
// 2) 同步到 std::cerr 的访问
// 3) 为条件变量 cv
int i = 0;

void waits()
{
	std::unique_lock<std::mutex> lk(cv_m);
	std::cerr << "Waiting... \n";
	cv.wait(lk, []{return i == 1; });
	std::cerr << "...finished waiting. i == 1\n";
}

void signals()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	{
		std::lock_guard<std::mutex> lk(cv_m);
		std::cerr << "Notifying...\n";
	}
	cv.notify_all();

	std::this_thread::sleep_for(std::chrono::seconds(1));

	{
		std::lock_guard<std::mutex> lk(cv_m);
		i = 1;
		std::cerr << "Notifying again...\n";
	}
	cv.notify_all();	
}

int main()
{
	std::thread t1(waits), t2(waits), t3(waits), t4(signals);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	getchar();
	getchar;

	return 1;
}




/*
// 线程间通信 - chan的实现
#include "stdafx.h"
#include <stdio.h>
#include <thread>
#include "chan.h"  // chan的头文件

using namespace std::chrono;

// 消费数据 
void consume(chan<int> ch, int thread_id) {
	int n;
	while (ch >> n) {
		printf("[%d] %d\n", thread_id, n);
		std::this_thread::sleep_for(milliseconds(100));
	}
}

int main() {
	chan<int> chInt(3);

	// 消费者
	std::thread consumers[5];
	for (int i = 0; i < 5; i++) {
		consumers[i] = std::thread(consume, chInt, i + 1);
	}

	// 生产数据 
	for (int i = 0; i < 16; i++) {
		chInt << i;
	}
	chInt.close();  // 数据生产完毕

	for (std::thread &thr : consumers) {
		thr.join();
	}

	return 0;
}
*/