#pragma once

#include <iostream>
#include <string>

using namespace std;

class AbstractInterface
{
public:
	AbstractInterface(){}
	~AbstractInterface(){}

	virtual void Request(int nRequestID) = 0;
};

class RealServer:public AbstractInterface
{
public:
	RealServer(){};
	~RealServer(){};

	virtual void Request(int nRequestID);
};

void RealServer::Request(int nRequestID)
{
	cout << "RealServer ToDo Request " << to_string(nRequestID) << endl;
}

class ProxyServer: public AbstractInterface
{
public:
	ProxyServer();
	~ProxyServer();

	virtual void Request(int nRequestID);

private:
	RealServer* m_pRealServer;
};

ProxyServer::ProxyServer()
{
	m_pRealServer = new RealServer();
	string strNumber("123456");
	int nNumber = atoi(strNumber.c_str());
	cout << "ProxyServer nNumber Is" << nNumber << endl;
}

ProxyServer::~ProxyServer()
{
	delete m_pRealServer;
}

void ProxyServer::Request(int nRequestID)
{
	if (m_pRealServer)
	{
		m_pRealServer->Request(nRequestID);
	}
}


