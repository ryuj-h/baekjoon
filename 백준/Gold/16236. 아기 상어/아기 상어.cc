#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <queue>
using namespace std;

int dirx[] = { 0,0,-1,1};
int diry[] = { -1,1,0,0};

/* 판과 방문 관련 변수 */
int N , M;
int board[21][21];
int visit[21][21];
int visitnum[21][21];

/* 아기 상어 변수 */
int Babyx;
int Babyy;
int Babyexp;
int Babylevel;

/* 가장 적합한 위치 정보 */
int Magicx;
int Magicy;
int Magicdist;

/* 최종 시간 */
int TIME = 0;

queue<std::pair<int, int>> q;

void initBFS()
{
	Magicx = 20;
	Magicy = 20;
	Magicdist = 400;

	memset(visit, 0, sizeof(visit));
	memset(visitnum, 0, sizeof(visitnum));
}

void BFS(int startx, int starty)
{
	q.push(make_pair(startx, starty));
	visit[starty][startx] = 1;

	while (!q.empty())
	{
		auto a = q.front();
		int currx = a.first;
		int curry = a.second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nextx = currx + dirx[d];
			int nexty = curry + diry[d];

			if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
				continue;
			if (visit[nexty][nextx] == 1)
				continue;
			if (board[nexty][nextx] > Babylevel)//아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 
				continue;

			visit[nexty][nextx] = 1;
			visitnum[nexty][nextx] = visitnum[curry][currx] + 1;

			if (board[nexty][nextx] >= 1 && board[nexty][nextx] <= 6)//현재 좌표가 물고기라면
			{
				if (Babylevel > board[nexty][nextx])//아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
				{
					if (Magicdist > visitnum[nexty][nextx])//첫번째로 거리가 더 짧은 좌표면 변경
					{
						Magicx = nextx;
						Magicy = nexty;
						Magicdist = visitnum[nexty][nextx];
					}
					else if (Magicdist == visitnum[nexty][nextx])//거리가 같다면
					{
						if (Magicy > nexty)//행이 더 작은거로(위 쪽에 있는 것)
						{
							Magicx = nextx;
							Magicy = nexty;
							Magicdist = visitnum[nexty][nextx];
						}
						else if (Magicy == nexty)//행도 같다면
						{
							if (Magicx > nextx)//열이 작은걸로 (왼 쪽에있는것)
							{
								Magicx = nextx;
								Magicy = nexty;
								Magicdist = visitnum[nexty][nextx];
							}
						}
					}
				}
			}
			q.push(make_pair(nextx, nexty));
		}
	}
}

void solve()
{
	while (true)
	{
		initBFS();
		BFS(Babyx, Babyy);

		if (Magicx == 20 && Magicy == 20 && Magicdist == 400)//해를 찾지 못했음. 와일문 종료
			break;
		else
		{
			Babyx = Magicx;
			Babyy = Magicy;
			board[Babyy][Babyx] = 0;
			Babyexp++;

			if (Babyexp == Babylevel)
			{
				Babylevel++;
				Babyexp = 0;
			}
			TIME = TIME + Magicdist;
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
				board[y][x] = 0;
				Babylevel = 2;
				Babyexp = 0;
				Babyx = x;
				Babyy = y;
			}
		}
	}
	
	solve();
	cout << TIME << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}