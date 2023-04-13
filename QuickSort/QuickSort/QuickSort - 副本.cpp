/*
// QuickSort.cpp : 定义控制台应用程序的入口点。
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

		if (eSortType == LOW_TO_HIGH)	// 从小到大
		{
			while (nEnd > nStart)
			{
				// 从后往前找小于等于nTempValue的值后前移
				while (vecValue[nEnd] > nTempValue && nEnd > nStart)
					nEnd--;		

				vecValue[nStart] = vecValue[nEnd];

				// 从前往后找到大于nTempValue的值后移
				while (vecValue[nStart] <= nTempValue && nEnd > nStart)
					nStart++;

				vecValue[nEnd] = vecValue[nStart];
			}

			vecValue[nStart] = nTempValue;
		}
		else							// 从大到小
		{
			while (nEnd > nStart)
			{
				// 从后往前找大于等于nTempValue的值后前移
				while (vecValue[nEnd] < nTempValue && nEnd > nStart)
					nEnd--;

				vecValue[nStart] = vecValue[nEnd];

				// 从前往后找到小于nTempValue的值后移
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
		cout << "排序前" << endl;
	} 
	else
	{
		cout << "排序后" << endl;
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
	// std::sort排序时要保证元素相等是返回false哦
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

