#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>
using namespace std;

class Work;

//����һ�����󷽷���д����
class State{

public:
	virtual void writeProgram(Work *w){}
	virtual ~State(){}
};

//��������繤��״̬
class ForenoonState : public State{

public:
	void writeProgram(Work *w);
	~ForenoonState();
};

//���繤��״̬
class NoonState : public State{

public:
	void writeProgram(Work *w);
	~NoonState();
};

//���繤��
class AfternoonState : public State{

public:
	void writeProgram(Work *w);
	~AfternoonState();
};

//��乤��״̬
class EveningState : public State{

public:
	void writeProgram(Work *w);
	~EveningState();
};

//�°�״̬
class RestState : public State{

public:
	void writeProgram(Work *w);
	~RestState();
};

//����״̬
class SleepingState : public State{

public:
	void writeProgram(Work *w);
	~SleepingState();
};

//������
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