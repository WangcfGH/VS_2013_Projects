/*
// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MinABT 5	//���˳�ӳ���
#define MaxABT 13	//�˳�ӳ���
#define MaxNUM 14	//

//  һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//	����2, ����3������K, ����A   (0- 12)
//	÷��2, ÷��3��÷��K, ÷��A   (13-25)
//	����2, ����3������K, ����A   (26-38)
//	����2, ����3������K, ����A   (39-51)
//  С��                           (52)
//  ����                           (53)  
//  ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2,3,4,5,6,7,8,9,10,J,Q,K,A��13��


//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A,2,3,4,5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//˳�Ӳ��ܳ���2����ͬ���� ����2,3,3,4,5,6�Ͳ�Ϊ˳��


//�ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ�3����Ŀ��
//��һ������Ϊ�����ᣬ������Ϊ������


//------------��һ�⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ڣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ۣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ܣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunzi����: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;

	if (nCardCount < MinABT || nCardCount > MaxABT) {
		return false;
	}

	int cards[MaxNUM] = { 0 };
	for (int i = 0; i < nCardCount; i++) {
		int num = nCardID[i] % 13;
		int color = nCardID[i] / 13;
		if (color >= 4) {
			cards[13] ++;
		}
		else {
			num = (num == 0) ? 12 : num - 1;
			cards[num]++;
		}
	}

	int len = 0, min = 0;
	bool flag = false;
	for (int i = 0; i < MaxNUM - 1; i++) {
		if (cards[i] == 1) {
			if (!flag) {
				flag = true;
				min = i;
			}
			len++;
			if (len == nCardCount) {
				break;
			}
		}
		else if (cards[i] == 0) {
			if (!flag) {
				continue;
			}
			bRet = false;
			break;
		}
		else {
			bRet = false;
			break;
		}
	}


	if (len != nCardCount) {
		bRet = false;
	}

	return bRet;
}




//------------�ڶ��⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ܣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ݣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunziEx����: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;

	if (nCardCount < MinABT || nCardCount > MaxABT) {
		return false;
	}

	int cards[MaxNUM] = { 0 };
	for (int i = 0; i < nCardCount; i++) {
		int num = nCardID[i] % 13;
		int color = nCardID[i] / 13;
		if (color >= 4) {
			cards[13] ++;
		}
		else {
			num = num == 0 ? 12 : num - 1;
			cards[num]++;
		}
	}

	int len = 0, min = 0;
	bool flag = false;
	for (int i = 0; i < MaxNUM - 1; i++) {
		if (cards[i] == 1) {
			if (!flag) {
				flag = true;
				min = i;
			}
			len++;
			if (len == nCardCount) {
				break;
			}
		}
		else if (cards[i] == 0) {
			if (!flag) {
				continue;
			}
			if (cards[13] != 0) {
				cards[13] --;
				len++;
				if (len == nCardCount) {
					break;
				}
			}
			else {
				bRet = false;
				break;
			}
		}
		else {
			bRet = false;
			break;
		}
	}

	if (len + cards[13] != nCardCount) {
		bRet = false;
	}

	return bRet;
}




//------------�����⣺�ҳ����˳�ӳ���(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ҳ��������nCardID[ ]���˳�ӵĳ��ȣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������GetMaxShunziCount����: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//�����Ǹ�����
	//����ȱ�֤ǰ2��ĵ��Խ����ȷ����ʱ�����������⣬ûʱ����Բ���
	int max_len = 0;

	int cards[MaxNUM] = { 0 };
	for (int i = 0; i < nCardCount; i++) {
		int num = nCardID[i] % 13;
		int color = nCardID[i] / 13;
		if (color >= 4) {
			cards[13] ++;
		}
		else {
			num = num == 0 ? 12 : num - 1;
			cards[num]++;
		}
	}

	for (int j = 0; j < MaxNUM - 1; j++) {
		int use_lazi = 0;
		int len = 0, min = 0;
		bool flag = false;
		for (int i = j; i < MaxNUM - 1; i++) {
			if (cards[i] >= 1) {
				if (!flag) {
					flag = true;
					min = i;
				}
				len++;
				max_len = (cards[13] + len) > max_len ? cards[13] + len : max_len;
			}
			else if (cards[i] == 0) {
				if (!flag) {
					continue;
				}
				if (cards[13] != 0) {
					cards[13] --;
					len++;
					use_lazi++;
				}
				else {
					break;
				}
			}
		}

		cards[13] += use_lazi;
	}

	// max_len = max_len >= MinABT ? max_len : 0;
	max_len = max_len <= MaxABT ? max_len : MaxABT;

	return max_len;
}

int main(int argc, char* argv[])
{
	int nCardID[13] = { 53, 53, 54, 54, 4, 5, 6, 7, 8, 9, 23, 11, 23 };
	int nCardCount = 13;

	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");

	if (IsShunziEx(nCardID, nCardCount))
		printf("Is ShunziEx!\n");
	else
		printf("Is Not ShunziEx\n");

	int nMaxShunziCount = GetMaxShunziCount(nCardID, nCardCount);
	printf("MaxShunziCount:%d\n", nMaxShunziCount);

	getchar();
	getchar();

	return 0;
}

*/


