#pragma once

class CSinglePattern
{
public:
	static CSinglePattern* GetInstance()
	{
		return &instance;
	}

private:
	// ����������̬�����ⲿ���壬���Ӧһ��
	static CSinglePattern instance;
	// ���캯��˽�л�����ֹ���ⴴ�����󣬱�֤�����Ψһ
	CSinglePattern(){}
	CSinglePattern(const CSinglePattern& singlePattern){}
	CSinglePattern& operator=(const CSinglePattern& singlePatten){};

	~CSinglePattern(){}

public:
	void DoFunc();
};