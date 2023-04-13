/*
// QuickSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum SORT_TYPE
{
	LOW_TO_HIGH,
	HIGH_TO_LOW
};

enum SORT_POINT
{
	SORT_BEFORE,
	SORT_AFTER
};

void QuickSort(vector<int> &vecValue, int nStart, int nEnd, int eSortType)
{
	if (nEnd > nStart)
	{
		int nOldStart = nStart;
		int nOldEnd = nEnd;
		int nTempValue = vecValue[nStart];

		if (eSortType == LOW_TO_HIGH)	// ��С����
		{
			while (nEnd > nStart)
			{
				// �Ӻ���ǰ��С�ڵ���nTempValue��ֵ��ǰ��
				while (vecValue[nEnd] > nTempValue && nEnd > nStart)
					nEnd--;		

				vecValue[nStart] = vecValue[nEnd];

				// ��ǰ�����ҵ�����nTempValue��ֵ����
				while (vecValue[nStart] <= nTempValue && nEnd > nStart)
					nStart++;

				vecValue[nEnd] = vecValue[nStart];
			}

			vecValue[nStart] = nTempValue;
		}
		else							// �Ӵ�С
		{
			while (nEnd > nStart)
			{
				// �Ӻ���ǰ�Ҵ��ڵ���nTempValue��ֵ��ǰ��
				while (vecValue[nEnd] < nTempValue && nEnd > nStart)
					nEnd--;

				vecValue[nStart] = vecValue[nEnd];

				// ��ǰ�����ҵ�С��nTempValue��ֵ����
				while (vecValue[nStart] >= nTempValue && nEnd > nStart)
					nStart++;

				vecValue[nEnd] = vecValue[nStart];
			}

			vecValue[nStart] = nTempValue;
		}	

		QuickSort(vecValue, nOldStart, nStart - 1, eSortType);
		QuickSort(vecValue, nStart + 1, nOldEnd, eSortType);
	}
}

void PrintValue(vector<int> vecValueTable, SORT_POINT eSortPoint)
{
	if (eSortPoint == SORT_BEFORE)
	{
		cout << "����ǰ" << endl;
	} 
	else
	{
		cout << "�����" << endl;
	}

	for (int i = 0; i < vecValueTable.size(); i++)
	{
		cout << vecValueTable[i] << "\t";
	}

	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> valueTable{1, 9, 80, 70, 60, 30, 40, 50, 60, 88, 22, 33, 11};
	PrintValue(valueTable, SORT_BEFORE);
	QuickSort(valueTable, 0, valueTable.size() - 1, LOW_TO_HIGH);
	PrintValue(valueTable, SORT_AFTER);

	getchar();
	getchar();
	getchar();
	return 0;
}

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void std_sort()
{
	int nNumList[15] = { 1, 45, 48, 86, 2, 69, 78, 89, 85, 1668, 48, 495, 8546, 126, 75 };
	std::cout << "Before std::sort" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << nNumList[i] << " ";
	}
	// std::sort����ʱҪ��֤Ԫ������Ƿ���falseŶ
	std::sort(nNumList, nNumList + 15, [](int nA, int nB){
		return(nA < nB);
	});

	std::cout << endl << "After std::sort" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << nNumList[i] << " ";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std_sort();
	getchar();
	getchar();
	getchar();
	return 0;
}

