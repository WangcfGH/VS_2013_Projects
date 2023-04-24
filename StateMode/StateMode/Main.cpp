// StateMode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "StateMode.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Work *emergencyPro = new Work();

	emergencyPro->setHour(9);
	emergencyPro->writeProgram();
	emergencyPro->setHour(10);
	emergencyPro->writeProgram();
	emergencyPro->setHour(11);
	emergencyPro->writeProgram();
	emergencyPro->setHour(12);
	emergencyPro->writeProgram();
	emergencyPro->setHour(13);
	emergencyPro->writeProgram();
	emergencyPro->setHour(17);
	emergencyPro->writeProgram();
	emergencyPro->setHour(19);
	emergencyPro->writeProgram();
	emergencyPro->setHour(22);
	emergencyPro->writeProgram();

	delete emergencyPro;

	//Work *normalPro = new Work();
	//normalPro->setHour(9);
	//normalPro->writeProgram();
	//normalPro->setHour(11);
	//normalPro->writeProgram();
	//normalPro->setHour(12);
	//normalPro->writeProgram();
	//normalPro->setHour(13);
	//normalPro->writeProgram();
	//normalPro->setHour(14);
	//normalPro->writeProgram();
	//normalPro->setTaskFinished(true);
	//normalPro->setHour(15);
	//normalPro->writeProgram();
	//normalPro->setHour(17);
	//normalPro->writeProgram();
	//delete normalPro;

	getchar();
	getchar();
	return 0;
}