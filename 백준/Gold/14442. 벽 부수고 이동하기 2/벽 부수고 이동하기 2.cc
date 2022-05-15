#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, K;
int board[1000][1000];
bool visited[1000][1000][10];

//5:03

typedef struct
{
	int x;
	int y;
	int leftitem;
	int distto;
}state;


int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool flag = false;
int mindist = 0x7fffffff;

void bfs2()
{
	queue<state> q;

	q.push({ 0,0,K,1 });

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		if (curr.x == M - 1 && curr.y == N - 1)
		{
			flag = true;
			mindist = curr.distto;
			return;
		}
		for (int d = 0; d < 4; d++)
		{
			int nextx = curr.x + dx[d];
			int nexty = curr.y + dy[d];
			int nextitem = curr.leftitem;
			int nextdist = curr.distto + 1;

			if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N)
				continue;
			
			if (visited[nexty][nextx][nextitem] == true)
				continue;

			if (board[nexty][nextx] == 0)
			{
				visited[nexty][nextx][nextitem] = true;
				q.push({ nextx,nexty,nextitem,nextdist });
			}
			else
			{
				if (nextitem > 0)
				{
					visited[nexty][nextx][nextitem] = true;
					q.push({ nextx,nexty,nextitem - 1, nextdist });
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
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