// QuickSort.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//std::sort����
void StdSort()
{
	// ����������
	int nNum[20] = { 5, 10, 15, 15, 20, 25, 30, 35, 16, 12, 8, 4, 3, 6, 9, 7, 14, 21, 95487, 3561 };
	
	// ToDo Sort
	cout << "After StdSort" << endl;
	sort(nNum, nNum + 20, [](int nA, int nB){ return (nA < nB); });
	
	// print
	for each (auto var in nNum)
		cout << var << "  ";
	cout << endl;
}

// Ͱ����
void BucketSort()
{
	// ����������
	int nNum[20] = { 5, 10, 15, 15, 20, 25, 30, 35, 16, 12, 8, 4, 3, 6, 9, 7, 14, 21, 95487, 3561 };	

	// ToDo Sort
	cout << "After BucketSort" << endl;
	int nMin = 3;
	int nMax = 95487;
	int nCount = 20;
	int nBucketLen = nMax - nMin + 1;
	vector<int> vecNumCount(nBucketLen, 0);
	for (int i = 0; i < nCount; i++)
	{
		vecNumCount[nNum[i] - nMin]++;
	}
	int nIndex = 0;
	for (int i = 0; i < nBucketLen; i++)
	{
		while (vecNumCount[i])
		{
			nNum[nIndex] = i + nMin;
			nIndex++;
			vecNumCount[i]--;
		}
	}

	// print
	for each (auto var in nNum)
		cout << var << "  ";
	cout << endl;
}

// ð������
void BubbleSort()
{
	// ����������
	int nNum[20] = { 5, 10, 15, 15, 20, 25, 30, 35, 16, 12, 8, 4, 3, 6, 9, 7, 14, 21, 95487, 3561 };

	// ToDo Sort
	int nTemp = 0;
	cout << "After BubbleSort" << endl;
	for (int i = 0; i < 20 - 1; i++)
	{
		for (int j = 0; j < 20 - i - 1; j++)
		{
			if (nNum[j] > nNum[j + 1])
			{
				nTemp = nNum[j + 1];
				nNum[j + 1] = nNum[j];
				nNum[j] = nTemp;
			}
		}
	}

	// print
	for each (auto var in nNum)
		cout << var << "  ";
	cout << endl;
}

//ѡ������
void SelectSort()
{
	// ����������
	int nNum[20] = { 5, 10, 15, 15, 20, 25, 30, 35, 16, 12, 8, 4, 3, 6, 9, 7, 14, 21, 95487, 3561 };
	
	// ToDo Sort
	cout << "After SelectSort" << endl;
	int nTemp = 0;
	for (int i = 0; i < 20 - 1; i++)
	{
		for (int j = i; j < 20; j++)
		{
			if (nNum[j] < nNum[i])
			{
				nTemp = nNum[i];
				nNum[i] = nNum[j];
				nNum[j] = nTemp;
			}
		}
	}

	// print
	for each (auto var in nNum)
		cout << var << "  ";
	cout << endl;
}


void LoopQuickSort(int nBegin, int nEnd, int* nNum)
{
	// �ݹ����
	if (nBegin >= nEnd)
		return;

	int i = nBegin; 
	int j = nEnd;
	int nTemp = 0;
	while (i != j)
	{
		while (nNum[j] >= nNum[nBegin] && i < j)
		{
			j--;
		}

		while (nNum[i] <= nNum[nBegin] && i < j)
		{
			i++;
		}

		if (i < j)
		{
			nTemp = nNum[i];
			nNum[i] = nNum[j];
			nNum[j] = nTemp;
		}		
	}
	
	nTemp = nNum[i];
	nNum[i] = nNum[nBegin];
	nNum[nBegin] = nTemp;

	// �ֶεݹ�
	LoopQuickSort(nBegin, i - 1, nNum);
	LoopQuickSort(i + 1, nEnd, nNum);
}

// QuickSort
void QuickSort()
{
	// ����������
	int nNum[20] = { 5, 10, 15, 15, 20, 25, 30, 35, 16, 12, 8, 4, 3, 6, 9, 7, 14, 21, 95487, 3561 };
	
	// ToDo Sort
	cout << "After QuickSort" << endl;
	LoopQuickSort(0, 20 - 1, nNum);

	// print
	for each (auto var in nNum)
		cout << var << "  ";
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// std::sort����
	StdSort();
	
	// Ͱ����
	BucketSort();

	// ð������
	BubbleSort();

	// ѡ������
	SelectSort();

	// ��������
	QuickSort();

	getchar();
	getchar();
	return 0;
}

