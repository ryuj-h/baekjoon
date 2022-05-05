#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;

bool visit[201][201];
int arr[201][201];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct
{
	int x;
	int y;
}info;

int getbiggest()
{
	int nb = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			nb = max(nb, arr[y][x]);
		}
	}
	return nb;
}

int getsmallest()
{
	int nb = 9999999999;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			nb = min(nb, arr[y][x]);
		}
	}
	return nb;
}

int bfs(int x,int y, int rainfall)
{
	if (visit[y][x])
		return 0;
	if (arr[y][x] <= rainfall)
		return 0;
	bool flag = false;
	queue <info> q;
	q.push({ x,y });

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nextx = curr.x + dx[d];
			int nexty = curr.y + dy[d];

			if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
				continue;
			if (arr[nexty][nextx] <= rainfall)
				continue;
			if (visit[nexty][nextx])
				continue;
			visit[nexty][nextx] = true;
			q.push({ nextx,nexty });
		}
	}
	return 1;
}

void solve()
{
	int nb = 0;
	for (int i = getbiggest(); i >= getsmallest() - 1; i--)
	{
		memset(visit, false, sizeof(visit));
		int part = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				part = part + bfs(x, y, i);
			}
		}
		nb = max(part, nb);
	}
	cout << nb << endl;
}

int main()
{
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> arr[y][x];
		}
	}
	solve();

	//cout << SOLVE << endl;
}