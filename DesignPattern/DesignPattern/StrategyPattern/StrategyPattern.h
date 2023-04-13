#pragma once
#include <iostream>
#include <string>

using namespace std;

class AbstractStrategy
{
public:
	AbstractStrategy(){}
	~AbstractStrategy(){}

	virtual bool AlgorithmRealize();	
};

bool AbstractStrategy::AlgorithmRealize()
{
	cout << "AbstractStrategy Realize" << endl;

	return true;
}

class QuickStrategy: public AbstractStrategy
{
public:
	QuickStrategy(){}
	~QuickStrategy(){}

	virtual bool AlgorithmRealize();
};

bool QuickStrategy::AlgorithmRealize()
{
	cout << "QuickStrategy Realize" << endl;
	return true;
}

class EfficientStrategy : public AbstractStrategy
{
public:
	EfficientStrategy(){}
	~EfficientStrategy(){}

	virtual bool AlgorithmRealize();
};

bool EfficientStrategy::AlgorithmRealize()
{
	cout << "EfficientStrategy Realize" << endl;
	return true;
}

class OptimalStrategy : public AbstractStrategy
{
public:
	OptimalStrategy(){}
	~OptimalStrategy(){}

	virtual bool AlgorithmRealize();
};

bool OptimalStrategy::AlgorithmRealize()
{
	cout << "OptimalStrategy Realize" << endl;
	return true;
}



class StrategyContent
{
public:
	StrategyContent();
	~StrategyContent();

	bool SetStrategy(AbstractStrategy* strategy);
	bool DoOperate();
public:
	AbstractStrategy* m_pStrategy;
};

StrategyContent::StrategyContent()
{
	m_pStrategy = nullptr;
}

StrategyContent::~StrategyContent()
{
	m_pStrategy = nullptr;
}

bool StrategyContent::SetStrategy(AbstractStrategy* strategy)
{
	m_pStrategy = strategy;

	return true;
}

bool StrategyContent::DoOperate()
{
	if (m_pStrategy)
	{
		return m_pStrategy->AlgorithmRealize();
	}

	return false;
}
