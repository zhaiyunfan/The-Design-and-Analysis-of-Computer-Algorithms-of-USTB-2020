#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include "������.h"

using namespace std;

/// <summary>
/// ������һ��ŷ��ɸ
/// </summary>
int  maxn = 1000000;
int prime[1000000];//prime[0]��¼��ǰΪֹ�ҵ��������ĸ�����1��n���ҵ�������
int visit[1000000];//0��ʾ������

int Prime()
{
	memset(visit, 0, sizeof(visit));
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= maxn; ++i)
	{
		if (!visit[i])
		{
			prime[++prime[0]] = i;	//��¼�����ĸ�����ͬʱ���ҵ�������
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; ++j)	//����ÿһ�����ҵ�������
		{
			visit[i * prime[j]] = 1;	//��������ı����Ǻ���
			if (i % prime[j] == 0)	//��Ϊÿ����ֻ��������С������ɸһ�Σ��ڴ�֮�����������ɸ���Ժ��ɸ
			{
				break;
			}
		}
	}
	return 0;
}

int findPrime(int target)
{
	//	һ���ϣ��
	//	vector<int> nums(prime + 1, prime + prime[0]);
	//	map<int, int> a;//�ṩһ��һ��hash
	//	vector<int> b(2, -1);//�������ؽ������ʼ��һ����СΪ2��ֵΪ-1������b
	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		if (a.count(target - nums[i]) > 0)
	//		{
	//			b[0] = a[target - nums[i]];
	//			b[1] = i;
	//			break;
	//		}
	//		a[nums[i]] = i;//����������map�У�������ȡ����±�
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
