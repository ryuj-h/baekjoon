#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool ssort(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.first < b.first)
		return true;
	else 
		return false;
}

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

		sort(vv, vv + N, ssort);

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
		cout << count << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}