// TestMemoryLeak.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <atlstr.h>
#include <winnls.h>
#include <string>
#include <vector>

void TestLeak()
{
	char* p = new char[100];
}

void TestLeakEx()
{
	std::vector<INT64> vecValue{ 0, 0, 0, 0, 0, 0, 0 };
	vecValue.push_back(0);
	vecValue.push_back(0);
	vecValue.push_back(0);
	vecValue.push_back(0);
	vecValue[0] = 0;
	vecValue[1] = 2;
	vecValue[2] = 2;
	vecValue[3] = 2;

	vecValue.push_back(1);
	vecValue.push_back(1);
	vecValue.push_back(0);
	vecValue.push_back(0);
}

// 榜单记录
typedef struct _tagDatePeakRankRecord
{
	int			userID;
	std::string		userName;
	INT64		gainClTotalValue;
	INT64		gainNwTotalValue;
	INT64		victoryClTotalValue;
	INT64		victoryNwTotalValue;
	INT64		matchTotalValue;
	INT64		streakTotalValue;
	INT64		streakTotalMaxValue;
	INT64		praiseTotalValue1;
	INT64		praiseTotalValue2;
	INT64		praiseTotalValue3;
}PEAK_RANK_RECORD, *LPDATE_PEAK_RANK_RECORD;

void TestLeakExEx()
{
	PEAK_RANK_RECORD oneDatePeakRankRecord;
	memset(&oneDatePeakRankRecord, 0, sizeof(PEAK_RANK_RECORD));
	
}

_CrtMemState s1, s2, s3;

int _tmain(int argc, _TCHAR* argv[])
{
	_CrtMemCheckpoint(&s1);//监测点1

	//TestLeak();
	//TestLeakEx();
	for (int i = 0; i < 1000000; i++)
	{
		TestLeakExEx();
	}

	_CrtMemCheckpoint(&s2);//监测点2

	if (_CrtMemDifference(&s3, &s1, &s2))//判断检监测点1和监测点2是否不同
	{
		_CrtMemDumpStatistics(&s3);//打印泄漏内存
	}

	_CrtDumpMemoryLeaks();//打印所有内存泄漏信息
	getchar();
	getchar();
	getchar();
	return 0;
}

