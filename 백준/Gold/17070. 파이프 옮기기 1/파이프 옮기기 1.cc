#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int board[17][17];

int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };

int list[17][17];

int SOLUTION = 0;


void print()
{
	cout << endl;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << board[y][x] << "	";
		}
		cout << endl;
	}
	cout << endl;
}




void dfs(int x, int y, int direction)
{
	int save[17][17];
	memcpy(save, board, sizeof(board));

	if (x == N - 1 && y == N - 1)
	{
		SOLUTION++;
		//print();
		return;
	}


	int skip_this = 4;
	switch (direction)
	{
	case 0:// 가로와 대각선만
		skip_this = 1;
		break;
	case 1:// 세로와 대각선만
		skip_this = 0;
		break;
	case 2:// 전부
		break;
	default:
		break;
	}


	for (int d = 0; d < 3; d++)
	{
		int nextx = x + dx[d];
		int nexty = y + dy[d];

		if (d == skip_this)
			continue;
		if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
			continue;
		if (board[nexty][nextx] == 1)
			continue;

		bool block = false;
		for (int yy = y; yy <= nexty; yy++)
		{
			for (int xx = x; xx <= nextx; xx++)
			{
				if (board[yy][xx] == 1)
					block = true;
			}
		}
		if (block)
			continue;
		dfs(nextx, nexty,d);
	}
}

int main()
{
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
		}
	}
	dfs(1, 0,0);
	cout << SOLUTION << endl;
}
