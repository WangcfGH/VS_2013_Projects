// DesignPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SinglePattern/SinglePattern.h"
#include "FactoryPattern/FactoryPattern.h"
#include "ObserverPattern/ObserverPattern.h"
#include "StrategyPattern/StrategyPattern.h"
#include "ProtoTypePattern/ProtoTypePattern.h"
#include "AdapterPattern/AdapterPattern.h"
#include "ProxyPattern/ProxyPattern.h"

// 定义单例静态对象
CSinglePattern CSinglePattern::instance;

int main()
{
	CSinglePattern::GetInstance()->DoFunc();

	cout << endl << endl << endl;

	Equipment *pEquipment;
	FactoryPattern factoryPattern;
	pEquipment = factoryPattern.GetEquipment(MOBILE_PHONE);
	if (pEquipment)
	{
		pEquipment->SetPrice(5000);
		pEquipment->PrintPrice();
	}	
	cout << endl;
	pEquipment = factoryPattern.GetEquipment(COMPUTER);
	if (pEquipment)
	{
		pEquipment->SetPrice(20000);
		pEquipment->PrintPrice();
	}

	cout << endl << endl << endl;

	PrototypeFirst prototypeF;
	int nAdd = (int)&prototypeF;
	prototypeF.m_pAddress = new int(nAdd);
	prototypeF.Show();
	PrototypeFirst* prototypeFcopy = (PrototypeFirst*)prototypeF.ThisClone();
	prototypeFcopy->Show();

	cout << endl << endl << endl;

	Observer observer;
	BeObserve beObserver;
	beObserver.AddObserver(observer);
	beObserver.EventHappen();


	cout << endl << endl << endl;

	StrategyContent strategyContent;
	QuickStrategy qStrategy;
	OptimalStrategy oStrategy;
	strategyContent.SetStrategy(&qStrategy);
	strategyContent.DoOperate();
	strategyContent.SetStrategy(&oStrategy);
	strategyContent.DoOperate();
	
	cout << endl << endl << endl;

	Target* target = new Adapter();
	target->Request();
	delete target;


	cout << endl << endl << endl;

	ProxyServer proxyS;
	proxyS.Request(1001);

	getchar();
	getchar();

	return 0;
}