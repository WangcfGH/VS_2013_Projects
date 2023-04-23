#ifndef _REFLECT_1_H_
#define _REFLECT_1_H_

#include <iostream>
#include <map>

using namespace std;

class Reflector;

// ֧�ַ���Ļ���
class Base
{
public:
	Base(){ cout << "Base()" << endl; }
	virtual ~Base(){ cout << "~Base()" << endl; }
	virtual void print(){
		cout << "Base print()" << endl;
	}
};

// ������ 
// - �ṩע��ӿڣ�ע������� Reflector ����
// - �ṩ���ش�������ӿڣ�����������������ʵ��
class Factory
{
private:
	Factory(){ cout << "Factory()" << endl; }

public:
	~Factory(){ cout << "~Factory()" << endl; }

public:
	static Factory& getInstance();

	// ������� Reflector ָ��ע�ᵽ map �� 
	void Register(Reflector* reflector);

	// ������������ʵ�� 
	Base* getObject(string className);

private:
	map<string, Reflector*> objectMap;
};

typedef Base* (*ObjectConstructor)();
// ʵ�ַ������ 
// - ����ʱ�������(ʵ���Ͼ��������) className �� Reflectorд�� map ��
// - �ص�����ʵ�ַ��������ʵ�� 
class Reflector
{
public:
	Reflector(string name, ObjectConstructor objc) : m_cname(name), m_objc(objc)
	{
		cout << "Reflector()" << endl;
		Factory::getInstance().Register(this);
	}
	virtual ~Reflector()
	{ 
		//cout << "~Reflector()" << endl; 
	}

	Base* getObjectInstance();

public:
	string m_cname;
	ObjectConstructor m_objc;
};

#endif