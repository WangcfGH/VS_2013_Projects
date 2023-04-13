// TempProject_shared_static_pointer_cast.cpp : �������̨Ӧ�ó������ڵ㡣
//

//�������á��㡱ָ����������ϵ�������ת��ʱ������ʹ��dynamic_cast����Ȼ����Ҳ����ʹ��static_cast��ֻ��dynamic_cast�ڽ�������ת����ʱ�򣨼����ൽ�����ࣩ�������ͼ�鹦�ܣ���static_castû�С���˴��ڰ�ȫ���⡣
//
//������ʹ������ָ��ʱ�������Ҫ���������ϵ�������ת��ʱ������ʹ��boost::static_pointer_cast��boost::dynamic_pointer_cast����C++11��Ҳ֧������ָ���ת����ֻ�������ռ�ĳ�std���ɣ���
//-------------------- -
//���ߣ�huangjh2018
//��Դ��CSDN
//ԭ�ģ�https ://blog.csdn.net/huangjh2017/article/details/74276134 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�



#include "stdafx.h"
#include <memory>
#include <iostream>
#include <iostream>
using namespace std;

class CBase
{
public:
	CBase() { }
	virtual ~CBase() { }

	void myBase()
	{
		cout << "CBase::myBase" << endl;
	}
};

class CDerive : public CBase
{
public:
	CDerive() { }
	~CDerive() { }

	void myDerive()
	{
		cout << "CDerive::myDerive" << endl;
	}
};

//1. static_pointer_cast
int _tmain(int argc, _TCHAR* argv[])
{
	//���е�ת���������ൽ�����ת����
	shared_ptr<CDerive> spDeriveUp;
	shared_ptr<CBase> spBaseUp;
	spDeriveUp = make_shared<CDerive>();
	spBaseUp = static_pointer_cast<CBase>(spDeriveUp);
	spBaseUp->myBase();

	//���е�ת�������ൽ�������ת�������ǲ���ȫ��
	shared_ptr<CDerive> spDeriveDown;
	shared_ptr<CBase> spBaseDown;
	spBaseDown = make_shared<CBase>();
	spDeriveDown = static_pointer_cast<CDerive>(spBaseDown);
	spDeriveDown->myBase();		//���������myDerive

	return 0;
}

////2. dynamic_pointer_cast
//int _tmain(int argc, _TCHAR* argv[])
//{
//	//���е�ת���������ൽ�����ת����
//	shared_ptr<CDerive> spDeriveUp;
//	shared_ptr<CBase> spBaseUp;
//	spDeriveUp = make_shared<CDerive>();
//	spBaseUp = dynamic_pointer_cast<CBase>(spDeriveUp);
//	spBaseUp->myBase();
//
//	//���е�ת�������ൽ�������ת��)
//	shared_ptr<CDerive> spDeriveDown;
//	shared_ptr<CBase> spBaseDown;
//	spBaseDown = make_shared<CBase>();
//	spDeriveDown = dynamic_pointer_cast<CDerive>(spBaseDown);
//	if (spDeriveDown == NULL)	//���ڻ�������͵ļ�飬����Ƿ���NULL
//		cout << "spDeriveDown is null" << endl;
//
//	return 0;
//}
//
////3. const_pointer_cast
//int _tmain(int argc, _TCHAR* argv[])
//{
//	{
//		shared_ptr<int> spInt;
//		shared_ptr<const int> spConstInt;
//
//		spInt = make_shared<int>(100);
//		spConstInt = const_pointer_cast<const int>(spInt);
//		cout << "*spConstInt = " << *spConstInt << endl;
//	}
//
//	{
//		shared_ptr<int> spInt;
//		shared_ptr<const int> spConstInt;
//		//��ʵ�ϲ�����ͨ��spInt�޸�ֵ
//		spConstInt = make_shared<const int>(100);
//		spInt = const_pointer_cast<int>(spConstInt);
//		cout << "*spInt = " << *spInt << endl;
//	}
//
//	return 0;
//}