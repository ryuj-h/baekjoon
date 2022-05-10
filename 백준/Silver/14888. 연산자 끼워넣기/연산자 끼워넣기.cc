#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;

int numbers[11];

//+0  -1  *2  /3
int yunsanja[4] = { 0, };

int calc(int num, int num2, int yunsanja)
{
	int res;
	switch (yunsanja)
	{
	case 0:res = num + num2; break;
	case 1:res = num - num2; break;
	case 2:res = num * num2; break;
	case 3:res = num / num2; break;
	default:
		break;
	}
	return res;
}

int mmin = 2000000001;
int mmax = -2000000001;

void df(int index, int result)
{
	if (index == N - 1)
	{
		mmin = min(result, mmin);
		mmax = max(result, mmax);
		return;
	}

	for (int d = 0; d < 4; d++)
	{
		if (yunsanja[d] == 0)
			continue;

		yunsanja[d]--;
		df(index + 1, calc(result, numbers[index + 1], d));
		yunsanja[d]++;
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	for (int i = 0; i < 4; i++)
		cin >> yunsanja[i];

	df(0, numbers[0]);

	cout << mmax << endl;
	cout << mmin << endl;
}