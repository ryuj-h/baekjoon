#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int sol = 0;

int main(int argc, char** argv)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i]<arr[j] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = 1; i <= N; i++)
		sol = max(sol, dp[i]);
	cout << sol;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}