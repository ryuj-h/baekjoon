#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <queue>


#define EMPTY  -9

using namespace std;

typedef struct {
	int x;
	int y;
}point;

int dirx[] = { 0,0,-1,1 };
int diry[] = { -1,1 ,0,0};

int N , M;
int board[21][21];
int visit[21][21];

int POINT = 0;

queue<point> q;

void rotate()
{
	static int tmparr[21][21];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmparr[i][j] = board[N - 1 - j][i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = tmparr[i][j];
}


int BFS(int color, int *rainbow, int *gijoonx ,int *gijoony)
{
	int num = 0;
	int rainbownum = 0;

	int minimumx= 99999;
	int minimumy= 99999;

	while (!q.empty())
	{
		point st = q.front();
		if (board[st.y][st.x] == color)
		{
			if (st.y < minimumy)
			{
				minimumx = st.x;
				minimumy = st.y;
			}
			else if (st.y == minimumy)
			{
				if (st.x < minimumx)
				{
					minimumx = st.x;
					minimumy = st.y;
				}
			}
		}
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nextx = st.x + dirx[d];
			int nexty = st.y + diry[d];

			if (nextx < 0 || nextx == N || nexty < 0 || nexty == N)
				continue;
			if (visit[nexty][nextx] == 1)
				continue;
			if (board[nexty][nextx] == EMPTY)
				continue;
			if (board[nexty][nextx] == color || board[nexty][nextx] == 0)
			{
				visit[nexty][nextx] = 1;
				point nt = { nextx,nexty };
				q.push(nt);
			}
		}
	}

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (visit[y][x] == 1)
			{
				num++;
				if (board[y][x] == 0)
				{
					rainbownum++;
				}
			}

	*gijoonx = minimumx;
	*gijoony = minimumy;
	*rainbow = rainbownum;
	return num;
}

void clear(int x, int y)
{
	memset(visit, 0, sizeof(visit));
	visit[y][x] = 1;


	point st_{ x,y };
	q.push(st_);
	int color = board[y][x];
	board[y][x] = EMPTY;

	while (!q.empty())
	{
		point st = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nextx = st.x + dirx[d];
			int nexty = st.y + diry[d];

			if (nextx < 0 || nextx == N || nexty < 0 || nexty == N)
				continue;
			if (visit[nexty][nextx] == 1)
				continue;
			if (board[nexty][nextx] == EMPTY)
				continue;
			if (board[nexty][nextx] == color || board[nexty][nextx] == 0)
			{
				visit[nexty][nextx] = 1;

				board[nexty][nextx] = EMPTY;
				point nt = { nextx,nexty };
				q.push(nt);
			}
		}
	}
}

void gravity()
{
	for (int x = 0; x < N; x++)
	{
		for (int y = N - 1; y >= 0; y--)
		{
			if (board[y][x] == EMPTY)
			{
				int xx = x;
				int yy = y;
				while (yy > 0 && board[yy][xx] == EMPTY) yy--;

				if (board[yy][xx] == -1)
					continue;
				board[y][x] = board[yy][xx];
				board[yy][xx] = EMPTY;
			}
		}
	}
}


void solve()
{
	while(true)
	{
		int maxfind = -1;
		int maxfindrainbow = -1;
		int maxfindx = -1;
		int maxfindy = -1;

		int gijoonx;
		int gijoony;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (board[y][x] != -1 && board[y][x] != EMPTY && board[y][x] != 0)
				{
					point st{ x,y };

					int rainbow = -1;
					memset(visit, 0, sizeof(visit));
					visit[y][x] = 1;
					q.push(st);
					int groupnum = BFS(board[y][x], &rainbow, &gijoonx, &gijoony);
					if (groupnum > maxfind)
					{
						maxfind = groupnum;
						maxfindrainbow = rainbow;
						maxfindx = gijoonx;
						maxfindy = gijoony;
					}
					else if (groupnum == maxfind)
					{
						if (rainbow > maxfindrainbow)
						{
							maxfind = groupnum;
							maxfindrainbow = rainbow;
							maxfindx = gijoonx;
							maxfindy = gijoony;
						}
						else if (rainbow == maxfindrainbow)
						{
							if (gijoony > maxfindy)
							{
								maxfind = groupnum;
								maxfindrainbow = rainbow;
								maxfindx = gijoonx;
								maxfindy = gijoony;
							}
							else if (gijoony == maxfindy)
							{
								if (gijoonx > maxfindx)
								{
									maxfind = groupnum;
									maxfindrainbow = rainbow;
									maxfindx = gijoonx;
									maxfindy = gijoony;
								}
							}
						}
					}
				}
			}
		}

		if (maxfind >= 2)
		{
			POINT = POINT + maxfind * maxfind;
			clear(maxfindx, maxfindy);
			gravity();
			rotate();
			rotate();
			rotate();
			gravity();
		}
		else
			return;
	}

}

int main(int argc, char** argv)
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];

	solve();

	cout << POINT << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}