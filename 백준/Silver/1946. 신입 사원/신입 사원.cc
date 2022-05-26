#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

pair<int, int> vv[100001];

int main(int argc, char** argv)
{
	cin.tie(0);
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++)
	{
		int N;
		cin >> N;
		for (int nn = 0; nn < N; nn++)
			cin >> vv[nn].first >> vv[nn].second;	

		sort(vv, vv + N);

		int count = 1;
		int startb = vv[0].second;
		for (int i = 1; i < N; i++)
		{
			if (vv[i].second < startb)
			{
				count++;
				startb = vv[i].second;
			}
		}
		cout << count <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}