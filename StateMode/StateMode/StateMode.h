#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>
using namespace std;

class Work;

//定义一个抽象方法，写程序
class State{

public:
	virtual void writeProgram(Work *w){}
	virtual ~State(){}
};

//上午和中午工作状态
class ForenoonState : public State{

public:
	void writeProgram(Work *w);
	~ForenoonState();
};

//中午工作状态
class NoonState : public State{

public:
	void writeProgram(Work *w);
	~NoonState();
};

//下午工作
class AfternoonState : public State{

public:
	void writeProgram(Work *w);
	~AfternoonState();
};

//晚间工作状态
class EveningState : public State{

public:
	void writeProgram(Work *w);
	~EveningState();
};

//下班状态
class RestState : public State{

public:
	void writeProgram(Work *w);
	~RestState();
};

//休眠状态
class SleepingState : public State{

public:
	void writeProgram(Work *w);
	~SleepingState();
};

//工作类
class Work{

public:
	Work();
	~Work();

	void setHour(const double &h);
	double getHour();

	void setTaskFinished(const bool &f);
	bool getTaskFinished();

	void setState(State *s);
	void writeProgram();

private:
	State *current;
	double hour;
	bool finish;
};

#endif // !HEAD_H