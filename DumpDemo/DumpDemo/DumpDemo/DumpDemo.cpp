// DumpDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"


int _tmain(int argc, _TCHAR* argv[])
{
	int *VecTemp = NULL;
	VecTemp[6] = 100;
	
	std::cout << "VecTemp[0] IS:" << VecTemp[0] << "VecTemp[1] IS:" << VecTemp[1] << "VecTemp[2] IS:" << VecTemp[2] << "VecTemp[3] IS:" << VecTemp[3] << "VecTemp[4] IS:" << VecTemp[4] << "VecTemp[5] IS:" << VecTemp[5] << "VecTemp[6] IS:" << VecTemp[6];
	getchar();
	getchar();
	return 0;
}

