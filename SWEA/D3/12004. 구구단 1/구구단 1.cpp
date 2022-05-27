#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		
		bool found = false;
		for (int i = 1; i < 10; i++)
		{
			if (N / i >= 1 && N / i  <= 9 && N % i == 0)
			{
				found = true; break;
			}
		}
		if (found)
		{
			cout << "#" << test_case << " Yes\n";
		}
		else
		{
			cout << "#" << test_case << " No\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}