#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct
{
	int x;
	int y;
	int type;
	int direction;//0 상 1 우 2 하 3 좌
}CCTV;

int N, M;
int board[8][8];
vector<CCTV> cctvs;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void make(CCTV& cctv)
{
	vector<int> dirs;
	switch (cctv.type)
	{
	case 1:
		dirs.push_back(cctv.direction);
		break;
	case 2:
		dirs.push_back(cctv.direction);//보는방향, 반대방향
		dirs.push_back((cctv.direction + 2+4) % 4);
		break;
	case 3:
		dirs.push_back(cctv.direction);//보는장향, 오른쪽으로 90도 꺾은 방향
		dirs.push_back((cctv.direction + 1+4) % 4);
		break;
	case 4:
		dirs.push_back(cctv.direction);//보는방향, 좌, 우로 90도 꺾은 방향
		dirs.push_back((cctv.direction + 1 + 4) % 4);
		dirs.push_back((cctv.direction - 1 + 4) % 4);
		break;
	case 5:
		dirs.push_back(0);//그냥 다
		dirs.push_back(1);
		dirs.push_back(2);
		dirs.push_back(3);
		break;
	default:
		break;
	}
	for (auto& dir : dirs)
	{
		int nextx = cctv.x + dx[dir];
		int nexty = cctv.y + dy[dir];
		while (true)
		{
			if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N || board[nexty][nextx] == 6)
				break;

			if (board[nexty][nextx] == 0)
			{
				board[nexty][nextx] = 8;
			}
			nextx = nextx + dx[dir];
			nexty = nexty + dy[dir];
		}
	}
}

int minsafezone = 64;
int boardsave[8][8];

void dfs(int index)
{
	if (index == cctvs.size())
	{
		//여기서 빈칸 확인하고 빈칸 최소 되는거 구하기
		memcpy(boardsave, board, sizeof(board));
		for (auto& cctv : cctvs)
		{
			make(cctv);
		}
		int safezone = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (board[y][x] == 0)
					safezone++;
			}
		}

		minsafezone = min(minsafezone, safezone);
		memcpy(board,boardsave, sizeof(board));
		return;
	}

	//방향 전부 돌리면서 dfs 호출
	cctvs[index].direction = 0;
	dfs(index + 1);

	cctvs[index].direction = 1;
	dfs(index + 1);

	cctvs[index].direction = 2;
	dfs(index + 1);

	cctvs[index].direction = 3;
	dfs(index + 1);
}

int main()
{
	cin >> N >> M;

	int cctvnum = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
			if (board[y][x] != 0 && board[y][x] != 6)
				cctvs.push_back({ x,y,board[y][x] ,0});
		}
	}
	dfs(0);
	cout << minsafezone << endl;
}