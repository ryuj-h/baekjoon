#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int dp[1001][3];
int Color[3];

int main(int argc, char** argv)
{
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++){
			cin >> Color[j];
		}
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + Color[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + Color[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + Color[2];
	}
	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}