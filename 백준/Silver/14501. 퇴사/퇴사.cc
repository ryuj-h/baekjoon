#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;

typedef struct
{
	int day;
	int pay;
}Order;

Order orders[15];
bool visit[15] = { false, };

int maxbenefit = 0;


void dfs(int index ,int day,int pay)
{
	if (index == N)
	{
		maxbenefit = max(maxbenefit, pay);
		return;
	}

	//index번 째 일을 했을때, 안했을때 두가지로 나눠서
	if (day <= index && index + orders[index].day <= N)
	{
		dfs(index + 1, index + orders[index].day, pay + orders[index].pay);
	}
	dfs(index + 1, day, pay);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int d, pay;
		cin >> d >> pay;
		orders[i].day = d;
		orders[i].pay = pay;
	}
	dfs(0, 0, 0);
	cout << maxbenefit;
}