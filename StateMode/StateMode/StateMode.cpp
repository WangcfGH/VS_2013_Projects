#include "stdafx.h"
#include "StateMode.h"

void ForenoonState::writeProgram(Work *w)
{
	if (w->getHour() < 12){

		cout << "当前时间：" << w->getHour() << "点 上午工作，精神百倍！" << endl;
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

		cout << "当前时间：" << w->getHour() << "点 饿了，午饭；犯困，午休。" << endl;
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
		//current = nullptr;	//这里有点 脱裤子 放屁
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

		cout << "当前时间：" << w->getHour() << "点 下午状态不错，继续努力！！！" << endl;
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
	cout << "当前时间：" << w->getHour() << "点 不行了，睡着了" << endl;
}

SleepingState::~SleepingState()
{
	cout << "SleepingState::~SleepingState() desconstruction !" << endl;
}

void RestState::writeProgram(Work *w)
{
	cout << "当前时间：" << w->getHour() << "点 下班回家！o(∩_∩)o 哈哈" << endl;
}

RestState::~RestState()
{
	cout << "RestState::~RestState() desconstruction !" << endl;
}

void EveningState::writeProgram(Work *w)
{
	if (w->getTaskFinished()){		//下班休息

		w->setState(new RestState());
		w->writeProgram();
	}
	else{

		if (w->getHour() < 21){

			cout << "当前时间：" << w->getHour() << "点 加班中，疲惫至极。" << endl;
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