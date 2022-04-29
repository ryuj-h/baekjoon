#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct {
	int size;
	int x;
	int y;
	int exp;
}shark;

typedef struct {
	int x;
	int y;
}point;

typedef struct {
	int x;
	int y;
	int distance;
}result;

int dirx[] = { 0,-1,1,0};
int diry[] = { -1,0,0,1};

int N , M;
int board[21][21];
int copyboard[21][21];
int visit[21][21];
int visitnum[21][21];


int POINT = 0;
shark baby;

queue<point> q;

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

bool BFS(int x,int y , result *res,bool eat = false)
{
	memset(visit, 0, sizeof(visit));
	memset(visitnum, 0, sizeof(visitnum));
	memcpy(copyboard, board, sizeof(board));

	point start{ baby.x, baby.y };
	q.push(start);

	visitnum[baby.y][baby.x] = 0;
	visit[baby.y][baby.x] = 1;

	while (!q.empty())
	{
		point currpos = q.front();
		q.pop();

		if (currpos.x == x && currpos.y == y)
		{
			res->x = x;
			res->y = y;
			res->distance = visitnum[y][x];

			if (!eat)
			{
				memcpy(board, copyboard, sizeof(board));
			}
			if (eat)
			{
				board[baby.y][baby.x] = 0;
				board[y][x] = 9;
				baby.x = x;
				baby.y = y;
				baby.exp++;
				if (baby.exp == baby.size)
				{
					baby.size++;
					baby.exp = 0;
				}
			}

			while (!q.empty())
				q.pop();
			return true;
		}

		for (int d = 0; d < 4; d++)
		{
			int nextx = currpos.x + dirx[d];
			int nexty = currpos.y + diry[d];

			if (nextx < 0 || nextx == N || nexty < 0 || nexty == N)
				continue;
			if (visit[nexty][nextx] == 1)
				continue;
			if (board[nexty][nextx] > baby.size)
				continue;


			visit[nexty][nextx] = 1;
			visitnum[nexty][nextx] = visitnum[currpos.y][currpos.x] + 1;
			point next{ nextx,nexty };

			q.push(next);
		}
	}

	memcpy(board, copyboard, sizeof(board));
	return false;
}



void solve()
{
	while (true)
	{
		int eatablenum = 0;
		int selectedX = 99999999;
		int selectedY = 99999999;
		int selectedDist = 99999999;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (board[y][x] != 0 && board[y][x] < baby.size && board[y][x] !=9)
				{
					result res;
					bool can = BFS(x, y, &res);
					if (can)
					{
						eatablenum++;
						if (selectedDist > res.distance)
						{
							selectedX = res.x;
							selectedY = res.y;
							selectedDist = res.distance;
						}
						else if (selectedDist == res.distance)
						{
							if (selectedY > res.y)
							{
								selectedX = res.x;
								selectedY = res.y;
								selectedDist = res.distance;
							}
							else if (selectedY == res.y)
							{
								if (selectedX > res.x)
								{
									selectedX = res.x;
									selectedY = res.y;
									selectedDist = res.distance;
								}
							}
						}
					}
				}
			}
		}

		if (eatablenum == 0)
		{
			break;
		}
		else
		{
			result res;
			BFS(selectedX, selectedY, &res, true);
			POINT = POINT + selectedDist;
		}
	}
}

int main(int argc, char** argv)
{
	cin >> N;
	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++){
			cin >> board[y][x];
			if (board[y][x] == 9)
			{
				baby.size = 2;
				baby.x = x;
				baby.y = y;
			}
		}
	}
	solve();


	cout << POINT << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}