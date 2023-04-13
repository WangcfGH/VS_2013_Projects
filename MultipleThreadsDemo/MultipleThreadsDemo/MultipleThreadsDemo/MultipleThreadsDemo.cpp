// MultipleThreadsDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <time.h>
#include <stdlib.h>

using namespace std;

void foo(int nThreadNO)
{
	cout << "thread " << nThreadNO << " Begin Do While" << endl;
	srand(time(NULL));
	
	while (true)
	{
		if (rand() * rand() % 100000000 == nThreadNO)
		{
			cout << "thread " << nThreadNO << "Do While Rand " << nThreadNO << endl;
		}		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	thread thr1(foo, 1);
	thread thr2(foo, 2);
	thread thr3(foo, 3);
	thread thr4(foo, 4);
	//thread thr5(foo, 5);
	//thread thr6(foo, 6);
	//thread thr7(foo, 7);
	//thread thr8(foo, 8);

	thr1.join();
	thr2.join();
	thr3.join();
	thr4.join();
	//thr5.join();
	//thr6.join();
	//thr7.join();
	//thr8.join();

	cout << "All Thread Join" << endl;

	return 0;
}

