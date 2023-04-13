// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	int nRequest, nCostTime, nRequestCount;
	string strLine;
	size_t nFind1, nFind2, nFind3, nFind4;
	map<int, int> mpRequestTime, mpRequestTimeCpy;
	map<int, int> mpRequestCount, mpRequestCountCpy;
	map<int, int>::iterator it;
	fstream fsRequestLog;
	fsRequestLog.open("wfbichunksvr.log", fstream::in | fstream::out | fstream::app);

	fstream fsRequestLogAnalyze;
	fsRequestLogAnalyze.open("wfbichunksvranalyze.txt", fstream::out | ios_base::trunc);
	fsRequestLogAnalyze.clear();

	while (getline(fsRequestLog, strLine))
	{
		nRequest = 0;
		nCostTime = 0;
		nFind1 = strLine.find("nRequest = ");
		nFind2 = strLine.find(" time costs:");
		nFind3 = strLine.find("time costs: ");
		nFind4 = strLine.find(" ms");
		if (nFind1 != string::npos && nFind2 != string::npos)
		{
			nRequest = atoi(strLine.substr(nFind1 + 11, nFind2 - nFind1 - 11).c_str());
		}
		if (nFind3 != string::npos && nFind4 != string::npos)
		{
			nCostTime = atoi(strLine.substr(nFind3 + 12, nFind4 - nFind3 - 12).c_str());
		}

		if (nRequest != 0)
		{
			it = mpRequestTime.find(nRequest);
			if (it != mpRequestTime.end())
			{
				it->second += nCostTime;
			}
			else
			{
				mpRequestTime.insert(pair<int, int>(nRequest, nCostTime));
			}

			it = mpRequestCount.find(nRequest);
			if (it != mpRequestCount.end())
			{
				it->second += 1;
			}
			else
			{
				mpRequestCount.insert(pair<int, int>(nRequest, 1));
			}
		}
	}

	mpRequestTimeCpy = mpRequestTime;
	mpRequestCountCpy = mpRequestCount;

	nRequestCount = mpRequestTime.size();
	fsRequestLogAnalyze << "Sort By Time:" << endl;
	for (int i = 0; i < nRequestCount; i++)
	{
		int nMaxRequest = 0;
		int nMaxTime = 0;
		map<int, int>::iterator itCount;
		map<int, int>::iterator itTime;
		for (itTime = mpRequestTime.begin(); itTime != mpRequestTime.end(); itTime++)
		{
			if (itTime->second >= nMaxTime)
			{
				nMaxTime = itTime->second;
				nMaxRequest = itTime->first;
			}
		}
		itCount = mpRequestCount.find(nMaxRequest);
		itTime = mpRequestTime.find(nMaxRequest);
		fsRequestLogAnalyze << "request" << itTime->first << "		cost time is " << itTime->second << endl;
		fsRequestLogAnalyze << "request" << itTime->first << "		send count is " << itCount->second << endl;
		fsRequestLogAnalyze << "request" << itTime->first << "		average time is " << itTime->second / itCount->second << endl << endl << endl;
		mpRequestTime.erase(itTime);
	}

	nRequestCount = mpRequestCountCpy.size();
	fsRequestLogAnalyze << endl << endl << endl << endl << endl << "Sort By Count:" << endl;
	for (int i = 0; i < nRequestCount; i++)
	{
		int nMaxRequest = 0;
		int nMaxCount = 0;
		map<int, int>::iterator itCount;
		map<int, int>::iterator itTime;
		for (itCount = mpRequestCountCpy.begin(); itCount != mpRequestCountCpy.end(); itCount++)
		{
			if (itCount->second >= nMaxCount)
			{
				nMaxCount = itCount->second;
				nMaxRequest = itCount->first;
			}
		}
		itCount = mpRequestCountCpy.find(nMaxRequest);
		itTime = mpRequestTimeCpy.find(nMaxRequest);
		fsRequestLogAnalyze << "request" << itTime->first << "		send count is " << itCount->second << endl;
		fsRequestLogAnalyze << "request" << itTime->first << "		cost time is " << itTime->second << endl;
		fsRequestLogAnalyze << "request" << itTime->first << "		average time is " << itTime->second / itCount->second << endl << endl << endl;
		mpRequestCountCpy.erase(itCount);
	}
	
	fsRequestLog.close();
	fsRequestLogAnalyze.close();

	printf("Analyze Over");
	getchar();
	getchar();
    return 0;
}

