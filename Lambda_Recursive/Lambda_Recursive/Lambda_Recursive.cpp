// Lambda_Recursive.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <functional>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	auto g = [](int a) {
		std::function<void(int)> f;
		f = [&](int a)  {
			if (a == 0) return;
			printf("%d\n", a);
			f(a - 1);
		};
		return f(a);
	};
	g(10);
	return 0;
}

