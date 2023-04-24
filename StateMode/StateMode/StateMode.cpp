#include "stdafx.h"
#include "StateMode.h"

void ForenoonState::writeProgram(Work *w)
{
	if (w->getHour() < 12){

		cout << "��ǰʱ�䣺" << w->getHour() << "�� ���繤��������ٱ���" << endl;
	}
	else{

		w->setState(new NoonState());
		w->writeProgram();
	}
}

ForenoonState::~ForenoonState()
{
	cout << "ForenoonState::~ForenoonState() desconstruction !" << endl;
}

void NoonState::writeProgram(Work *w)
{
	if (w->getHour() < 13){

		cout << "��ǰʱ�䣺" << w->getHour() << "�� ���ˣ��緹�����������ݡ�" << endl;
	}
	else{

		w->setState(new AfternoonState());
		w->writeProgram();
	}
}

NoonState::~NoonState()
{
	cout << "NoonState::~NoonState() desconstruction !" << endl;
}

Work::Work()
{
	this->current = new ForenoonState();
	this->finish = false;
	this->hour = 6.0;
}

Work::~Work()
{
	cout << "Work::~Work() desconstruction !" << endl;
}

void Work::setHour(const double &h)
{
	this->hour = h;
}

double Work::getHour()
{
	return this->hour;
}

void Work::setTaskFinished(const bool &f)
{
	this->finish = f;
}

bool Work::getTaskFinished()
{
	return this->finish;
}

void Work::setState(State *s)
{
	if (this->current != nullptr){

		delete current;
		//current = nullptr;	//�����е� �ѿ��� ��ƨ
	}
	this->current = s;
}

void Work::writeProgram()
{
	this->current->writeProgram(this);
}

void AfternoonState::writeProgram(Work *w)
{
	if (w->getHour() < 17){

		cout << "��ǰʱ�䣺" << w->getHour() << "�� ����״̬��������Ŭ��������" << endl;
	}
	else{

		w->setState(new EveningState());
		w->writeProgram();
	}
}

AfternoonState::~AfternoonState()
{
	cout << "AfternoonState::~AfternoonState() desconstruction !" << endl;
}

void SleepingState::writeProgram(Work *w)
{
	cout << "��ǰʱ�䣺" << w->getHour() << "�� �����ˣ�˯����" << endl;
}

SleepingState::~SleepingState()
{
	cout << "SleepingState::~SleepingState() desconstruction !" << endl;
}

void RestState::writeProgram(Work *w)
{
	cout << "��ǰʱ�䣺" << w->getHour() << "�� �°�ؼң�o(��_��)o ����" << endl;
}

RestState::~RestState()
{
	cout << "RestState::~RestState() desconstruction !" << endl;
}

void EveningState::writeProgram(Work *w)
{
	if (w->getTaskFinished()){		//�°���Ϣ

		w->setState(new RestState());
		w->writeProgram();
	}
	else{

		if (w->getHour() < 21){

			cout << "��ǰʱ�䣺" << w->getHour() << "�� �Ӱ��У�ƣ��������" << endl;
		}
		else{

			w->setState(new SleepingState());
			w->writeProgram();
		}
	}
}

EveningState::~EveningState()
{
	cout << "EveningState::~EveningState() desconstruction !" << endl;
}