/*
//1����Ŀ���ƣ��˿˵�һ��
//һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//����2, ����3������K, ����A(0 - 12)
//÷��2, ÷��3��÷��K, ÷��A(13 - 25)
//����2, ����3������K, ����A(26 - 38)
//����2, ����3������K, ����A(39 - 51)
//С��(52)
//����(53)
//ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A��13��
//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A, 2, 3, 4, 5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//	  ˳�Ӳ��ܳ���2����ͬ���� ����2, 3, 3, 4, 5, 6�Ͳ�Ϊ˳��
//	  �ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ���Ŀ��
//	  ��һ������Ϊ������������Ϊ������
//	  ------------��һ�⣺�ж��Ƿ���˳��(��������)-------------- -
//	  ��Ҫ��٣����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������
//	  Ԫ�صĸ��������Ƶ�������
//	  ��Ҫ��ڣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//	  ��Ҫ��ۣ�����˳�ӷ���true������˳�ӷ���false��
//	  ��Ҫ��ܣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
//  ��������Ҫ�������IsShunzi���� :
//�����������
#include <stdio.h>
#include "stdafx.h"
bool IsShunzi(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;
	int idTmp = 0;
	int num = nCardCount - 1;
	//ȡ������
	while (num > 1) {
		printf("num = \n");
		for (int i = 0; i < num; i++) {
			//��С��ֱ�ӷ���false
			if (nCardID[i] > 51) {
				return false;
			}
			else if (nCardID[i] % 13 > nCardID[i + 1] % 13) {
				idTmp = nCardID[i];
				nCardID[i] = nCardID[i + 1];
				nCardID[i + 1] = idTmp;
			}
			else if (nCardID[i] % 13 == nCardID[i + 1] % 13) { //���ֱ�ӷ���
				return false;
			}
		}
		num--;
	}
	//��СΪA����false
	if (nCardID[0] % 13 == 12) {
		return false;
	}
	num = nCardCount - 1;
	for (int i = 0; i < num; i++) {
		int sub = nCardID[i + 1] % 13 - nCardID[i] % 13;
		if (sub > 1) {
			return false;
		}
	}
	return bRet;
}
int main(int argc, char* argv[])
{
	int nCardID[7] = { 0, 1, 3, 4, 53, 6, 8 };
	int nCardCount = 7;
	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");
	return 0;
}

//2����Ŀ���ƣ��˿˵ڶ���
//һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//����2, ����3������K, ����A(0 - 12)
//÷��2, ÷��3��÷��K, ÷��A(13 - 25)
//����2, ����3������K, ����A(26 - 38)
//����2, ����3������K, ����A(39 - 51)
//С��(52)
//����(53)
//ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A��13��
//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A, 2, 3, 4, 5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//	  ˳�Ӳ��ܳ���2����ͬ���� ����2, 3, 3, 4, 5, 6�Ͳ�Ϊ˳��
//	  �ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ���Ŀ��
//	  ��һ������Ϊ�����ᣬ������Ϊ������
//	  ------------�ڶ��⣺�ж��Ƿ���˳��(��������)-------------- -
//	  ��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//	  ��Ҫ��ڣ����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������
//	  Ԫ�صĸ��������Ƶ�������
//	  ��Ҫ��ۣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//	  ��Ҫ��ܣ�����˳�ӷ���true������˳�ӷ���false��
//	  ��Ҫ��ݣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
//  ��������Ҫ�������IsShunziEx���� :
//�����������
#include <stdio.h>
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;
	int idTmp = 0;
	int num = nCardCount - 1;
	int count = 0;
	//ȡ������
	while (num > 0) {
		printf("num %d %d \n", num, nCardID[num]);
		for (int i = 0; i < num; i++) {
			//��С��ֱ�ӷ���false
			if (nCardID[i] > 51) {
				count++;
			}
			if (nCardID[i] % 13 > nCardID[i + 1] % 13) {
				idTmp = nCardID[i];
				nCardID[i] = nCardID[i + 1];
				nCardID[i + 1] = idTmp;
			}
			else if (nCardID[i] % 13 == nCardID[i + 1] % 13) { //���ֱ�ӷ���
				return false;
			}
		}
		num--;
	}
	//��СΪA����false
	if (nCardID[0] % 13 == 12) {
		return false;
	}
	num = nCardCount - 1;
	for (int i = 0; i < num; i++) {
		int sub = nCardID[i + 1] % 13 - nCardID[i] % 13;
		if (sub > 1) {
			sub -= 1;
			//������
			if (count >= sub) {
				count -= sub;
				continue;
			}
			return false;
		}
	}
	return bRet;
}
int main(int argc, char* argv[])
{
	int nCardID[7] = { 0, 1, 3, 4, 53, 6, 8 };
	int nCardCount = 7;
	if (IsShunziEx(nCardID, nCardCount))
		printf("Is ShunziEx!\n");
	else
		printf("Is Not ShunziEx\n");
	return 0;
}

//3����Ŀ���ƣ��˿˵�����
//һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//����2, ����3������K, ����A(0 - 12)
//÷��2, ÷��3��÷��K, ÷��A(13 - 25)
//����2, ����3������K, ����A(26 - 38)
//����2, ����3������K, ����A(39 - 51)
//С��(52)
//����(53)
//ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A��13��
//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A, 2, 3, 4, 5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//	  ˳�Ӳ��ܳ���2����ͬ���� ����2, 3, 3, 4, 5, 6�Ͳ�Ϊ˳��
//	  �ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ���Ŀ��
//	  ��һ������Ϊ�����⣬������Ϊ������
//	  ------------�����⣺�ҳ����˳�ӳ���(��������)-------------- -
//	  ��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//	  ��Ҫ��ڣ����ҳ��������nCardID[]���˳�ӵĳ��ȣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID
//	  ������Ԫ�صĸ��������Ƶ�������
//	  ��Ҫ��ۣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
//  ��������Ҫ�������GetMaxShunziCount���� :
//�����������
#include <stdio.h>
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//�����Ǹ�����
	//����ȱ�֤ǰ2��ĵ��Խ����ȷ����ʱ�����������⣬ûʱ����Բ���
	int idTmp = 0;
	int num = nCardCount - 1;
	int count = 0;
	//ȡ������
	while (num > 0) {
		printf("num %d %d \n", num, nCardID[num]);
		for (int i = 0; i < num; i++) {
			//��С��ֱ�ӷ���false
			if (nCardID[i] > 51) {
				count++;
			}
			if (nCardID[i] % 13 > nCardID[i + 1] % 13) {
				idTmp = nCardID[i];
				nCardID[i] = nCardID[i + 1];
				nCardID[i + 1] = idTmp;
			}
		}
		num--;
	}
	int maxNum = 0;
	int tmpMaxNum = 0;
	num = nCardCount - 1;
	for (int i = 0; i < num; i++) {
		int sub = nCardID[i + 1] % 13 - nCardID[i] % 13;
		if (sub > 1) {
			sub -= 1;
			//������
			if (count >= sub) {
				count -= sub;
				tmpMaxNum += sub;
				continue;
			}
			//���浱ǰ���
			if (maxNum > tmpMaxNum) {
				maxNum = tmpMaxNum;
			}
			tmpMaxNum = 0;
			continue;
		}
		else if (sub == 0) {
			//���浱ǰ���
			if (maxNum > tmpMaxNum) {
				maxNum = tmpMaxNum;
			}
			tmpMaxNum = 0;
			continue;
		}
		tmpMaxNum++;
	}
	return maxNum;
}

int main(int argc, char* argv[])
{
	int nCardID[7] = { 0, 1, 3, 4, 53, 6, 8 };
	int nCardCount = 7;
	int nMaxShunziCount = GetMaxShunziCount(nCardID, nCardCount);
	printf("MaxShunziCount:%d\n", nMaxShunziCount);
	return 0;
}
*/

