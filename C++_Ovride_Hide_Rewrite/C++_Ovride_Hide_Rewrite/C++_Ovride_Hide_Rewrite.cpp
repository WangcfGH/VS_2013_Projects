// C++_Ovride_Hide_Rewrite.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//���أ���ָͬһ�ɷ������ڱ������ļ������в�ͬ�����У����������ͣ�������˳��ͬ����ͬ�����������ݲ����б�ȷ�������ĸ����������ز����ĺ����������͡�
class A
{
public:
	int Add(int nF, int nS)
	{
		return nF + nS;
	}

	float Add(float fF, float fS)
	{
		return fF + fS;
	}

	double Add(double dF, double dS)
	{
		return dF + dS;
	}

	// Error:���ز���ע����ֵ�����������б���ͬ���ܱ�����
	//void Add(int nF, int nS)
	//{		
	//}

	virtual int Reduce(int nF, int nS)
	{
		return nF - nS;
	}

};

class B: public A
{
public:
	int Add(int nF, int nS, int nT)
	{
		return nF + nS + nT;
	}
	
	//��д(����)����ָ�������д������¶���ĺ�����
	//�亯�����������б�����ֵ���ͣ����ж�����ͬ�����б���д�ĺ���һ�¡�ֻ�к����岻ͬ���������ڣ���
	//����д�ĺ���������virtual���Ρ�
	virtual int Reduce(int nF, int nS)
	{
		return nF * 2 - nS;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	B cB;
	cB.Add(1, 2, 3);
	// Error:����ͬ���������������أ������������з���
	//cB.Add(1, 2);

	A* pA = &cB;
	pA->Add(1, 2);
	// Error:����ͬ���������������أ�ֻ�ܷ���ָ�����е�ͬ������
	//pA->Add(1, 2, 3);

	pA->Reduce(3, 1);
	pA->Reduce(8, 1);
	return 0;
}

