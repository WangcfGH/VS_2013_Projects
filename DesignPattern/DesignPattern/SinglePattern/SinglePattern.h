#pragma once

class CSinglePattern
{
public:
	static CSinglePattern* GetInstance()
	{
		return &instance;
	}

private:
	// 类里声明静态对象，外部定义，类对应一个
	static CSinglePattern instance;
	// 构造函数私有化，禁止类外创建对象，保证类对象唯一
	CSinglePattern(){}
	CSinglePattern(const CSinglePattern& singlePattern){}
	CSinglePattern& operator=(const CSinglePattern& singlePatten){};

	~CSinglePattern(){}

public:
	void DoFunc();
};