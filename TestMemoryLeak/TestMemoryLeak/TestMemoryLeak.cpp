// TestMemoryLeak.cpp : �������̨Ӧ�ó������ڵ㡣
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

// �񵥼�¼
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
	_CrtMemCheckpoint(&s1);//����1

	//TestLeak();
	//TestLeakEx();
	for (int i = 0; i < 1000000; i++)
	{
		TestLeakExEx();
	}

	_CrtMemCheckpoint(&s2);//����2

	if (_CrtMemDifference(&s3, &s1, &s2))//�жϼ����1�ͼ���2�Ƿ�ͬ
	{
		_CrtMemDumpStatistics(&s3);//��ӡй©�ڴ�
	}

	_CrtDumpMemoryLeaks();//��ӡ�����ڴ�й©��Ϣ
	getchar();
	getchar();
	getchar();
	return 0;
}

