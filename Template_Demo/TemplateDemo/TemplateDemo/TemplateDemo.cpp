#include "stdafx.h"
#include <iostream>
#include <type_traits>

template<class T1, class T2>
void print_is_same()
{
	std::cout << std::is_same<T1, T2>() << std::endl;
}

void print_separator()
{
	std::cout << "-----" << std::endl;
}


template<class T1, class T2>
T2 TestAddFunc(T1 t1, T2 t2)
{
	t1--;
	t2++;
	T2 t3 = t2 + t1;
	std::cout << "t1 Is " << t1 << std::endl; 
	std::cout << "t2 Is " << t2 << std::endl;
	std::cout << "t1 + t2 Is " << t3 << std::endl;
	return t3;
}

int main()
{
	std::cout << std::boolalpha;

	print_is_same<int, int>();   // true
	print_is_same<int, int*>();  // false
	print_is_same<int, int**>(); // false

	print_separator();

	print_is_same<int, std::remove_pointer<int>::type>();   // true
	print_is_same<int, std::remove_pointer<int*>::type>();  // true
	print_is_same<int, std::remove_pointer<int**>::type>(); // false

	print_separator();

	print_is_same<int, std::remove_pointer<int* const>::type>();          // true
	print_is_same<int, std::remove_pointer<int* volatile>::type>();       // true
	print_is_same<int, std::remove_pointer<int* const volatile>::type>(); // true

	float fResult = TestAddFunc(5, 2.0);

	getchar();
	getchar();
}

