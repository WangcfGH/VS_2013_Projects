#ifndef _REFLECT_1_H_
#define _REFLECT_1_H_

#include <iostream>
#include <map>

using namespace std;

class Reflector;

// 支持反射的基类
class Base
{
public:
	Base(){ cout << "Base()" << endl; }
	virtual ~Base(){ cout << "~Base()" << endl; }
	virtual void print(){
		cout << "Base print()" << endl;
	}
};

// 工厂类 
// - 提供注册接口，注册子类的 Reflector 对象
// - 提供返回创建对象接口，根据子类类名返回实例
class Factory
{
private:
	Factory(){ cout << "Factory()" << endl; }

public:
	~Factory(){ cout << "~Factory()" << endl; }

public:
	static Factory& getInstance();

	// 将子类的 Reflector 指针注册到 map 中 
	void Register(Reflector* reflector);

	// 根据类名返回实例 
	Base* getObject(string className);

private:
	map<string, Reflector*> objectMap;
};

typedef Base* (*ObjectConstructor)();
// 实现反射的类 
// - 构造时将自身的(实际上就是子类的) className 和 Reflector写入 map 中
// - 回调函数实现返回子类的实例 
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