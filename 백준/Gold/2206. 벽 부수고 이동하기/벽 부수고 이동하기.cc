#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int board[1000][1000];
int boarddist[1000][1000];
bool visit[1000][1000][2];


typedef struct
{
	int x;
	int y;
	bool item;
}state;


int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool flag = false;
int mindist = 0x7fffffff;

void bfs2()
{
	queue<state> q;

	q.push({ 0,0,true });
	boarddist[0][0] = 1;
	visit[0][0][true] = true;

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		int currx = curr.x;
		int curry = curr.y;
		bool curritem = curr.item;

		if (currx == M - 1 && curry == N - 1)
		{
			flag = true;
			mindist = min(mindist, boarddist[curry][currx]);
		}
		for (int d = 0; d < 4; d++)
		{
			int nextx = currx + dx[d];
			int nexty = curry + dy[d];
			bool nextitem = curr.item;

			if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N )
				continue;

			if (visit[nexty][nextx][nextitem] == true)
				continue;
				
			if (board[nexty][nextx] == 1)
			{
				if (nextitem)
					nextitem = false;
				else
					continue;
			}
			visit[nexty][nextx][nextitem] = true;

			boarddist[nexty][nextx] = boarddist[curry][currx] + 1;
			q.push({ nextx, nexty, nextitem});
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			scanf("%1d", &board[y][x]); //한글자씩 입력받기
		}
	}
	bfs2();

	if (flag)
		cout << mindist;
	else
		cout << "-1";
}