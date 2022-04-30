#include <iostream>
#include <cstring>

using namespace std;

int N;
int SCORE;
int board[20][20];

int dirx[] = { 0,0,1,-1 };
int diry[] = { 1,-1,0,0 };

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

void res_turn(int x, int y, int direction)
{
	int nextx = x + dirx[direction];
	int nexty = y + diry[direction];
	while (true)
	{
		if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
			return;
		if (board[nexty][nextx] == 0)
		{
			nextx = nextx + dirx[direction];
			nexty = nexty + diry[direction];
		}
		else
			break;
	}
	bool recheck = false;
	if (board[y][x] == 0)
	{
		board[y][x] = board[nexty][nextx];
		board[nexty][nextx] = 0;
		recheck = true;
	}
	else if (board[y][x] == board[nexty][nextx])
	{
		board[y][x] = board[y][x] + board[nexty][nextx];
		board[nexty][nextx] = 0;
	}

	if (recheck)
	{
		nextx = x;
		nexty = y;
	}
	else
	{
		nextx = x + dirx[direction];
		nexty = y + diry[direction];
	}


	res_turn(nextx, nexty, direction);
}

void turn(int direction)//0 상 1 하 2 좌 3 우
{
	int x, y;
	int plusx, plusy;
	switch (direction)
	{
	case 0:
		x = 0;
		y = 0;
		plusx = 1;
		plusy = 0;
		break;
	case 1:
		x = 0;
		y = N - 1;
		plusx = 1;
		plusy = 0;
		break;
	case 2:
		x = 0;
		y = 0;
		plusx = 0;
		plusy = 1;
		break;
	case 3:
		x = N - 1;
		y = 0;
		plusx = 0;
		plusy = 1;
		break;
	default:
		break;
	}
	
	for (int i = 0; i < N; i++)
	{
		res_turn(x + i * plusx, y + i * plusy, direction);
	}
}

int GetBiggestNumber()
{
	int num = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] > num)
				num = board[y][x];
		}
	}
	return num;
}

void dfs(int movetime)
{
	int tmparr[20][20];

	int b = GetBiggestNumber();
	if (SCORE < b)
		SCORE = b;
	if (movetime == 5)	
		return;

	memcpy(tmparr, board, sizeof(board));

	for (int d = 0; d < 4; d++)
	{
		turn(d);
		dfs(movetime + 1);
		memcpy(board, tmparr, sizeof(board));
	}
}


void solve()
{
	dfs(0);
}

int main()
{
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];
		
	solve();

	cout << SCORE << endl;
}