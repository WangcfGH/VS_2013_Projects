#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char* p1 = new char;
	printf("%p\n", p1);

	char* pLargeMem = new char[40000];

	for (int i = 0; i < 1000; ++i)
	{
		char* p = new char[20];
	}

	system("pause");

	return 0;
}