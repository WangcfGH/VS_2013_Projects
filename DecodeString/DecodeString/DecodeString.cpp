// DecodeString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<afx.h>
#include <fstream>
#include <string>
#include <iostream>
#include<iomanip>
using namespace std;

// ���������ַ�
CString EncodeString(CString strIn)
{
	const TCHAR* pInfo = LPCTSTR(strIn);
	int nCount = strlen(pInfo);
	char* pBuf = new char[2 * nCount + 1];
	memset(pBuf, 0, 2 * nCount + 1);
	char* p = pBuf;
	for (int j = 0; j < nCount; j++) {
		p += sprintf(p, "%02x", (BYTE)pInfo[j]);
	}
	CString strOut;
	strOut.Empty();
	strOut.Format("%s", pBuf);
	delete[] pBuf;
	return strOut;
}

// ���������ַ�
CString DecodeString(CString strIn)
{
	if (0 == strIn.Compare("")) {
		return "";
	}
	const TCHAR* pIn = LPCTSTR(strIn);
	int nCount = strlen(pIn);
	char* pBuf = new char[nCount / 2 + 1];
	memset(pBuf, 0, nCount / 2 + 1);
	char* p = pBuf;
	for (int j = 0; j < nCount; j += 2) {
		int c = 0;
		sscanf_s(pIn + j, "%02x", &c);
		*p = c;
		p++;
	}
	*p = 0;

	CString strOut;
	strOut.Empty();
	strOut.Format("%s", pBuf);
	delete[] pBuf;
	return strOut;
}

std::string truncatTailingZeroes(std::string s)
{
	//ɾ��β�������0�����β���Ե������Ҳɾ��С����
	std::string tmps = s;
	if (tmps.find(".") > 0)
	{
		size_t fp = tmps.rfind(".");
		size_t f = tmps.rfind("0");
		while (f != string::npos && f == tmps.length() - 1 && f > fp) {

			if (f != -1) {
				tmps = tmps.erase(f);
			}
			f = tmps.rfind("0");
		}
		fp = tmps.rfind(".");
		if (fp == tmps.size() - 1)
		{
			tmps = tmps.erase(fp);
		}
		return tmps;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	CString strScr;
	CString strTar;
	//SetConsoleOutputCP(65001);
	ofstream outfile;
	outfile.open("E:/Debug/promotion_competition_target.txt", ios::out);
	if (!outfile)
	{
		cout << "file can not open" << endl;
		abort();
	}

	//SetConsoleOutputCP(65001);
	ifstream fin("E:/Debug/promotion_competition.txt");
	string line;

	if (fin)
	{
		while (getline(fin, line)) //���ж�ȡ��line_info�� 
		{
			if (line.size() == 0)
			{
				break;   //ѭ�������ֶ��Ľ��п��е��ж�
			}

			strScr = line.c_str();
			strTar = DecodeString(strScr);

			cout << strTar.GetBuffer(0) << endl;
			outfile << strTar.GetBuffer(0) << endl;
		}
	}

	else
	{
		cout << "no such file" << endl;;
	}
	fin.close();
	outfile.close();
	

	CString str;
	__int64 nWinGoldCoinLow = 102046;
	__int64 nWinGoldCoinHigh = 0;
	__int64 nWinGoldCoinMultLow = 1048576;
	__int64 nWinGoldCoinMultHigh = 0;
	__int64 nWinGoldCoin = nWinGoldCoinHigh * 1000000000 + nWinGoldCoinLow;
	__int64 nWinGoldCoinMult = nWinGoldCoinMultHigh * 1000000000 + nWinGoldCoinMultLow;

	float fWinGoldCoinMult = (float)nWinGoldCoinMult / 10000;
	CString cstrWinGoldCoinMult;
	cstrWinGoldCoinMult.Format(_T("%.2f"), fWinGoldCoinMult);
	string strWinGoldCoinMult = cstrWinGoldCoinMult.GetBuffer();
	strWinGoldCoinMult = truncatTailingZeroes(strWinGoldCoinMult);
	str.Format(_T("��ϲ���һ�ִ��%s�򱶣�Ӯ��%lld��ң�������!"), strWinGoldCoinMult.c_str(), nWinGoldCoin);

	return 0;
}






