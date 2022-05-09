#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M;


int board[600][600];
bool visit2[600][600];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int maxsum = 0;

void dfs(int x, int y,int depth ,int sum)
{
	if (depth == 4)
	{
		maxsum = max(maxsum, sum);
		return;
	}

	for (int d = 0; d < 4; d++)
	{
		int nextx = x + dx[d];
		int nexty = y + dy[d];

		if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N)
			continue;
		if (visit2[nexty][nextx])
			continue;
		visit2[nexty][nextx] = true;
		dfs(nextx,nexty, depth + 1, sum + board[nexty][nextx]);
		visit2[nexty][nextx] = false;
	}
}

void checkthis(int x, int y)
{
	//ㅏ
	if (y - 2 >= 0 && x + 1 < M)
	{
		int sum = board[y][x] + board[y - 1][x] + board[y - 2][x] + board[y - 1][x + 1];

		maxsum = max(maxsum, sum);
	}
	//ㅓ
	if (y - 2 >= 0 && x - 1 >= 0)
	{
		int sum2 = board[y][x] + board[y - 1][x] + board[y - 2][x] + board[y - 1][x - 1];
		maxsum = max(maxsum, sum2);
	}
	//ㅗ

	if (x + 2 < M && y - 1 >= 0)
	{
		int sum3 = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y - 1][x + 1];
		maxsum = max(maxsum, sum3);
	}
	//ㅜ
	if (x + 2 < M && y + 1 < N)
	{
		int sum4 = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1];
		maxsum = max(maxsum, sum4);
	}
}


void solve()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			visit2[y][x] = true;
			dfs(x,y,1, board[y][x]);
			visit2[y][x] = false;
			checkthis(x, y);
		}
	}
}

int main()
{
		cin >> N >> M;
		for (int yy = 0; yy < N; yy++)
		{
			for (int xx = 0; xx < M; xx++)
			{
				cin >> board[yy][xx];
			}
		}
		solve();
		cout << maxsum << endl;
}