/*
#include "stdafx.h"
#include <stdio.h>

bool IsShunziCur(int nCardID[], int nCardCount)
{
	bool bRet = true;
	if (nCardCount >= 2)
	{
		if ((nCardID[nCardCount - 1] % 13) - (nCardID[nCardCount - 2] % 13) != 1)
			bRet = false;
	}
	bool curRet = IsShunziCur(nCardID, nCardCount - 1);

	return (bRet && curRet);

}
bool IsShunzi(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;
	int sum = 0;
	for (int idx = 0; idx < nCardCount; idx++)
	{
		int min = idx;
		if (nCardID[idx] >= 52)
			return false;
		for (int jdx = idx + 1; jdx < nCardCount; jdx++)
		{
			if (nCardID[jdx] >= 52)
				return false;

			if (nCardID[jdx] < nCardID[min])
				min = jdx;
		}

		sum += nCardID[min];
		int temp = nCardID[min];		
		nCardID[min] = nCardID[idx];
		nCardID[idx] = temp;
	}

	bool ret = IsShunziCur(nCardID, nCardCount);

	return ret;
}

int main(int argc, char* argv[])
{
	//int nCardID[7] = { 0, 1, 3, 4, 53, 6, 8 };
	int nCardID[7] = { 0, 14, 15, 3, 4, 5, 6 };
	int nCardCount = 7;

	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");

	getchar();
	getchar();

	return 0;
}



// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include<algorithm>

#define MinABT 5	//���˳�ӳ���
#define MaxABT 13	//�˳�ӳ���

//  һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//	����2, ����3������K, ����A   (0- 12)
//	÷��2, ÷��3��÷��K, ÷��A   (13-25)
//	����2, ����3������K, ����A   (26-38)
//	����2, ����3������K, ����A   (39-51)
//  С��                           (52)
//  ����                           (53)  
//  ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2,3,4,5,6,7,8,9,10,J,Q,K,A��13��


//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A,2,3,4,5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//˳�Ӳ��ܳ���2����ͬ���� ����2,3,3,4,5,6�Ͳ�Ϊ˳��


//�ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ�3����Ŀ��
//��һ������Ϊ�����ᣬ������Ϊ������



//------------��һ�⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ڣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ۣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ܣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunzi����: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;

	if (nCardCount < MinABT || nCardCount > MaxABT) {
		return false;
	}

	int nCardSet[MaxABT] = { 0 };

	for (int i = 0; i < nCardCount; i++) {
		if (nCardID[i] >= 52) {
			return false;
		}

		int nCardValue = nCardID[i] % 13;
		nCardSet[nCardValue]++;
		if (nCardSet[nCardValue] > 1) {
			// �ж�����ͬ�ķ���false
			return false;
		}
	}

	int nContinueNum = 0;		// ��������
	bool bStart = false;		// ˳���Ƿ�ʼ

	for (int i = 0; i < MaxABT; i++) {
		if (nCardSet[i] != 0) {
			nContinueNum++;
			bStart = true;
		}

		if (nCardSet[i] == 0 && bStart) {
			break;
		}
	}

	bRet = (nContinueNum == nCardCount ? true : false);

	return bRet;
}




//------------�ڶ��⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ܣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ݣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunziEx����: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;

	if (nCardCount < MinABT || nCardCount > MaxABT) {
		return false;
	}

	int nCardSet[MaxABT] = { 0 };
	int nKing = 0;

	for (int i = 0; i < nCardCount; i++) {
		if (nCardID[i] == 52 || nCardID[i] == 53) {
			nKing++;
			continue;
		}

		int nCardValue = nCardID[i] % 13;
		nCardSet[nCardValue]++;
		if (nCardSet[nCardValue] > 1) {
			// �ж�����ͬ�ķ���false
			return false;
		}
	}

	int nContinueNum = 0;		// ��������
	bool bStart = false;		// ˳���Ƿ�ʼ

	for (int i = 0; i < MaxABT; i++) {
		if (nCardSet[i] != 0) {
			nContinueNum++;
			bStart = true;
		}

		if (nCardSet[i] == 0 && bStart) {
			if (nKing > 0) {
				nContinueNum++;
				nKing--;
			}
			else {
				break;
			}
		}
	}

	bRet = ((nContinueNum + nKing) == nCardCount ? true : false);

	return bRet;
}




//------------�����⣺�ҳ����˳�ӳ���(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ҳ��������nCardID[ ]���˳�ӵĳ��ȣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������GetMaxShunziCount����: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//�����Ǹ�����
	//����ȱ�֤ǰ2��ĵ��Խ����ȷ����ʱ�����������⣬ûʱ����Բ���

	if (nCardCount == 0) {
		return 0;
	}

	std::vector<int> nums;
	int nKing = 0;

	for (int i = 0; i < nCardCount; i++) {
		if (nCardID[i] == 52 || nCardID[i] == 53) {
			nKing++;
			continue;
		}

		int nCardValue = nCardID[i] % 13;
		nums.push_back(nCardValue);
	}

	sort(nums.begin(), nums.end());
	int nContinueNum = 0;		// ��������
	int nMaxShunziCount = 0;	// �����������
	int nKingTmp = nKing;
	int nBeginNum = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] - nums[i - 1] > 1 && nums[i] - nums[i - 1] - 1 <= nKingTmp) {
			nKingTmp -= (nums[i] - nums[i - 1] - 1);
		}
		else if (nums[i] - nums[i - 1] > 1) {
			nContinueNum = nums[i - 1] - nBeginNum + nKingTmp + 1;
			if (nContinueNum > nMaxShunziCount) {
				nMaxShunziCount = nContinueNum;
			}

			nBeginNum = nums[i];
			nKingTmp = nKing;
		}
	}

	nContinueNum = nums[nums.size() - 1] - nBeginNum + nKingTmp + 1;
	if (nContinueNum > nMaxShunziCount) {
		nMaxShunziCount = nContinueNum;
	}

	return nMaxShunziCount;
}

int main(int argc, char* argv[])
{
	//int nCardID[7] = { 0, 1, 4, 53, 15, 5, 6 };
	int nCardID[7] = { 0, 1, 53, 3, 7, 6, 8 };
	int nCardCount = 7;

	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");

	if (IsShunziEx(nCardID, nCardCount))
		printf("Is ShunziEx!\n");
	else
		printf("Is Not ShunziEx\n");

	int nMaxShunziCount = GetMaxShunziCount(nCardID, nCardCount);
	printf("MaxShunziCount:%d\n", nMaxShunziCount);


	getchar();
	getchar();
	getchar();

	return 0;
}

*/



