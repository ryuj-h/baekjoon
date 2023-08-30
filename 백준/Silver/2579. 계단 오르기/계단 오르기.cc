#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int stairs[301];
int dp[301];

int main(int argc, char** argv)
{
	int N;
	cin >> N;
		
	for (int i = 0; i < N; i++)
	{
		cin >> stairs[i];
	}

	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1]+ stairs[2]);

	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i-2] + stairs[i]);
	}
	cout << dp[N - 1];

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}