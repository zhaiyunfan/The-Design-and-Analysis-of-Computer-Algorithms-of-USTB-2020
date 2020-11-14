#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int getNextLeft(char inputString[100000], int Pleft)
{
	int length = strlen(inputString);
	for (int i = Pleft; i < length; i++)
	{
		if (inputString[i] == '(')
		{
			return i;
		}
	}
	return -1;
}

int getNextRight(char inputString[100000], int Pright)
{
	int length = strlen(inputString);
	for (int i = Pright; i < length; i++)
	{
		if (inputString[i] == ')')
		{
			return i;
		}
	}
	return -1;
}

char input[100000];

int LuckyScore()
{
	cin >> input;

	int sum = 0;
	int length = strlen(input);
	int Pleft = -1;
	int Pright = -1;
	int i = 0;

	Pleft = i = getNextLeft(input, i);
	Pright = getNextRight(input, i + 1);

	while (Pleft != -1 && Pright != -1)
	{
		sum++;
		Pleft = getNextLeft(input, Pleft + 1);
		Pright = getNextRight(input, max(Pright + 1, Pleft));
	}

	cout << sum;
	return 0;
}