/*
// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<algorithm>
using namespace std;
#define MinABT 5	//���˳�ӳ���
#define MaxABT 13	//�˳�ӳ���

//  һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//	����2, ����3������K, ����A   (0- 12)
//	÷��2, ÷��3��÷��K, ÷��A   (13-25)
//	����2, ����3������K, ����A   (26-38)
//	����2, ����3������K, ����A   (39-51)
//  С��                           (52)
//  ����                           (53)  
//  ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2,3,4,5,6,7,8,9,10,J,Q,K,A��13��


//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A,2,3,4,5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//˳�Ӳ��ܳ���2����ͬ���� ����2,3,3,4,5,6�Ͳ�Ϊ˳��


//�ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ�3����Ŀ��
//��һ������Ϊ�����ᣬ������Ϊ������



//------------��һ�⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ڣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ۣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ܣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunzi����: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;
	if (nCardCount < MinABT || nCardCount > MaxABT)
	{
		return false;
	}
	if (nCardID == NULL)
	{
		return false;
	}
	for (int i = 0; i < nCardCount; i++)
	{
		if (nCardID[i] == 52 || nCardID[i] == 53)
		{
			return false;
		}
		nCardID[i] = nCardID[i] % 13;
	}
	sort(nCardID, nCardID + nCardCount);

	for (int i = 0; i < nCardCount - 1; i++)
	{
		if (nCardID[i + 1] - nCardID[i] != 1)
		{
			bRet = false;
			break;
		}
	}
	return bRet;
}




//------------�ڶ��⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ܣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ݣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunziEx����: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;
	char allPower = 0;
	char allPower_ex = 0;
	if (nCardCount < MinABT || nCardCount > MaxABT)
	{
		return false;
	}
	if (nCardID == NULL)
	{
		return false;
	}
	for (int i = 0; i < nCardCount; i++)
	{
		if (nCardID[i] == 52 || nCardID[i] == 53)
		{
			allPower++;
		}
		else
		{
			nCardID[i] = nCardID[i] % 13;
		}
	}
	sort(nCardID, nCardID + nCardCount);
	allPower_ex = allPower;
	for (int i = 0; i < nCardCount - 1 - allPower_ex; i++)
	{
		if (nCardID[i] == 52 || nCardID[i] == 53)
		{
			continue;
		}
		if (nCardID[i + 1] == nCardID[i])
		{
			bRet = false;
			break;
		}
		else if (nCardID[i + 1] - nCardID[i] == 1)
		{

		}
		else if (nCardID[i + 1] - nCardID[i] - 1 <= allPower)
		{
			allPower = allPower - (nCardID[i + 1] - nCardID[i] - 1);
		}
		else
		{
			bRet = false;
			break;
		}
	}
	return bRet;
}




//------------�����⣺�ҳ����˳�ӳ���(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ҳ��������nCardID[ ]���˳�ӵĳ��ȣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������GetMaxShunziCount����: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//�����Ǹ�����
	//����ȱ�֤ǰ2��ĵ��Խ����ȷ����ʱ�����������⣬ûʱ����Բ���
	int allPower = 0;
	int allPower_ex = 0;
	int nShunzicount = 0;
	if (nCardCount < MinABT || nCardCount > MaxABT)
	{
		return 0;
	}
	if (nCardID == NULL)
	{
		return 0;
	}
	for (int i = 0; i < nCardCount; i++)
	{
		if (nCardID[i] == 52 || nCardID[i] == 53)
		{
			allPower++;
		}
		else
		{
			nCardID[i] = nCardID[i] % 13;
		}
	}
	sort(nCardID, nCardID + nCardCount);
	allPower_ex = allPower;
	for (int i = 0; i < nCardCount - 1 - allPower_ex; i++)
	{
		//printf("=%d==\r\n", nCardID[i]);
		if (nCardID[i] == 52 || nCardID[i] == 53)
		{
			continue;
		}
		if (nCardID[i + 1] == nCardID[i])
		{
			nShunzicount = 0;
			break;
		}
		else if (nCardID[i + 1] - nCardID[i] == 1)
		{
		}
		else if (nCardID[i + 1] - nCardID[i] - 1 <= allPower)
		{
			allPower = allPower - (nCardID[i + 1] - nCardID[i] - 1);
		}
		else
		{
			nShunzicount = 0;
			break;
		}
		nShunzicount++;
	}
	return nShunzicount + allPower_ex;
}

int main(int argc, char* argv[])
{
	//int nCardID[13] = { 1, 2, 3, 4, 5, 32, 52, 8, 9, 53, 11, 12, 13 };
	int nCardID[13] = { 1, 2, 3, 5, 6, 7, 52, 8, 9, 10, 11, 12, 13 };
	int nCardCount = 13;

	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");

	if (IsShunziEx(nCardID, nCardCount))
		printf("Is ShunziEx!\n");
	else
		printf("Is Not ShunziEx\n");

	int nMaxShunziCount = GetMaxShunziCount(nCardID, nCardCount);
	printf("MaxShunziCount:%d\n", nMaxShunziCount);

	getchar();
	getchar();
	getchar();

	return 0;
}


*/






