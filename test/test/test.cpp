// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstring>
#include<cstdio>
#include<vector>

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
	if (nCardCount > MaxABT || nCardCount < MinABT)
	{
		return false;
	}
	//出去大小王13种牌，定义一个数组，把出现的牌往里面塞，如果有重复就返回false，记录最小下标，插完之后从最小下标开始往后遍历，全连续就是顺子
	int arrCarSet[13];
	memset(arrCarSet, 0, 13 * 4);
	int iCarType; //牌的数字
	int iMinCar = 13;	//最小牌
	for (int i = 0; i < nCardCount; i++)
	{
		//所有牌必须用上，无万能牌，所以出现大小王就false
		if (nCardID[i] > 51)
		{
			return false;
		}
		//取余获取牌的ID
		iCarType = (nCardID[i] + 1) % MaxABT;
		if (iCarType == 0)
		{
			iCarType = 13;
		}
		//判断是否重复
		if (arrCarSet[iCarType - 1] > 0)
		{
			return false;
		}
		//记录最小牌
		if (iCarType < iMinCar)
		{
			iMinCar = iCarType;
		}
		//标志位置位1
		arrCarSet[iCarType - 1] = 1;
	}
	for (int i = iMinCar - 1; i < nCardCount; i++)
	{
		if (arrCarSet[i] != 1)
		{
			return false;
		}
	}
	return true;

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

	if (nCardCount > MaxABT || nCardCount < MinABT)
	{
		return false;
	}
	//最大13张牌，定义一个数组，把出现的牌往里面塞，如果有重复就返回false，记录最小下标，插完之后从最小下标开始往后遍历，全连续就是顺子。有空的记录数量，再对比王牌数量
	int arrCarSet[13];
	memset(arrCarSet, 0, 13 * 4);
	int iCarType = 1; //牌的数字
	int iMinCar = 13;	//最小牌
	int iKingCount = 0; //王牌数量	
	for (int i = 0; i < nCardCount; i++)
	{
		if (nCardID[i] > 51)
		{
			iKingCount++;
			continue;
		}
		iCarType = (nCardID[i] + 1) % MaxABT;
		//判断是否重复
		if (arrCarSet[iCarType - 1] > 0)
		{
			return false;
		}
		//记录最小牌
		if (iCarType < iMinCar)
		{
			iMinCar = iCarType;
		}
		//标志位置位1
		arrCarSet[iCarType - 1] = 1;
	}
	int iNeedCount = 0; //需要王牌的数量
	for (int i = iMinCar - 1; i < nCardCount; i++)
	{
		if (arrCarSet[i] != 1)
		{
			iNeedCount++;
			continue;
		}
	}
	if (iNeedCount <= iKingCount)
	{
		return true;
	}
	return false;
}



/*
//------------附加题：找出最长的顺子长度(有万能牌)---------------
//（要求①）：假设大小王可以充当任意一张牌使用，即万能牌。
//（要求②）：找出随机数组nCardID[ ]中最长顺子的长度，nCardID数组中存储都是牌的ID，nCardCount是指nCardID数组中元素的个数，即牌的张数。
//（要求③）：尽可能高的效率以及尽可能好的算法。
// 根据以上要求请设计GetMaxShunziCount函数: 
int GetMaxShunziCount(int nCardID[], int nCardCount)
{
	//本题是附加题
	//务必先保证前2题的调试结果正确，有时间再做附加题，没时间可以不做

	//最大13张牌，定义一个数组，把出现的牌往里面塞，塞完遍历。记录每个不连续牌的位置。
	//从头开始遍历，碰到不连续的数量大于王牌数量就中断，记录下顺子长度。从下一个不连续牌位置重新开始遍历。
	if (nCardCount > 54 || nCardCount < MinABT)
	{
		return 0;
	}
	if (nCardCount > 51)
	{
		//52张牌必定是13张的顺子
		return 13;
	}
	int arrCarSet[13];
	memset(arrCarSet, 0, 13 * 4);
	int iKingCount = 0; //王牌数量
	int iCarType;
	int iMinCar;
	for (int i = 0; i < nCardCount; i++)
	{
		if (nCardID[i] > 51)
		{
			iKingCount++;
			continue;
		}
		iCarType = (nCardID[i] + 1) % MaxABT;
		//记录最小牌
		if (iCarType < iMinCar)
		{
			iMinCar = iCarType;
		}
		//标志位置位1
		arrCarSet[iCarType - 1] = 1;
	}
	vector<int> v0Pos; //记录空缺位置
	for (int i = 0; i < 13; i++)
	{
		if (arrCarSet[i] == 0)
		{
			v0Pos.push_back(i);
		}
	}
	//没有空缺位置或者空缺位置小于王牌数量返回13
	if (sizeof(v0Pos) <= 0 or sizeof(v0Pos) <= iKingCount)
	{
		return 13
	}
	int iNeedCount = 0;	//顺子需要王牌的数量
	int iLenth = 0;	//当前顺子长度
	int iMaxLenth = 0;	//最长顺子长度
	if (v0Pos[0] != 0)//如果牌空缺位置不从0开始就从0开始先遍历一波
	{
		for (int i = 0; i < 13; i++)
		{
			if (arrCarSet[i] == 0)
			{
				iNeedCount++;
				if (iNeedCount > iKingCount)
				{
					break;
				}
			}
			iLenth++;
		}
		if (iMaxLenth < iLenth)
		{
			iMaxLenth = iLenth;
		}
	}

	for (int i = 0; i < sizeof(v0Pos); i++)
	{
		for (int i = v0Pos[i]; i < 13; i++)
		{
			if (arrCarSet[i] == 0)
			{
				iNeedCount++;
				if (iNeedCount > iKingCount)
				{
					break;
				}
			}
			iLenth++;
		}
		if (iMaxLenth < iLenth)
		{
			iMaxLenth = iLenth;
		}
	}
	return iMaxLenth;
}
*/
int main(int argc, char* argv[])
{
	int nCardID[7] = { 0, 1, 2, 16, 4, 5, 6 };
	int nCardCount = 7;

	if (IsShunzi(nCardID, nCardCount))
		printf("Is Shunzi!\n");
	else
		printf("Is Not Shunzi!\n");
	
	if (IsShunziEx(nCardID, nCardCount))
		printf("Is ShunziEx!\n");
	else
		printf("Is Not ShunziEx\n");
	/*
	int nMaxShunziCount = GetMaxShunziCount(nCardID, nCardCount);
	printf("MaxShunziCount:%d\n", nMaxShunziCount);
	*/


	return 0;
}

