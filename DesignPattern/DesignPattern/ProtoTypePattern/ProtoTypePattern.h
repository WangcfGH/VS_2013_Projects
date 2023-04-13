#pragma once
#include <iostream>

using namespace std;

class AbstractProtoType
{
public:
	AbstractProtoType(){}
	~AbstractProtoType(){}

	virtual AbstractProtoType* ThisClone(){ return nullptr; }
};

class PrototypeFirst: public AbstractProtoType
{
public:
	PrototypeFirst(){}
	PrototypeFirst(const PrototypeFirst& prototypeF)
	{
		this->m_pAddress = new int(*prototypeF.m_pAddress);
	}

	~PrototypeFirst (){}

	virtual AbstractProtoType* ThisClone();
	void Show();
public:
	int* m_pAddress;
};

AbstractProtoType* PrototypeFirst::ThisClone()
{
	PrototypeFirst* newPrototypeF = new PrototypeFirst(*this);

	return newPrototypeF;
}

void PrototypeFirst::Show()
{
	cout << "this add is" << *m_pAddress << endl;
}