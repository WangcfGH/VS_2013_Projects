// StrlenDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "comutil.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string strTemp = "123456789";
	char propInfoStr[8];
	memset(propInfoStr, 0, 8);
	strcpy(propInfoStr, strTemp.c_str());
	int len = strlen(propInfoStr);

	printf("len is %ld", len);
	getchar();
	getchar();
	getchar();
	return 0;
}

