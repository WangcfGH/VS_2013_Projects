// unordered_map.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;


//class A {
//public:
//	A(int size) : size_(size) {
//		data_ = new int[size];
//		cout << "Create A 1 Argv" << endl;
//	}
//	A(){
//		cout << "Create A 2 Default" << endl;
//	}
//	A(const A& a) {
//		size_ = a.size_;
//		data_ = new int[size_];
//		cout << "Create A 3 copy" << endl;
//	}
//	A(A&& a) {
//		this->size_ = a.size_;
//		this->data_ = a.data_;
//		a.data_ = nullptr;
//		a.size_ = 0;
//		cout << "Create A 3 move" << endl;
//	}
//	~A() {
//		if (data_ != nullptr) {
//			delete[] data_;
//		}
//	}
//	int *data_;
//	int size_;
//};
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	A a(10);
//	A b = a;
//	A c = std::move(a); // �����ƶ����캯��
//
//	getchar();
//	getchar();
//	return 0;
//}



void PrintV(int &t) {
	cout << "lvalue" << endl;
}

void PrintV(int &&t) {
	cout << "rvalue" << endl;
}

template<typename T>
void Test(T &&t) {
	PrintV(t);
	PrintV(std::forward<T>(t));

	PrintV(std::move(t));
}

int main() {
	Test(1); // lvalue rvalue rvalue
	int a = 1;
	Test(a); // lvalue lvalue rvalue
	Test(std::forward<int>(a)); // lvalue rvalue rvalue
	Test(std::forward<int&>(a)); // lvalue lvalue rvalue
	Test(std::forward<int&&>(a)); // lvalue rvalue rvalue
	return 0;
}
