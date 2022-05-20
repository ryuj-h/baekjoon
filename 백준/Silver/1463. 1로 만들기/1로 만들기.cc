#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;



int main(int argc, char** argv)
{
	int N;
	cin >> N;

	vector<int> dp(N+1);

	dp[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[N];

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}