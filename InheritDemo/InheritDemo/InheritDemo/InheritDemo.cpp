// InheritDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class A
{
public:
	void FuncA(){
		printf("FuncA\n");
	}
	virtual void FuncB(){
		printf("FuncB\n");
	}
};
class B : public A
{
public:
	B(int i = 0){
		printf("Constructor_%d\n", i);
	}
	B(const B &x){
		printf("Constructor_2\n");
	}
	B &operator=(const B &x){
		printf("Constructor_3\n");
		return *this;
	}
	void FuncA(){
		A::FuncA();
		printf("FuncAB\n");
	}
	virtual void FuncB(){
		printf("FuncBB\n");
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	B b1(1);
	B b2 = b1;
	A *pa1 = &b1;
	A *pa2 = new A;
	pa1->FuncA();
	pa1->FuncB();
	pa2->FuncA();
	pa2->FuncB();
	delete pa2;

	getchar();
	return 0;
}

