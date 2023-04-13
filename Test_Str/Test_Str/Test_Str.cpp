// Test_Str.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include <atlstr.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string strTest;
	strTest.c_str();

	CString strTitle;
	strTitle.Format("亲爱的玩家，您在%4d年%02d月%02d日 %2d:%02d-%2d:%02d的定时赛活动中，获得了第%d名，我们通过邮件发送给您，请查收哦！",
		2021, 4, 8, 10, 2, 12, 0);

	cout << strTitle <<endl;


	getchar();
	getchar();

	return 0;
}

