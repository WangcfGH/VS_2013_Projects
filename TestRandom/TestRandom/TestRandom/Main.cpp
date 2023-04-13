using namespace std;
#include <iostream>
#include <random>
#include <vector>
#include <atlstr.h>
#include <algorithm>

/*
#define		HIT_PROBABILITY		80
void main()
{
	int nHitCount		= 0;
	int nMissCount		= 0;
	int nRandom			= 0;

	for (int i = 0; i < 1000; i++)
	{
		std::random_device rd;
		nRandom = rd() % 100;
		if (nRandom >=0 && nRandom < HIT_PROBABILITY )
		{
			nHitCount++;
			printf("Random %d   Value Is %d\n", i, nRandom);
		} 
		else
		{
			nMissCount++;
			printf("Random %d   Value Is %d\n", i, nRandom);
		}
	}
	
	CString strUserName("玩家426508");
	int nUserName = atoi(strUserName);
	printf("Random 1000 Times Percent 80 HitCount  Is %d\n", nHitCount);
	printf("Random 1000 Times Percent 80 MissCount Is %d\n", nMissCount);


	std::vector<int> thirdTeam;
	std::vector<int> fouthTeam;

	thirdTeam.clear();
	fouthTeam.clear();

	std::sort(thirdTeam.begin(), thirdTeam.end());
	std::sort(fouthTeam.begin(), fouthTeam.end());

	getchar();
	getchar();
}
*/

void main()
{	
	/*
	int m_nFirstSelectChairNO		= -1;
	int m_nSecondSelectChairNO		= -1;
	int m_nSelectCardID				= -1;
	int nSelectCardIsAllInOne		= 0;
	int nSelectCardIsAllInFriend	= 0;
	std::vector<int> vecFirstChairNO;
	std::vector<int> vecSecondChairNO;
	std::vector<int> vecCardID;
	vecFirstChairNO.clear();
	vecSecondChairNO.clear();
	vecCardID.clear();

	std::random_device rd;										//将用于获取随机数引擎的种子
	std::mt19937 gen(rd());										//以rd()为种子的标准mersenne_twister_engine 
	std::uniform_int_distribution <> distrib1(1, 4);
	std::uniform_int_distribution <> distrib2(1, 108);

	for (int i = 0; i < 4; i++)
		vecFirstChairNO.push_back(0);

	for (int i = 0; i < 4; i++)
		vecSecondChairNO.push_back(0);

	for (int i = 0; i < 108; i++)
		vecCardID.push_back(0);

	for (int i = 0; i < 100; i++)
	{
		m_nFirstSelectChairNO = distrib1(gen) - 1;					//使用`distrib`将gen生成的随机无符号int转化为[0, 3]中的int 
		m_nSecondSelectChairNO = distrib1(gen) - 1;					//使用`distrib`将gen生成的随机无符号int转化为[0, 3]中的int 
		m_nSelectCardID = distrib2(gen) - 1;						//使用`distrib`将gen生成的随机无符号int转化为[0, 107]中的int 		
		vecFirstChairNO[m_nFirstSelectChairNO]++;
		vecSecondChairNO[m_nSecondSelectChairNO]++;
		vecCardID[m_nSelectCardID]++;
		if (m_nFirstSelectChairNO == m_nSecondSelectChairNO)
		{
			nSelectCardIsAllInOne++;
		}

		if (m_nFirstSelectChairNO - m_nSecondSelectChairNO == 2 || m_nFirstSelectChairNO - m_nSecondSelectChairNO == -2)
		{
			nSelectCardIsAllInFriend++;
		}
	}

	for (int i = 0; i < 4; i++)
		std::cout << " " << i << ":" << vecFirstChairNO[i];
	std::cout << endl;

	for (int i = 0; i < 4; i++)
		std::cout << " " << i << ":" << vecSecondChairNO[i];
	std::cout << endl;

	std::cout << "All In One " << nSelectCardIsAllInOne << endl;
	
	std::cout << "All In Friend " << nSelectCardIsAllInFriend << endl;

	for (int i = 0; i < 108; i++)
		std::cout << " " << i << ":" << vecCardID[i];
	std::cout << endl;
	
	*/


	std::random_device rd;										//将用于获取随机数引擎的种子
	std::mt19937 gen(rd());										//以rd()为种子的标准mersenne_twister_engine 
	std::uniform_int_distribution <> distrib2(1, 100);

	int nCount = 0;
	int nTemp = 0;
	for (int i = 0; i < 10000; i++)
	{
		nTemp = distrib2(gen) - 1;
		if (nTemp < 50)
		{
			cout << nTemp << endl;
			nCount++;
		}
	}

	getchar();
	getchar();
}