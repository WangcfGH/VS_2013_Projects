// Basic_Regex.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string target = "@abc def--";
	std::regex e("(\\w+)\\W+(\\w+)");
	std::smatch sm;
	std::regex_search(target, sm, e);

	std::cout << "sm.prefix: " << sm.prefix() << std::endl;
	for each (auto var in sm)
	{
		std::cout << var << std::endl;
	}

	std::cout << "sm.prefix: " << sm.suffix() << std::endl;


	getchar();
	getchar();

	return 0;
}

