// CTime.cpp : �������̨Ӧ�ó������ڵ㡣
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

	return 0;
}

