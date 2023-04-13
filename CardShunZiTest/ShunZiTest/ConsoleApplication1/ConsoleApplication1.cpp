/*
// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MinABT 5	//最短顺子长度
#define MaxABT 13	//最长顺子长度
#define MaxNUM 14	//

//  一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//	方块2, 方块3…方块K, 方块A   (0- 12)
//	梅花2, 梅花3…梅花K, 梅花A   (13-25)
//	红桃2, 红桃3…红桃K, 红桃A   (26-38)
//	黑桃2, 黑桃3…黑桃K, 黑桃A   (39-51)
//  小王                           (52)
//  大王                           (53)  
//  注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2,3,4,5,6,7,8,9,10,J,Q,K,A共13种


//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A,2,3,4,5不能组成顺子(A只能当最大的，不能当最小的)
//顺子不能出现2张相同的牌 比如2,3,3,4,5,6就不为顺子


//在开始做题前请仔细阅读以上的说明，然后再查看以下的3个题目。
//第一、二题为必做提，第三题为附加题


//------------第一题：判断是否是顺子(无万能牌)---------------
//（要求①）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求②）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求③）：是顺子返回true，不是顺子返回false。
//（要求④）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunzi函数: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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




//------------第二题：判断是否是顺子(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求④）：是顺子返回true，不是顺子返回false。
//（要求⑤）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunziEx函数: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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




//------------附加题：找出最长的顺子长度(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：找出随机数组nCardID[ ]中最长顺子的长度，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计GetMaxShunziCount函数: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//本题是附加题
	//务必先保证前2题的调试结果正确，有时间再做附加题，没时间可以不做
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
//1、题目名称：扑克第一题
//一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//方块2, 方块3…方块K, 方块A(0 - 12)
//梅花2, 梅花3…梅花K, 梅花A(13 - 25)
//红桃2, 红桃3…红桃K, 红桃A(26 - 38)
//黑桃2, 黑桃3…黑桃K, 黑桃A(39 - 51)
//小王(52)
//大王(53)
//注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A共13种
//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A, 2, 3, 4, 5不能组成顺子(A只能当最大的，不能当最小的)
//	  顺子不能出现2张相同的牌 比如2, 3, 3, 4, 5, 6就不为顺子
//	  在开始做题前请仔细阅读以上的说明，然后再查看以下的题目。
//	  第一、二题为必做，第三题为附加题
//	  ------------第一题：判断是否是顺子(无万能牌)-------------- -
//	  （要求①）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中
//	  元素的个数，即牌的张数。
//	  （要求②）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//	  （要求③）：是顺子返回true，不是顺子返回false。
//	  （要求④）：尽可能高的效率以及尽可能好的算法。
//  根据以上要求请设计IsShunzi函数 :
//考生解决方案
#include <stdio.h>
#include "stdafx.h"
bool IsShunzi(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
	bool bRet = true;
	int idTmp = 0;
	int num = nCardCount - 1;
	//取余排序
	while (num > 1) {
		printf("num = \n");
		for (int i = 0; i < num; i++) {
			//大小王直接返回false
			if (nCardID[i] > 51) {
				return false;
			}
			else if (nCardID[i] % 13 > nCardID[i + 1] % 13) {
				idTmp = nCardID[i];
				nCardID[i] = nCardID[i + 1];
				nCardID[i + 1] = idTmp;
			}
			else if (nCardID[i] % 13 == nCardID[i + 1] % 13) { //相等直接返回
				return false;
			}
		}
		num--;
	}
	//最小为A返回false
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

//2、题目名称：扑克第二题
//一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//方块2, 方块3…方块K, 方块A(0 - 12)
//梅花2, 梅花3…梅花K, 梅花A(13 - 25)
//红桃2, 红桃3…红桃K, 红桃A(26 - 38)
//黑桃2, 黑桃3…黑桃K, 黑桃A(39 - 51)
//小王(52)
//大王(53)
//注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A共13种
//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A, 2, 3, 4, 5不能组成顺子(A只能当最大的，不能当最小的)
//	  顺子不能出现2张相同的牌 比如2, 3, 3, 4, 5, 6就不为顺子
//	  在开始做题前请仔细阅读以上的说明，然后再查看以下的题目。
//	  第一、二题为必做提，第三题为附加题
//	  ------------第二题：判断是否是顺子(有万能牌)-------------- -
//	  （要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//	  （要求②）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中
//	  元素的个数，即牌的张数。
//	  （要求③）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//	  （要求④）：是顺子返回true，不是顺子返回false。
//	  （要求⑤）：尽可能高的效率以及尽可能好的算法。
//  根据以上要求请设计IsShunziEx函数 :
//考生解决方案
#include <stdio.h>
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
	bool bRet = true;
	int idTmp = 0;
	int num = nCardCount - 1;
	int count = 0;
	//取余排序
	while (num > 0) {
		printf("num %d %d \n", num, nCardID[num]);
		for (int i = 0; i < num; i++) {
			//大小王直接返回false
			if (nCardID[i] > 51) {
				count++;
			}
			if (nCardID[i] % 13 > nCardID[i + 1] % 13) {
				idTmp = nCardID[i];
				nCardID[i] = nCardID[i + 1];
				nCardID[i + 1] = idTmp;
			}
			else if (nCardID[i] % 13 == nCardID[i + 1] % 13) { //相等直接返回
				return false;
			}
		}
		num--;
	}
	//最小为A返回false
	if (nCardID[0] % 13 == 12) {
		return false;
	}
	num = nCardCount - 1;
	for (int i = 0; i < num; i++) {
		int sub = nCardID[i + 1] % 13 - nCardID[i] % 13;
		if (sub > 1) {
			sub -= 1;
			//万能牌
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

//3、题目名称：扑克第三题
//一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//方块2, 方块3…方块K, 方块A(0 - 12)
//梅花2, 梅花3…梅花K, 梅花A(13 - 25)
//红桃2, 红桃3…红桃K, 红桃A(26 - 38)
//黑桃2, 黑桃3…黑桃K, 黑桃A(39 - 51)
//小王(52)
//大王(53)
//注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A共13种
//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A, 2, 3, 4, 5不能组成顺子(A只能当最大的，不能当最小的)
//	  顺子不能出现2张相同的牌 比如2, 3, 3, 4, 5, 6就不为顺子
//	  在开始做题前请仔细阅读以上的说明，然后再查看以下的题目。
//	  第一、二题为必做题，第三题为附加题
//	  ------------附加题：找出最长的顺子长度(有万能牌)-------------- -
//	  （要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//	  （要求②）：找出随机数组nCardID[]中最长顺子的长度，nCardID数组中存储都是牌的ID，nCardCount是指nCardID
//	  数组中元素的个数，即牌的张数。
//	  （要求③）：尽可能高的效率以及尽可能好的算法。
//  根据以上要求请设计GetMaxShunziCount函数 :
//考生解决方案
#include <stdio.h>
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//本题是附加题
	//务必先保证前2题的调试结果正确，有时间再做附加题，没时间可以不做
	int idTmp = 0;
	int num = nCardCount - 1;
	int count = 0;
	//取余排序
	while (num > 0) {
		printf("num %d %d \n", num, nCardID[num]);
		for (int i = 0; i < num; i++) {
			//大小王直接返回false
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
			//万能牌
			if (count >= sub) {
				count -= sub;
				tmpMaxNum += sub;
				continue;
			}
			//保存当前最长数
			if (maxNum > tmpMaxNum) {
				maxNum = tmpMaxNum;
			}
			tmpMaxNum = 0;
			continue;
		}
		else if (sub == 0) {
			//保存当前最长数
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
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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

#define MinABT 5	//最短顺子长度
#define MaxABT 13	//最长顺子长度

//  一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//	方块2, 方块3…方块K, 方块A   (0- 12)
//	梅花2, 梅花3…梅花K, 梅花A   (13-25)
//	红桃2, 红桃3…红桃K, 红桃A   (26-38)
//	黑桃2, 黑桃3…黑桃K, 黑桃A   (39-51)
//  小王                           (52)
//  大王                           (53)  
//  注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2,3,4,5,6,7,8,9,10,J,Q,K,A共13种


//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A,2,3,4,5不能组成顺子(A只能当最大的，不能当最小的)
//顺子不能出现2张相同的牌 比如2,3,3,4,5,6就不为顺子


//在开始做题前请仔细阅读以上的说明，然后再查看以下的3个题目。
//第一、二题为必做提，第三题为附加题



//------------第一题：判断是否是顺子(无万能牌)---------------
//（要求①）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求②）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求③）：是顺子返回true，不是顺子返回false。
//（要求④）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunzi函数: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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
			// 有多张相同的返回false
			return false;
		}
	}

	int nContinueNum = 0;		// 连续数量
	bool bStart = false;		// 顺子是否开始

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




//------------第二题：判断是否是顺子(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求④）：是顺子返回true，不是顺子返回false。
//（要求⑤）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunziEx函数: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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
			// 有多张相同的返回false
			return false;
		}
	}

	int nContinueNum = 0;		// 连续数量
	bool bStart = false;		// 顺子是否开始

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




//------------附加题：找出最长的顺子长度(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：找出随机数组nCardID[ ]中最长顺子的长度，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计GetMaxShunziCount函数: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//本题是附加题
	//务必先保证前2题的调试结果正确，有时间再做附加题，没时间可以不做

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
	int nContinueNum = 0;		// 连续数量
	int nMaxShunziCount = 0;	// 最大连续数量
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
#define MinABT 5	//最短顺子长度
#define MaxABT 13	//最长顺子长度

//  一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//	方块2, 方块3…方块K, 方块A   (0- 12)
//	梅花2, 梅花3…梅花K, 梅花A   (13-25)
//	红桃2, 红桃3…红桃K, 红桃A   (26-38)
//	黑桃2, 黑桃3…黑桃K, 黑桃A   (39-51)
//  小王                           (52)
//  大王                           (53)  
//  注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2,3,4,5,6,7,8,9,10,J,Q,K,A共13种


//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A,2,3,4,5不能组成顺子(A只能当最大的，不能当最小的)
//顺子不能出现2张相同的牌 比如2,3,3,4,5,6就不为顺子


//在开始做题前请仔细阅读以上的说明，然后再查看以下的3个题目。
//第一、二题为必做提，第三题为附加题



//------------第一题：判断是否是顺子(无万能牌)---------------
//（要求①）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求②）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求③）：是顺子返回true，不是顺子返回false。
//（要求④）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunzi函数: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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




//------------第二题：判断是否是顺子(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求④）：是顺子返回true，不是顺子返回false。
//（要求⑤）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunziEx函数: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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




//------------附加题：找出最长的顺子长度(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：找出随机数组nCardID[ ]中最长顺子的长度，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计GetMaxShunziCount函数: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//本题是附加题
	//务必先保证前2题的调试结果正确，有时间再做附加题，没时间可以不做
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

#define MinABT 5	//最短顺子长度
#define MaxABT 13	//最长顺子长度

//  一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//	方块2, 方块3…方块K, 方块A   (0- 12)
//	梅花2, 梅花3…梅花K, 梅花A   (13-25)
//	红桃2, 红桃3…红桃K, 红桃A   (26-38)
//	黑桃2, 黑桃3…黑桃K, 黑桃A   (39-51)
//  小王                           (52)
//  大王                           (53)  
//  注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2,3,4,5,6,7,8,9,10,J,Q,K,A共13种


//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A,2,3,4,5不能组成顺子(A只能当最大的，不能当最小的)
//顺子不能出现2张相同的牌 比如2,3,3,4,5,6就不为顺子


//在开始做题前请仔细阅读以上的说明，然后再查看以下的3个题目。
//第一、二题为必做提，第三题为附加题



//------------第一题：判断是否是顺子(无万能牌)---------------
//（要求①）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求②）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求③）：是顺子返回true，不是顺子返回false。
//（要求④）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunzi函数: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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




//------------第二题：判断是否是顺子(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求④）：是顺子返回true，不是顺子返回false。
//（要求⑤）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunziEx函数: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
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




//------------附加题：找出最长的顺子长度(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：找出随机数组nCardID[ ]中最长顺子的长度，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计GetMaxShunziCount函数: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//本题是附加题
	//务必先保证前2题的调试结果正确，有时间再做附加题，没时间可以不做
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

#define MinABT 5	//最短顺子长度
#define MaxABT 13	//最长顺子长度

//  一副扑克由方块，梅花，红桃，黑桃四种花色各13张加上小王，大王各一张组成，共54张牌。先定义ID如下：
//	方块2, 方块3…方块K, 方块A   (0- 12)
//	梅花2, 梅花3…梅花K, 梅花A   (13-25)
//	红桃2, 红桃3…红桃K, 红桃A   (26-38)
//	黑桃2, 黑桃3…黑桃K, 黑桃A   (39-51)
//  小王                           (52)
//  大王                           (53)  
//  注：方块K，方块是花色，K是牌点。除去大小王外，牌点有2,3,4,5,6,7,8,9,10,J,Q,K,A共13种


//如果n张牌的牌点相连，则称这n张牌构成"顺子"。如："方块2，黑桃3，红桃4，黑桃5，方块6，梅花7".
//特殊情况如:A,2,3,4,5不能组成顺子(A只能当最大的，不能当最小的)
//顺子不能出现2张相同的牌 比如2,3,3,4,5,6就不为顺子


//在开始做题前请仔细阅读以上的说明，然后再查看以下的3个题目。
//第一、二题为必做提，第三题为附加题



//------------第一题：判断是否是顺子(无万能牌)---------------
//（要求①）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求②）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求③）：是顺子返回true，不是顺子返回false。
//（要求④）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunzi函数: 
bool IsShunzi(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
	bool bRet = true;

	for (int i = 0; i < nCardCount - 1; ++i)
	{
		if ((nCardID[i] == 12 || nCardID[i] == 25 || nCardID[i] == 38 || nCardID[i] == 51) && i < nCardCount - 1)
		{
			// 非最后一个是A
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




//------------第二题：判断是否是顺子(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：判断随机数组nCardID[]是否是顺子，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：nCardID[]里的nCardCount张牌必须全部用上，一张用不上都不是顺子。
//（要求④）：是顺子返回true，不是顺子返回false。
//（要求⑤）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计IsShunziEx函数: 
bool IsShunziEx(int nCardID[], int nCardCount)
{
	//本题是必做题
	//注意附加题可以不做，但是务必要保证前2题必做题调试结果正确，否则不给分
	bool bRet = true;

	for (int i = 0; i < nCardCount - 1; ++i)
	{
		if ((nCardID[i] == 12 || nCardID[i] == 25 || nCardID[i] == 38 || nCardID[i] == 51) && i < nCardCount - 1)
		{
			// 非最后一个是A
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




//------------附加题：找出最长的顺子长度(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：找出随机数组nCardID[ ]中最长顺子的长度，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计GetMaxShunziCount函数: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//本题是附加题
	//务必先保证前2题的调试结果正确，有时间再做附加题，没时间可以不做

	return 0;
}

int main(int argc, char* argv[])
{
	//int nCardID[7]={0,1,3,4,53,6,8}; //这里ID仅为示例，非只调通此示例。
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

