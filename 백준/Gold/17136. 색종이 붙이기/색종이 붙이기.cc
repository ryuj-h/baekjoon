#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int board[16][16];
int oneNUM = 0;

int papers[6] = { 0,5,5,5,5,5 };

bool canstick(int x, int y, int size)
{
	if (papers[size] == 0)
		return false;

	if (x + size > N || y + size > N)
		return false;
	
	for (int yy = y; yy < y + size; yy++){
		for (int xx = x; xx < x + size; xx++)
		{
			if (board[yy][xx] == 0)
				return false;
		}
	}
	return true;
}

void stickpaper(int x, int y, int size)
{
	papers[size]--;
	for (int yy = y; yy < y + size; yy++) {
		for (int xx = x; xx < x + size; xx++)
		{
			board[yy][xx] = 0;
		}
	}
	oneNUM = oneNUM - size * size;
}

void restorepaper(int x, int y, int size)
{
	papers[size]++;
	for (int yy = y; yy < y + size; yy++) {
		for (int xx = x; xx < x + size; xx++)
		{
			board[yy][xx] = 1;
		}
	}
	oneNUM = oneNUM + size * size;
}


bool flag = false;
int minused = 99999999;

void dfs(int x ,int y,int used)
{
	if (oneNUM == 0)
	{
		minused = min(minused, used);
		flag = true;
		return;
	}

	for (int yy = y; yy < N; yy++)
	{
		for (int xx = x; xx < N; xx++)
		{
			if (board[yy][xx] == 1)
			{
				for (int p = 5; p >= 1; p--)
				{
					if (canstick(xx, yy, p))
					{
						stickpaper(xx, yy, p);
						dfs(xx + p,yy,used + 1);
						restorepaper(xx, yy, p);
					}
				}
				return;// 색종이를 하나도 못 붙이고 넘어가면 안됨
			}
		}
		x = 0;
	}
}

int main()
{
	N = 10;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == 1)
			{
				oneNUM++;
			}
		}
	}
	dfs(0,0,0);

	if (flag)
		cout << minused << endl;
	else
		cout << -1 << endl;
}
