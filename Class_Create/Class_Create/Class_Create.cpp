// Class_Create.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
using namespace std;
class Complex{
public:
	double real, imag;
	Complex(double r, double i){
		real = r; imag = i;
	}
	Complex(const Complex & c){
		real = c.real; imag = c.imag;
		cout << "Copy Constructor called const" << endl;
	}

	Complex(Complex &c){
		real = c.real; imag = c.imag;
		cout << "Copy Constructor called no const" << endl;
	}

	void ChangeDate()
	{
		real = real + 1;
		imag = imag + 1;
	}
};

void Function(const Complex & c)
{
	c.ChangeDate();
}

int main(){
	Complex cl(1, 2);
	const Complex c1ex = cl;
	Complex c2(c1ex);  //调用复制构造函数
	cout << c2.real << "," << c2.imag;

	getchar();
	getchar();
	return 0;
}