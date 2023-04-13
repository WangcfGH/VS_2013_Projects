#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Observer
{
public:
	Observer();
	~Observer();

	void OnNotify();
	void Func();
};

Observer::Observer()
{

}

Observer::~Observer()
{

}

void Observer::OnNotify()
{
	cout << "Observer OnNotify Some Thing Then Do Func" << endl;
	Func();
}

void Observer::Func()
{
	cout << "Observer Func" << endl;
}



class BeObserve
{
public:
	BeObserve();
	~BeObserve();
	
	void EventHappen();
	bool AddObserver(const Observer observer);
	void NotifyObserve();
private:
	vector<Observer> m_vecObserver;
};

BeObserve::BeObserve()
{
	m_vecObserver.clear();
}

BeObserve::~BeObserve()
{
	m_vecObserver.clear();
}

void BeObserve::EventHappen()
{
	cout << "Some Event Happen Then Notify All Observer" << endl;
	for each (auto var in m_vecObserver)
	{
		var.OnNotify();
	}
}

bool BeObserve::AddObserver(const Observer observer)
{
	m_vecObserver.push_back(observer);

	return true;
}

