#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include<iomanip>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream		ifile;						//����һ��fstream�ļ�������
	ofstream		ofile;						//����һ��fstream�ļ�������
	vector<string>  vecUrl;						//����һ��vector<string>����
	string			strUrl;						//��������ÿһ��
	
	ifile.open("PortraitUrl.txt");				//���ļ�
	if (ifile.is_open())			
	{
		while (getline(ifile, strUrl))			//���Զ���\n���з�ȥ�� 
		{
			const char* pPortraitUrl = strUrl.data();
			int nCount = strlen(pPortraitUrl);
			char* pBuf = new char[2 * nCount + 1];
			char* p = pBuf;
			for (int j = 0; j < nCount; j++)
			{
				p += sprintf(p, "%02x", pPortraitUrl[j]);
			}
			string strUrlEncryption = string(pBuf);

			vecUrl.push_back(strUrlEncryption);
		}
	}						
	ifile.close();

	ofile.open("PortraitUrlEncryption.txt");	//���ļ�
	if (ofile.is_open())
	{
		for (int i = 0; i < vecUrl.size(); i++)
		{
			ofile << vecUrl[i];
			ofile << "\n";
		}
	}
	ofile.close();

	return 0;
}

