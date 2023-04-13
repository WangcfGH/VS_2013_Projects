// Function_Bind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Test
{
public:
	static int Add(int nA, int nB)
	{
		cout << "Test::Add " <<to_string(nA) << " + " << to_string(nB) << " = " << to_string(nA + nB) << endl;
		return nA + nB;
	}

	int Reduce(int nA, int nB)
	{
		cout << "Test::Reduce " << to_string(nA) << " - " << to_string(nB) << " = " << to_string(nA - nB) << endl;
		return nA - nB;
	}

	void Print()
	{
		cout << "Test::Print " << endl;
	}
};

int Add(int nA, int nB)
{
	cout << "Global_Add " << to_string(nA) << " + " << to_string(nB) << " = " << to_string(nA + nB) << endl;
	return nA + nB;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test test;	
	std::function<int(int, int)> funcTest;
	funcTest = Test::Add;
	funcTest(12, 15);
	funcTest = Add;
	funcTest(18, 90);
	auto lFunc = [](int nA, int nB)->int{
		cout << "Lambda_Add " << to_string(nA) << " + " << to_string(nB) << " = " << to_string(nA + nB) << endl;
		return nA + nB;
	};
	funcTest = lFunc;
	funcTest(50, 150);

	auto funcBind = bind(&Test::Reduce, test, placeholders::_1, 50);
	funcBind(6000);

	getchar();
	getchar();
	return 0;
}
