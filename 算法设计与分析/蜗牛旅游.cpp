/*
��ţ���ƶ���������μƻ����� nn �������ѡ��
���Ѿ�����Щ���㰴��˳·������˳���ų�һ���ˣ�ÿ���ط�����Ӧ�ľ��ۣ�������һ��������ʾ��
��ţϣ��ѡȡ������һ�ξ��㣬��Ҫѡ������ÿһ������ľ��۶���ͬ��
���������ѡ�����ٸ�����������Ρ�
�����ʽ
��һ�У�һ�������� n��
�ڶ��У����� n �������� a_i���� i ��������ʾ�� i ������ľ��ۡ�
�����ʽ
���һ�У�����һ����������ʾ��ţ�����ѡ���ľ�������
*/


#include <iostream>
#include <map>
#include <vector>
#include <map>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include "��ţ����.h"

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