/*
// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MinABT 5	//���˳�ӳ���
#define MaxABT 13	//�˳�ӳ���

//  һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//	����2, ����3������K, ����A   (0- 12)
//	÷��2, ÷��3��÷��K, ÷��A   (13-25)
//	����2, ����3������K, ����A   (26-38)
//	����2, ����3������K, ����A   (39-51)
//  С��                           (52)
//  ����                           (53)  
//  ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2,3,4,5,6,7,8,9,10,J,Q,K,A��13��


//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A,2,3,4,5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//˳�Ӳ��ܳ���2����ͬ���� ����2,3,3,4,5,6�Ͳ�Ϊ˳��


//�ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ�3����Ŀ��
//��һ������Ϊ�����ᣬ������Ϊ������



//------------��һ�⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ڣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ۣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ܣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunzi����: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;
	int minNum = 13;
	int maxNum = 0;
	int cardList[MaxABT] = { 0 };

	for (int i = 0; i < nCardCount; i++){
		if (nCardID[i] == 52 || nCardID[i] == 53)
			return false;

		int currentID = nCardID[i] % 13;
		cardList[currentID] = 1;
		if (currentID > maxNum)
			maxNum = currentID;
		if (currentID < minNum)
			minNum = currentID;
	}

	if (maxNum - minNum + 1 != nCardCount){
		bRet = false;
	}
	else{
		for (int j = minNum; j <= maxNum; j++){
			if (cardList[j] != 1){
				bRet = false;
				break;
			}
		}
	}

	return bRet;
}




//------------�ڶ��⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ܣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ݣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunziEx����: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;
	int minNum = 13;
	int maxNum = 0;
	int cardList[MaxABT] = { 0 };
	int exCount = 0;

	for (int i = 0; i < nCardCount; i++){
		if (nCardID[i] == 52 || nCardID[i] == 53){
			exCount = exCount + 1;
			continue;
		}

		int currentID = nCardID[i] % 13;
		cardList[currentID] = cardList[currentID] + 1;
		if (currentID > maxNum)
			maxNum = currentID;
		if (currentID < minNum)
			minNum = currentID;
	}

	for (int j = minNum; j <= maxNum; j++){
		if (cardList[j] > 1){
			return false;
		}

		if (cardList[j] == 0){
			if (exCount > 0){
				exCount = exCount - 1;
			}
			else{
				bRet = false;
				break;
			}
		}
	}

	return bRet;
}




//------------�����⣺�ҳ����˳�ӳ���(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ҳ��������nCardID[ ]���˳�ӵĳ��ȣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������GetMaxShunziCount����: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//�����Ǹ�����
	//����ȱ�֤ǰ2��ĵ��Խ����ȷ����ʱ�����������⣬ûʱ����Բ���
	int minNum = 13;
	int maxNum = 0;
	int cardList[MaxABT] = { 0 };
	int exCount = 0;

	for (int i = 0; i < nCardCount; i++){
		if (nCardID[i] == 52 || nCardID[i] == 53){
			exCount = exCount + 1;
			continue;
		}

		int currentID = nCardID[i] % 13;
		cardList[currentID] = cardList[currentID] + 1;
		if (currentID > maxNum)
			maxNum = currentID;
		if (currentID < minNum)
			minNum = currentID;
	}

	//std::vector<int> subShunZiSize;
	//int temp = 0;
	//for(int j = minNum; j <= maxNum; j++){
	//		if(cardList[j] > 0 ){
	//			temp = temp + 1;			
	//		}
	//		else{
	//			sunShunZiSize.push_back(temp);
	//			temp = 0;
	//		}
	//}

	//int maxSize = 0;
	//int size = subShunZiSize.size();
	//if(exCount == 0){
	//	for(int t = 0; t < size; t++){
	//		if(subShunZiSize[t] > maxSize)
	//		{
	//			maxSize = subShunZiSize[t];
	//		}
	//		return maxSize;
	//	}
	//}
	//if(exCount == 1)
	//shuang xiabiao

	//if(exCount == 2)
	//huadongchuangkou
	//dangezuidadebiaojia]o

	return 0;
}

int main(int argc, char* argv[])
{
	int nCardID[7] = { 0, 1, 3, 4, 53, 6, 8 };
	int nCardCount = 7;

	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");

	if (IsShunziEx(nCardID, nCardCount))
		printf("Is ShunziEx!\n");
	else
		printf("Is Not ShunziEx\n");

	int nMaxShunziCount = GetMaxShunziCount(nCardID, nCardCount);
	printf("MaxShunziCount:%d\n", nMaxShunziCount);

	return 0;
}
*/









// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MinABT 5	//���˳�ӳ���
#define MaxABT 13	//�˳�ӳ���

//  һ���˿��ɷ��飬÷�������ң��������ֻ�ɫ��13�ż���С����������һ����ɣ���54���ơ��ȶ���ID���£�
//	����2, ����3������K, ����A   (0- 12)
//	÷��2, ÷��3��÷��K, ÷��A   (13-25)
//	����2, ����3������K, ����A   (26-38)
//	����2, ����3������K, ����A   (39-51)
//  С��                           (52)
//  ����                           (53)  
//  ע������K�������ǻ�ɫ��K���Ƶ㡣��ȥ��С���⣬�Ƶ���2,3,4,5,6,7,8,9,10,J,Q,K,A��13��


//���n���Ƶ��Ƶ������������n���ƹ���"˳��"���磺"����2������3������4������5������6��÷��7".
//���������:A,2,3,4,5�������˳��(Aֻ�ܵ����ģ����ܵ���С��)
//˳�Ӳ��ܳ���2����ͬ���� ����2,3,3,4,5,6�Ͳ�Ϊ˳��


//�ڿ�ʼ����ǰ����ϸ�Ķ����ϵ�˵����Ȼ���ٲ鿴���µ�3����Ŀ��
//��һ������Ϊ�����ᣬ������Ϊ������



