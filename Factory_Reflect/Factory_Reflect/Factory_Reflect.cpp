// Factory_Reflect.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Factory_Reflect.h"
#include <iostream>

using namespace std;

#define DELCLARE_CLASS(className) \
    public: \
        static Base* CreateObject() \
        {   \
            return new className;   \
        }   \
    protected:  \
        static Reflector m_reflector;   \

#define REGISTER_CLASS(className) \
    Reflector className::m_reflector(#className, className::CreateObject);

// 工厂类impl
Factory& Factory::getInstance()
{
	static Factory factory;
	return factory;
}

void Factory::Register(Reflector* reflector)
{
	if (reflector)
	{
		objectMap.insert(map<string, Reflector*>::value_type(reflector->m_cname, reflector));
	}
}

Base* Factory::getObject(string className)
{
	map<string, Reflector*>::const_iterator iter = objectMap.find(className);
	if (iter != objectMap.end())
	{
		return iter->second->getObjectInstance();
	}
}



// 反射类impl
Base* Reflector::getObjectInstance()
{
	return m_objc();
}



// 支持反射的子类
class Derive : public Base
{
	DELCLARE_CLASS(Derive);
	/*	
	public:
		static Base* CreateObject()
		{
			return new Derive;
		}
	protected:
		static Reflector m_reflector;
	*/
public:
	Derive(){ cout << "Derive()" << endl; }
	virtual ~Derive(){ cout << "~Derive()" << endl; }

	void print()
	{
		cout << "Derive print()" << endl;
	}

};
REGISTER_CLASS(Derive);	//Reflector Derive::m_reflector("Derive", Derive::CreateObject);

class Derive2 : public Base
{
	DELCLARE_CLASS(Derive2);

public:
	Derive2(){ cout << "Derive2()" << endl; }
	virtual ~Derive2(){ cout << "~Derive2()" << endl; }
	void print()
	{
		cout << "Derive2 print()" << endl;
	}
};
REGISTER_CLASS(Derive2);

int _tmain(int argc, _TCHAR* argv[])
{	
	Base* p = Factory::getInstance().getObject("Derive");
	if (p)
	{
		p->print();
	}
	delete p;

	Base* p2 = Factory::getInstance().getObject("Derive2");
	if (p2)
	{
		p2->print();
	}
	delete p2;
	getchar();
	getchar();
	return 0;
}
