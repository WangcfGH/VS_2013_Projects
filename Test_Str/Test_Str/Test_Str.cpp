// Test_Str.cpp : �������̨Ӧ�ó������ڵ㡣
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
	strTitle.Format("�װ�����ң�����%4d��%02d��%02d�� %2d:%02d-%2d:%02d�Ķ�ʱ����У�����˵�%d��������ͨ���ʼ����͸����������Ŷ��",
		2021, 4, 8, 10, 2, 12, 0);

	cout << strTitle <<endl;


	getchar();
	getchar();

	return 0;
}

