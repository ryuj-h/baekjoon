#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct {
	int x;
	int y;
}point;

int board[101][101];
int visit[101][101];
int dist[101][101];

int Y, X;

int dirx[] = { 0,0,-1,1 };
int diry[] = { -1,1,0,0 };

queue<point> q;

void BFS()
{
	point st{ 0,0 };
	visit[0][0] = 1;
	dist[0][0] = 1;
	q.push(st);

	while (!q.empty())
	{
		point currpos = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			if (currpos.x + dirx[d] < 0 || currpos.x + dirx[d] >= X ||
				currpos.y + diry[d] < 0 || currpos.y + diry[d] >= Y)
				continue;

			if (visit[currpos.y + diry[d]][currpos.x + dirx[d]] == 0)
			{
				if (board[currpos.y + diry[d]][currpos.x + dirx[d]] == 1)
				{
					visit[currpos.y + diry[d]][currpos.x + dirx[d]] = 1;

					point nextpos{ currpos.x + dirx[d], currpos.y + diry[d] };
					dist[nextpos.y][nextpos.x] = dist[currpos.y][currpos.x] + 1;
					q.push(nextpos);
				}
			}
		}
	}

}

int main(int argc, char** argv)
{
	cin >> Y >> X;
	memset(board, 0, sizeof(board));
	memset(visit, 0, sizeof(visit));
	memset(dist, 0, sizeof(dist));

	for (int y = 0; y < Y; y++)
		for (int x = 0; x < X; x++)
			scanf("%1d", &board[y][x]);

	BFS();

	cout << dist[Y - 1][X - 1];

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}