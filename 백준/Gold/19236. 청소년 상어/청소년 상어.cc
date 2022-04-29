#include <iostream>
#include <cstring>

using namespace std;

#define SHARK -999

typedef struct
{
	int index;
	int direction;
}FISH;

int dirx[] = {0,0,-1,-1,-1,0,1,1,1};
int diry[] = {0,-1,-1,0,1,1,1,0,-1};

FISH board[4][4];

int maxeat = 0;

void res(int x,int y)
{
	int direction = board[y][x].direction;
	int targetx = x + dirx[direction];
	int targety = y + diry[direction];

	if (targetx < 0 || targetx >= 4 ||
		targety < 0 || targety >= 4 ||
		board[targety][targetx].index == SHARK)
	{
		board[y][x].direction = (board[y][x].direction + 1) / 9 + (board[y][x].direction + 1) % 9;

		res(x, y);
	}
	return;
}

void FishMove()
{
	for(int index =1;index < 17; index++)
	{
		bool find = false;
		int x, y;
		for (int yy = 0; yy < 4; yy++)
		{
			for (int xx = 0; xx < 4; xx++)
			{
				if (board[yy][xx].index == index)
				{
					x = xx;
					y = yy;
					find = true;
				}
			}
		}

		if (find)
		{
			res(x, y);
			//swap
			int direction = board[y][x].direction;
			int targetx = x + dirx[direction];
			int targety = y + diry[direction];

			board[y][x].direction = board[targety][targetx].direction;
			board[y][x].index = board[targety][targetx].index;
			board[targety][targetx].direction = direction;
			board[targety][targetx].index = index;
		}
	}
}

void SharkEatdfs(int x,int y,int dir, int eat)
{
	if (eat > maxeat)
		maxeat = eat;
	FISH tmp[4][4];
	memcpy(tmp, board, sizeof(tmp));

	board[y][x].index = SHARK;
	FishMove();
	board[y][x].index = 0;

	for (int i = 1; i < 4; i++)
	{
		int nextx = x + dirx[dir] * i;
		int nexty = y + diry[dir] * i;
	
		if (nextx < 0 || nextx >= 4 || nexty < 0 || nexty >= 4)
			continue;
		if (board[nexty][nextx].index == 0)
			continue;

		int nextget = board[nexty][nextx].index;
		int nextdir = board[nexty][nextx].direction;

		SharkEatdfs(nextx, nexty, nextdir,eat + nextget);
	}
	memcpy(board,tmp, sizeof(tmp));
}

int main()
{
	maxeat = 0;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			cin >> board[y][x].index >> board[y][x].direction;
		}
	}
	SharkEatdfs(0, 0, board[0][0].direction, board[0][0].index);

	cout << maxeat << endl;

}