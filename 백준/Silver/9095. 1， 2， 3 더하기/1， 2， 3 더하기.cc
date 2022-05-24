#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int dp[301];

int main(int argc, char** argv)
{
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i < 20; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << dp[n - 1] << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}