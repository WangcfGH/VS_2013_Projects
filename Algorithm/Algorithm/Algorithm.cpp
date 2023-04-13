#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum SORT_TYPE
{
	QUICK_SORT		= 0,	// ��������
	SELECT_SORT,			// ѡ������
	MAOPAO_SORT,			// ð������
};

enum SORT_UP_DOWN
{
	SORT_TO_UP		= 0,	// ��������
	SORT_TO_DOWN,			// �ݼ�����

};

enum SORT_TIME
{
	SORT_BEFORE		= 0,	// ����ǰ
	SORT_AFTER,				// �����
};

void PrintVecSort(const vector<int> vecBeforeSort, SORT_TYPE eSortType, SORT_UP_DOWN eSortUpDown, SORT_TIME eSortTime)
{
	string strSortType[] = { "����", "ѡ��", "ð��" };
	string strSortUpDown[] = { "����", "�ݼ�" };
	string strSortTime[] = { "����ǰ", "�����" };
	cout << strSortType[eSortType] << strSortUpDown[eSortUpDown] << strSortTime[eSortTime] << endl;
	for each (int var in vecBeforeSort)
	{
		cout << var << "	";
	}
	cout << endl;
}

// ��������
void QuickSort(vector<int> &vecSortValue, int nBegin, int nEnd, SORT_UP_DOWN eSortUpDown)
{
	if (nEnd > nBegin)
	{
		int nTemp = vecSortValue[nBegin];
		int i = nBegin;
		int j = nEnd;
		while (i < j)
		{
			if (eSortUpDown == SORT_TO_UP)
			{
				// ��������
				while (i < j && vecSortValue[j] >= nTemp)
				{
					j--;
				}
				if ( i != j )
				{
					vecSortValue[i] = vecSortValue[j];
				}

				while (i < j && vecSortValue[i] < nTemp)
				{
					i++;
				}

				if (i != j)
				{
					vecSortValue[j] = vecSortValue[i];
				}
			} 
			else
			{
				// �ݼ�����
				while (i < j && vecSortValue[j] <= nTemp)
				{
					j--;
				}
				if (i != j)
				{
					vecSortValue[i] = vecSortValue[j];
				}

				while (i < j && vecSortValue[i] > nTemp)
				{
					i++;
				}

				if (i != j)
				{
					vecSortValue[j] = vecSortValue[i];
				}
			}
				
		}
		vecSortValue[i] = nTemp;

		QuickSort(vecSortValue, nBegin, i, eSortUpDown);
		QuickSort(vecSortValue, i+1, nEnd, eSortUpDown);
	}
}

// ѡ������
void SelectSort(vector<int> &vecSortValues, SORT_UP_DOWN eSortUpDown)
{
	int nTemp;
	int nIndex;
	for (int i = 0; i < vecSortValues.size(); i++)
	{
		nTemp = vecSortValues[i];
		nIndex = i;
		for (int j = i + 1; j < vecSortValues.size(); j++)
		{
			if (eSortUpDown == SORT_TO_UP)
			{
				// ��������
				if (vecSortValues[j] < nTemp)
				{
					nTemp = vecSortValues[j];
					nIndex = j;
				}
			}
			else
			{
				// �ݼ�����
				if (vecSortValues[j] > nTemp)
				{
					nTemp = vecSortValues[j];
					nIndex = j;
				}
			}
		}
		vecSortValues[nIndex] = vecSortValues[i];
		vecSortValues[i] = nTemp;
	}
}


// ð������
void MaoPaoSort(vector<int> &vecSortValues, SORT_UP_DOWN eSortUpDown)
{
	int nTemp;
	for (int i = 0; i < vecSortValues.size(); i++)
	{
		for (int j = i + 1; j < vecSortValues.size(); j++)
		{
			if (eSortUpDown == SORT_TO_UP)
			{
				// ��������
				if (vecSortValues[j] < vecSortValues[i])
				{
					nTemp = vecSortValues[i];
					vecSortValues[i] = vecSortValues[j];
					vecSortValues[j] = nTemp;
				}
			} 
			else
			{
				// �ݼ�����
				if (vecSortValues[j] > vecSortValues[i])
				{
					nTemp = vecSortValues[i];
					vecSortValues[i] = vecSortValues[j];
					vecSortValues[j] = nTemp;
				}
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vecQuickSort = {0, 8, 95, 6,951, 23, 1, 5, 689, 64, 2, 66, 3, 89, 55, 4, 666, 5,8888, 964,593, 12,576, 31};
	PrintVecSort(vecQuickSort, QUICK_SORT, SORT_TO_UP, SORT_BEFORE);
	QuickSort(vecQuickSort, 0, vecQuickSort.size() - 1, SORT_TO_UP);
	PrintVecSort(vecQuickSort, QUICK_SORT, SORT_TO_UP, SORT_AFTER);
	cout << endl;
	PrintVecSort(vecQuickSort, QUICK_SORT, SORT_TO_DOWN, SORT_BEFORE);
	QuickSort(vecQuickSort, 0, vecQuickSort.size() - 1, SORT_TO_DOWN);
	PrintVecSort(vecQuickSort, QUICK_SORT, SORT_TO_DOWN, SORT_AFTER);

	cout << endl;
	cout << endl;
	cout << endl;
	vector<int> vecSelecSort = { 0, 8, 95, 6, 951, 23, 1, 9, 689, 64, 2, 66, 66, 3, 89, 55, 4, 666, 5, 888, 8888, 964, 593, 12, 576, 31 };
	PrintVecSort(vecSelecSort, SELECT_SORT, SORT_TO_UP, SORT_BEFORE);
	SelectSort(vecSelecSort, SORT_TO_UP);
	PrintVecSort(vecSelecSort, SELECT_SORT, SORT_TO_UP, SORT_AFTER);
	cout << endl;
	PrintVecSort(vecSelecSort, SELECT_SORT, SORT_TO_DOWN, SORT_BEFORE);
	SelectSort(vecSelecSort, SORT_TO_DOWN);
	PrintVecSort(vecSelecSort, SELECT_SORT, SORT_TO_DOWN, SORT_AFTER);

	cout << endl;
	cout << endl;
	cout << endl;
	vector<int> vecMaoPaoSort = { 0, 8, 95, 6, 951, 67, 1, 9, 689, 64, 2, 68, 69, 3, 89, 55, 4, 666, 5, 5, 888, 8888, 964, 593, 12, 576, 31 };
	PrintVecSort(vecMaoPaoSort, MAOPAO_SORT, SORT_TO_UP, SORT_BEFORE);
	MaoPaoSort(vecMaoPaoSort, SORT_TO_UP);
	PrintVecSort(vecMaoPaoSort, MAOPAO_SORT, SORT_TO_UP, SORT_AFTER);
	cout << endl;
	PrintVecSort(vecMaoPaoSort, MAOPAO_SORT, SORT_TO_DOWN, SORT_BEFORE);
	MaoPaoSort(vecMaoPaoSort, SORT_TO_DOWN);
	PrintVecSort(vecMaoPaoSort, MAOPAO_SORT, SORT_TO_DOWN, SORT_AFTER);

	getchar();
	getchar();
	getchar();
	
	return 0;
}