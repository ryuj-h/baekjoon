#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int C;


int main()
{
	cin >> C;
	for (int t = 0; t < C; t++)
	{
		int sum = 0;
		int N;
		vector<int> v;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;

			v.push_back(num);
			sum = sum + num;
		}

		float res = sum / (float)N;
		int nn = 0;
		for (auto& nb : v)
		{
			if (nb > res)
				nn++;
		}
		float sol = nn / (float)(v.size()) * 100;
		printf("%.3f\%\n", sol);
	}
}