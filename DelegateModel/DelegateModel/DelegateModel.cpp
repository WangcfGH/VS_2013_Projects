// DelegateModel.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include <memory>
using namespace std;
// Э��
class BaseFunction
{
public:
	BaseFunction(){};
	~BaseFunction(){};

	virtual void WorkFunc() = 0;
};
// ������
class Worker : public BaseFunction
{
public:
	Worker(){};
	~Worker(){};

	void WorkFunc()
	{
		cout << "ľ�����ƹ���" << endl;
	}
};
// ί����
class Boss : public BaseFunction
{
public:
	Boss(){};
	~Boss(){};

	void WorkFunc()
	{
		cout << "�ϰ�ί��ľ�����ƹ���" << endl;
		auto pWorker = m_pWorker.lock();
		if (pWorker)
		{
			pWorker->WorkFunc();
		}
	}

	void ToDoProject()
	{
		cout << "�ϰ�а�����" << endl;
		WorkFunc();
	}

public:
	weak_ptr<Worker> m_pWorker;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Boss boss;
	shared_ptr<Worker> worker = make_shared<Worker>();
	boss.m_pWorker = weak_ptr<Worker>(worker);
	boss.ToDoProject();
	getchar();	
	return 0;
}

/*
//C++����ֵ
//1) ���ڻ������ͣ���ֵ�ǲ��ɱ��޸ĵ�(non - modifiable)��Ҳ���ɱ� const, volatile ������(cv - qualitification ignored)
//2) �����Զ��������(user - defined types)����ֵȴ����ͨ�����ĳ�Ա���������޸ġ�
#include "stdafx.h"
#include "iostream"
using namespace std;
class cs
{
public:
	cs(int i) : i_(i)  { cout << "cs(" << i << ") constructor!" << endl; }
	~cs() { cout << "cs destructor,i(" << i_ << ")" << endl; }

	cs& operator=(const cs& other)
	{
		i_ = other.i_;
		cout << "cs operator=()" << endl;
		return *this;
	}

	int get_i() const { return i_; }
	void change(int i)  { i_ = i; }

private:
	int i_;
};

cs get_cs()
{
	static int i = 0;
	return cs(i++);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// �Ϸ�
	(get_cs() = cs(2)).change(323);
	get_cs() = cs(2);// operator=()
	get_cs().change(32);

	getchar();
	return 0;
}
*/