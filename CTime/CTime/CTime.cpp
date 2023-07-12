// CTime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<atltime.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//int m_currentDate = atoi(CTime::GetCurrentTime().Format(_T("04d%02d%02d")));

	CTime tNow = CTime::GetCurrentTime();
	CTime tStamp = 1659079060;

	CTimeSpan tSpanTime = tNow - tStamp;
	int nSeconds = tSpanTime.GetSeconds();

	DWORD dwValue1 = 1412296875;
	DWORD dwValue2 = 1412297765;
	DWORD dwValue3 = 151000;

	if (dwValue1 - dwValue2 > dwValue3)
	{
		std::cout << "Bigger" << endl;
	} 
	else
	{
		std::cout << "Smaller" << endl;
	}

	return 0;
}