//------------��һ�⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ڣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ۣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ܣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunzi����: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;

	for (int i = 0; i < nCardCount - 1; ++i)
	{
		if ((nCardID[i] == 12 || nCardID[i] == 25 || nCardID[i] == 38 || nCardID[i] == 51) && i < nCardCount - 1)
		{
			// �����һ����A
			return false;
		}
		if (nCardID[i] == (nCardID[i + 1] - 1)
			|| nCardID[i] == (nCardID[i + 1] - 14)
			|| nCardID[i] == (nCardID[i + 1] - 27)
			|| nCardID[i] == (nCardID[i + 1] - 40)
			|| nCardID[i] == (nCardID[i + 1] + 12)
			|| nCardID[i] == (nCardID[i + 1] + 25)
			|| nCardID[i] == (nCardID[i + 1] + 38)
			)
		{
			continue;
		}
		else
		{
			return false;
		}
	}

	return bRet;
}




//------------�ڶ��⣺�ж��Ƿ���˳��(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ж��������nCardID[]�Ƿ���˳�ӣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ���nCardID[]���nCardCount���Ʊ���ȫ�����ϣ�һ���ò��϶�����˳�ӡ�
//��Ҫ��ܣ�����˳�ӷ���true������˳�ӷ���false��
//��Ҫ��ݣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������IsShunziEx����: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//�����Ǳ�����
	//ע�⸽������Բ������������Ҫ��֤ǰ2���������Խ����ȷ�����򲻸���
	bool bRet = true;

	for (int i = 0; i < nCardCount - 1; ++i)
	{
		if ((nCardID[i] == 12 || nCardID[i] == 25 || nCardID[i] == 38 || nCardID[i] == 51) && i < nCardCount - 1)
		{
			// �����һ����A
			return false;
		}
		if (nCardID[i] == (nCardID[i + 1] - 1)
			|| nCardID[i] == (nCardID[i + 1] - 14)
			|| nCardID[i] == (nCardID[i + 1] - 27)
			|| nCardID[i] == (nCardID[i + 1] - 40)
			|| nCardID[i] == (nCardID[i + 1] + 12)
			|| nCardID[i] == (nCardID[i + 1] + 25)
			|| nCardID[i] == (nCardID[i + 1] + 38)
			)
		{
			continue;
		}
		else
		{
			if (52 == nCardID[i]
				|| 53 == nCardID[i]
				|| 52 == nCardID[i + 1]
				|| 53 == nCardID[i + 1])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}

	return bRet;
}




