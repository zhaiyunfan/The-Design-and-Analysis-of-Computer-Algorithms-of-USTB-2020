#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include "找质数.h"

using namespace std;

/// <summary>
/// 下面是一个欧拉筛
/// </summary>
int  maxn = 1000000;
int prime[1000000];//prime[0]记录当前为止找到的素数的个数，1～n存找到的素数
int visit[1000000];//0表示是素数

int Prime()
{
	memset(visit, 0, sizeof(visit));
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= maxn; ++i)
	{
		if (!visit[i])
		{
			prime[++prime[0]] = i;	//记录素数的个数，同时存找到的素数
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; ++j)	//遍历每一个已找到的素数
		{
			visit[i * prime[j]] = 1;	//这个素数的倍数是合数
			if (i % prime[j] == 0)	//因为每个数只被它的最小质因子筛一次，在此之后的质数不用筛，以后会筛
			{
				break;
			}
		}
	}
	return 0;
}

int findPrime(int target)
{
	//	一遍哈希表
	//	vector<int> nums(prime + 1, prime + prime[0]);
	//	map<int, int> a;//提供一对一的hash
	//	vector<int> b(2, -1);//用来承载结果，初始化一个大小为2，值为-1的容器b
	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		if (a.count(target - nums[i]) > 0)
	//		{
	//			b[0] = a[target - nums[i]];
	//			b[1] = i;
	//			break;
	//		}
	//		a[nums[i]] = i;//反过来放入map中，用来获取结果下标
	//	}
	//	cout << nums[b[0]] << " " << nums[b[1]];
	//	return 0;

	for (int i = 2; i < 1000000; ++i)
	{
		if (!visit[i] && !visit[target - i])
		{
			printf("%d %d\n", i, target - i);
			break;
		}
	}
	return 0;
}

int findPrime()
{
	Prime();
	int total = 0, temp = 0;
	cin >> total;
	for (int i = 0; i < total; ++i)
	{
		scanf("%d", &temp);
		findPrime(temp);
	}
	return 0;
}
