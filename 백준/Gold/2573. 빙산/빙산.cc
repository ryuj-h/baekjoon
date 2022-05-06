#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
int N, M;

typedef struct
{
	int x;
	int y;
}point;

int dx[] = { 0,0, -1,1 };
int dy[] = { -1,1,0,0 };

int board[400][400];
bool visit[400][400];

void print()
{
	cout << endl;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool bfs(int x, int y)
{
	if (visit[y][x])
		return false;
	if (board[y][x] == 0)
		return false;

	queue<point> q;

	visit[y][x] = true;
	q.push({ x,y });
	while (!q.empty())
	{
		auto currnode = q.front();
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nextx = currnode.x + dx[d];
			int nexty = currnode.y + dy[d];
			if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N)
				continue;
			if (visit[nexty][nextx])
				continue;
			if (board[nexty][nextx] == 0)
				continue;
			visit[nexty][nextx] = true;
			q.push({ nextx,nexty });
		}
	}
	return true;
}

int getpartnum()
{
	memset(visit, false, sizeof(visit));
	int ret = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (bfs(x, y))
				ret++;
		}
	}
	return ret;
}

void malt()
{
	int nearzeroarr[400][400];
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (board[y][x] != 0)
			{
				int nearzero = 0;
				for (int d = 0; d < 4; d++)
				{
					int nextx = x + dx[d];
					int nexty = y + dy[d];
					if (board[nexty][nextx] == 0)
						nearzero++;
				}
				nearzeroarr[y][x] = nearzero;
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (board[y][x] != 0)
			{
				board[y][x] = board[y][x] - nearzeroarr[y][x];
				if (board[y][x] < 0)
					board[y][x] = 0;
			}
		}
	}
}

bool is_allmalt()
{
	bool ret = true;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (board[y][x] != 0)
			{
				ret = false;
			}
		}
	}
	return ret;
}


void solve()
{
	bool flag = false;
	int year = 0;
	while (true)
	{
		year++;
		malt();
		int part = getpartnum();
		if (part > 1)
		{
			flag = true;
			break;
		}

		if (is_allmalt())
			break;
	}
	if (flag)
		cout << year << endl;
	else
		cout << 0 << endl;
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
		}
	}
	solve();


	return 0;
}
