// Simulation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include "math.h"


std::vector<std::vector <int>> zuhe(std::vector<int> in, int target)	//target 是希望选择M个作组合,in是选择的范围，长度为N
{
	std::vector<std::vector <int>> output;
	for (int i = 0; i < pow(2, in.size()); i++) {
		int temp = 0, count = 0;
		std::vector<int> weishu;
		for (int j = 0; j < in.size(); j++) {
			if ((i&(1 << j)) != 0) {
				weishu.push_back(j); count++;
			}//找出二进制为1的位数以及它们的位置
		}
		if (count == target) {//位数等于M
			std::vector<int> one_case;
			for (int j = 0; j < count; j++) {
				temp = in.size() - 1 - weishu[j];
				one_case.push_back(in[temp]);
			}
			output.push_back(one_case);
		}
	}
	return output;
}

int main()
{
	for (int k = 1; k < 30; k++)
	{	
		int size = k;
		if (size && size < 30)  //30保护
		{
			std::vector<int> in(size);
			for (int i = 0; i < size; i++)
			{
				in[i] = i;
			}
			int count = 5;
			if (size < 5)
			{
				count = size;
			}

			std::vector<std::vector <int>> vec_AllUniteIndex; //所有的组合

			for (int i = 1; i <= count; i++)
			{
				std::vector<std::vector <int>> output;
				output = zuhe(in, i);
				vec_AllUniteIndex.insert(vec_AllUniteIndex.end(), output.begin(), output.end());
			}

			for (auto item : vec_AllUniteIndex)
			{
				for (auto num : item)
				{
					if (num < 0 || num > size)
					{
						printf("Array Out Of Bounds Num = %d", num);
					}
				}
			}
		}
	}


    return 0;
}

