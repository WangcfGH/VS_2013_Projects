// C++_Ovride_Hide_Rewrite.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//重载：是指同一可访问区内被声明的几个具有不同参数列（参数的类型，个数，顺序不同）的同名函数，根据参数列表确定调用哪个函数，重载不关心函数返回类型。
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

	// Error:重载不关注返回值，函数名和列表相同则不能被重载
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
	
	//重写(覆盖)：是指派生类中存在重新定义的函数。
	//其函数名，参数列表，返回值类型，所有都必须同基类中被重写的函数一致。只有函数体不同（花括号内），
	//被重写的函数必须有virtual修饰。
	virtual int Reduce(int nF, int nS)
	{
		return nF * 2 - nS;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	B cB;
	cB.Add(1, 2, 3);
	// Error:父类同名函数被子类隐藏，不能在子类中访问
	//cB.Add(1, 2);

	A* pA = &cB;
	pA->Add(1, 2);
	// Error:父类同名函数被子类隐藏，只能访问指定类中的同名函数
	//pA->Add(1, 2, 3);

	pA->Reduce(3, 1);
	pA->Reduce(8, 1);
	return 0;
}

