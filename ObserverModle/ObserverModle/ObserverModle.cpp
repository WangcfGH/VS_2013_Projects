#include "stdafx.h"
#include "iostream"
#include "list"
#include "string"

using namespace std;

//���ߣ�Observer���۲��ߣ�
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
		cout << m_strName << "���ܱ���" << endl;
	}
private:
	string	m_strName;
};

//�ʾ֣�Subject�����۲��ߣ�
class PostOffice
{
public:
	PostOffice(){};
	~PostOffice(){};
	
	// ���߶���
	void Attach(Reader* reader)
	{
		m_lsReader.push_back(reader);
		cout << "����" << reader->GetName() << "���ʾֶ��ı���" << endl;
	}

	// ����ȡ������
	void Remove(Reader* reader)
	{
		m_lsReader.remove(reader);
		cout << "����" << reader->GetName() << "���ʾ�ȡ������" << endl;
	}

	// ֪ͨ����
	void Notify()
	{
		cout << "֪ͨ��λ����" << endl;
		for each (Reader* reader in m_lsReader)
		{
			reader->ReceiveNews();
		}
	}

	// ������ֽ
	void PublishNews()
	{
		cout << "�ʾַ����±���" << endl;
		Notify();
	}
private:
	list<Reader*>	m_lsReader;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Reader reader1("����");
	Reader reader2("����");
	PostOffice pOffice;

	pOffice.Attach(&reader1);
	pOffice.Attach(&reader2);

	pOffice.PublishNews();

	getchar();
	getchar();
	getchar();
	return 0;
}

