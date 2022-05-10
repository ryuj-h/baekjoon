#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int board[9][9];
bool visit[9][9];

int board_save[9][9];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct
{
	int x;
	int y;
}point;

//벽 3개를 dfs로 구현 
//BFS를 통하여 바이러스 전파
//남은 빈공간 확인

int bfs_check()
{
	memcpy(board_save, board, sizeof(board));
	queue<point> q;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (board[y][x] == 2)
			{
				q.push({ x,y });
			}
		}
	}

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nextx = curr.x + dx[d];
			int nexty = curr.y + dy[d];
			if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N || board[nexty][nextx] != 0)
				continue;

			board[nexty][nextx] = 2;
			q.push({ nextx,nexty });
		}
	}

	int ret = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (board[y][x] == 0)
			{
				ret++;
			}
		}
	}

	memcpy(board,board_save, sizeof(board));
	return ret;
}

int max_safe_zone = 0;
void dfs(int x, int y, int depth)
{
	if (depth == 3)
	{
		int safe_zone = bfs_check();
		max_safe_zone = max(safe_zone, max_safe_zone);
		return;
	}


	for (int yy = y; yy < N; yy++)
	{
		for (int xx = x; xx < M; xx++)
		{
			if (visit[yy][xx] || board[yy][xx] != 0)
				continue;
			visit[yy][xx] = true;
			board[yy][xx] = 1;
			dfs(xx + 1, yy, depth + 1);
			visit[yy][xx] = false;
			board[yy][xx] = 0;
		}
		x = 0;
	}

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
	dfs(0, 0, 0);
	cout << max_safe_zone << endl;
}