//------------�����⣺�ҳ����˳�ӳ���(��������)---------------
//��Ҫ��٣��������С�����Գ䵱����һ����ʹ�ã��������ơ�
//��Ҫ��ڣ����ҳ��������nCardID[ ]���˳�ӵĳ��ȣ�nCardID�����д洢�����Ƶ�ID��nCardCount��ָnCardID������Ԫ�صĸ��������Ƶ�������
//��Ҫ��ۣ��������ܸߵ�Ч���Լ������ܺõ��㷨��
// ��������Ҫ�������GetMaxShunziCount����: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//�����Ǹ�����
	//����ȱ�֤ǰ2��ĵ��Խ����ȷ����ʱ�����������⣬ûʱ����Բ���

	return 0;
}

int main(int argc, char* argv[])
{
	//int nCardID[7]={0,1,3,4,53,6,8}; //����ID��Ϊʾ������ֻ��ͨ��ʾ����
	//int nCardID[7] = { 52, 1, 28, 3, 17, 5, 53 };
	int nCardID[7] = { 1, 3, 2, 4, 6, 7, 5 };
	int nCardCount = 7;

	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");

	if (IsShunziEx(nCardID, nCardCount))
		printf("Is ShunziEx!\n");
	else
		printf("Is Not ShunziEx\n");

	int nMaxShunziCount = GetMaxShunziCount(nCardID, nCardCount);
	printf("MaxShunziCount:%d\n", nMaxShunziCount);

	getchar();
	getchar();
	return 0;
}

