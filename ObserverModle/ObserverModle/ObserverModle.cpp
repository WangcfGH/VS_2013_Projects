#include "stdafx.h"
#include "iostream"
#include "list"
#include "string"

using namespace std;

//读者（Observer：观察者）
class Reader
{
public:
	Reader(string strName){ m_strName = strName; };
	~Reader(){};

	string GetName()
	{
		return m_strName;
	}

	void ReceiveNews()
	{
		cout << m_strName << "接受报刊" << endl;
	}
private:
	string	m_strName;
};

//邮局（Subject：被观察者）
class PostOffice
{
public:
	PostOffice(){};
	~PostOffice(){};
	
	// 读者订阅
	void Attach(Reader* reader)
	{
		m_lsReader.push_back(reader);
		cout << "读者" << reader->GetName() << "向邮局订阅报刊" << endl;
	}

	// 读者取消订阅
	void Remove(Reader* reader)
	{
		m_lsReader.remove(reader);
		cout << "读者" << reader->GetName() << "向邮局取消订阅" << endl;
	}

	// 通知读者
	void Notify()
	{
		cout << "通知各位读者" << endl;
		for each (Reader* reader in m_lsReader)
		{
			reader->ReceiveNews();
		}
	}

	// 发布报纸
	void PublishNews()
	{
		cout << "邮局发布新报刊" << endl;
		Notify();
	}
private:
	list<Reader*>	m_lsReader;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Reader reader1("张三");
	Reader reader2("李四");
	PostOffice pOffice;

	pOffice.Attach(&reader1);
	pOffice.Attach(&reader2);

	pOffice.PublishNews();

	getchar();
	getchar();
	getchar();
	return 0;
}

