// DelegateModel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <memory>
using namespace std;
// 协议
class BaseFunction
{
public:
	BaseFunction(){};
	~BaseFunction(){};

	virtual void WorkFunc() = 0;
};
// 代理类
class Worker : public BaseFunction
{
public:
	Worker(){};
	~Worker(){};

	void WorkFunc()
	{
		cout << "木工定制柜子" << endl;
	}
};
// 委托类
class Boss : public BaseFunction
{
public:
	Boss(){};
	~Boss(){};

	void WorkFunc()
	{
		cout << "老板委托木工定制柜子" << endl;
		auto pWorker = m_pWorker.lock();
		if (pWorker)
		{
			pWorker->WorkFunc();
		}
	}

	void ToDoProject()
	{
		cout << "老板承包工程" << endl;
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
//C++左右值
//1) 对于基础类型，右值是不可被修改的(non - modifiable)，也不可被 const, volatile 所修饰(cv - qualitification ignored)
//2) 对于自定义的类型(user - defined types)，右值却允许通过它的成员函数进行修改。
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
	// 合法
	(get_cs() = cs(2)).change(323);
	get_cs() = cs(2);// operator=()
	get_cs().change(32);

	getchar();
	return 0;
}
*/