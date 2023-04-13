#pragma once
#include <iostream>
#include <string>

using namespace std;

enum OBJECT_TYPE
{
	ELECTRONIC_EQUIPMENT = 0,
	MOBILE_PHONE,
	COMPUTER,
};

class Equipment
{
public:
	Equipment();
	~Equipment();

	virtual void SetPrice(int nPrice);
	virtual int GetPrice();
	virtual void PrintPrice();
private:
	int m_nPrice;
};

Equipment::Equipment()
{	
	m_nPrice = 0;		
	cout << "Equipment Create Price Is "<< to_string(GetPrice())  << endl;
}

Equipment::~Equipment()
{
	cout << "Equipment Delete" << endl;
}

void Equipment::SetPrice(int nPrice)
{
	m_nPrice = nPrice;
}

int Equipment::GetPrice()
{
	return m_nPrice;
}

void Equipment::PrintPrice()
{
	cout << "This Equipment Price Is" << to_string(GetPrice()) << endl;
}

class MobilePhone:public Equipment
{
public:
	MobilePhone();
	~MobilePhone();

	virtual void PrintPrice();
};

MobilePhone::MobilePhone()
{
	cout << "MobilePhone Create Price Is " << to_string(GetPrice()) << endl;
}

MobilePhone::~MobilePhone()
{
	cout << "MobilePhone Delete" << endl;
}

void MobilePhone::PrintPrice()
{
	cout << "This MobilePhone Price Is" << to_string(GetPrice()) << endl;
}

class Computer :public Equipment
{
public:
	Computer();
	~Computer();

	virtual void PrintPrice();
};

Computer::Computer()
{
	cout << "Computer Create Price Is " << to_string(GetPrice()) << endl;
}

Computer::~Computer()
{
	cout << "Computer Delete" << endl;
}

void Computer::PrintPrice()
{
	cout << "This Computer Price Is" << to_string(GetPrice()) << endl;
}

class FactoryPattern
{
public:
	FactoryPattern(){}
	~FactoryPattern(){}
	
	Equipment* GetEquipment(int nType);
};

Equipment* FactoryPattern::GetEquipment(int nType)
{
	Equipment* pEquipment = nullptr;
	if (nType == ELECTRONIC_EQUIPMENT)
	{
		pEquipment = new Equipment();
	} 
	else if (nType == MOBILE_PHONE)
	{
		pEquipment = new MobilePhone();
	}
	else if (nType == COMPUTER)
	{
		pEquipment = new Computer();
	}
	return pEquipment;
}