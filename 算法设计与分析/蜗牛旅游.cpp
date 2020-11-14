/*
蜗牛在制定今天的旅游计划，有 nn 个景点可选，
它已经把这些景点按照顺路游览的顺序排成一排了，每个地方有相应的景观，这里用一个整数表示。
蜗牛希望选取连续的一段景点，还要选出来的每一个景点的景观都不同，
问它最多能选出多少个景点进行旅游。
输入格式
第一行，一个正整数 n。
第二行，包含 n 个正整数 a_i，第 i 个整数表示第 i 个景点的景观。
输出格式
输出一行，包含一个整数，表示蜗牛最多能选出的景点数。
*/


#include <iostream>
#include <map>
#include <vector>
#include <map>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include "蜗牛旅游.h"

using namespace std;

int nums[100000];

bool belong(int Pleft, int Pright, int target)
{
	for (int i = Pleft; i <= Pright; i++)
	{
		if (nums[i] == target)
		{
			return true;
		}
	}
	return false;
}

int snailTourism()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &nums[i]);
	}
	int Pleft = 0, Pright = 0, length = 1;
	while (Pright + 1 < n)
	{
		if (!belong(Pleft, Pright, nums[Pright + 1]))
		{
			++Pright;
			//length++;
			length = max(Pright - Pleft + 1, length);
		}
		else
		{
			++Pleft;
			//++Pright;
		}
	}
	cout << length;
	return 0;
}
