#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
char board[20][20];
bool visit[20][20][20][20];

typedef struct
{
	int x;
	int y;
}point;

point red;
point blue;

typedef struct
{
	int redx;
	int redy;
	int bluex;
	int bluey;
	int count;
}Qdata;

int dirx[] = { 0,0,-1,1 };
int diry[] = { -1,1,0,0 };
//0 상 1 하 2 좌 3 우

#define FAILED 92393488593
int RESULT = FAILED;

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


void bfs()
{
	bool found = false;
	queue<Qdata> q;
	q.push({ red.x ,red.y,blue.x ,blue.y ,0 });

	while (!q.empty())
	{
		auto data = q.front();
		q.pop();
		
		int now_Rx = data.redx;
		int now_Ry = data.redy;
		int now_Bx = data.bluex;
		int now_By = data.bluey;

		visit[now_Rx][now_Ry][now_Bx][now_By] = true;

		if (data.count > 10)
			break;
		if (board[data.redy][data.redx] == 'O')
		{
			found = true;
			RESULT = data.count;
			break;
		}

		for (int d = 0; d < 4; d++)
		{
			int next_Rx = data.redx;
			int next_Ry = data.redy;
			int next_Bx = data.bluex;
			int next_By = data.bluey;

			while (1) // R 이동
			{
				if (board[next_Ry + diry[d]][next_Rx + dirx[d]] == '.') // 길
				{
					next_Rx += dirx[d];
					next_Ry += diry[d];
				}
				else if (board[next_Ry + diry[d]][next_Rx + dirx[d]] == 'O') // 구멍
				{
					next_Rx += dirx[d];
					next_Ry += diry[d];
					break;
				}
				else break; // 벽
			}
			while (1) // B 이동
			{
				if (board[next_By + diry[d]][next_Bx + dirx[d]] == '.') // 길
				{
					next_Bx += dirx[d];
					next_By += diry[d];
				}
				else if (board[next_By + diry[d]][next_Bx + dirx[d]] == 'O') // 구멍
				{
					next_Bx += dirx[d];
					next_By += diry[d];
					break;
				}
				else break; // 벽
			}
			if (board[next_By][next_Bx] == 'O')
				continue;
			if (next_Rx == next_Bx && next_Ry == next_By)
			{
				switch (d)
				{
				case 0: now_Ry > now_By ? next_Ry++ : next_By++; break;
				case 1: now_Ry > now_By ? next_By-- : next_Ry--; break;
				case 2: now_Rx > now_Bx ? next_Rx++ : next_Bx++; break;
				case 3: now_Rx > now_Bx ? next_Bx-- : next_Rx--; break;
				}
			}
			if (!visit[next_Rx][next_Ry][next_Bx][next_By])
				q.push({ next_Rx ,next_Ry ,next_Bx ,next_By ,data.count + 1 });
		}
	}

	if (found)
		cout << RESULT << endl;
	else
		cout << -1;
}

int main()
{
	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == 'R')
			{
				red.x = x;
				red.y = y;
				board[y][x] = '.';
			}
			else if (board[y][x] == 'B')
			{
				blue.x = x;
				blue.y = y;
				board[y][x] = '.';
			}
		}
	}

	bfs();
}