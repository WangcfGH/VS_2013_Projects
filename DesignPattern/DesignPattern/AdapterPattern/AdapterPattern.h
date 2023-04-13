#pragma once
#include <iostream>
#include <string>

using namespace std;

class Target
{
public:
	Target(){}
	~Target(){}

	virtual void Request(){}
};

class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}

	bool OpeSomething();
};

bool Adaptee::OpeSomething()
{
	cout << "Adaptee OpeSomething" << endl;
	return true;
}

class Adapter:public Target, public Adaptee
{
public:
	Adapter();
	~Adapter();

	virtual void Request();
};

Adapter::Adapter()
{
}

Adapter::~Adapter()
{
}

void Adapter::Request()
{
	cout << "Adapter Request" << endl;
	cout << "Then ToDo Adaptee OpeSomething" << endl;
	OpeSomething();
}