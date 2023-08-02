
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int board[20][20];
bool visit[20];

vector<int> team1;
vector<int> team2;

int minpower = 2147483646;

void dfs(int index, int depth)
{
	if (depth == N / 2)
	{
		team1.clear();
		team2.clear();
		for (int i = 0; i < N; i++)
		{
			if (visit[i] == true)
				team1.push_back(i);
			else
				team2.push_back(i);
		}
		int team1power = 0;
		for (auto& v1 : team1){
			for (auto& vv1 : team1)
			{
				if (v1 == vv1)
					continue;
				team1power += board[v1][vv1];
			}
		}
		int team2power = 0;
		for (auto& v1 : team2) {
			for (auto& vv1 : team2)
			{
				if (v1 == vv1)
					continue;
				team2power += board[v1][vv1];
			}
		}
		minpower = min(minpower ,abs(team1power - team2power));
		return;
	}

	if (index + 1 < N)
	{
		visit[index] = true;
		dfs(index + 1, depth + 1);
		visit[index] = false;
		dfs(index + 1, depth);
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	dfs(0, 0);
	cout << minpower;
}