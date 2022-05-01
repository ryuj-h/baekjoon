#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <cstring>

using namespace std;

#define SNAKE 1
#define APPLE 2

typedef struct {
	int time;
	char d;
}DirInfo;

typedef struct {
	int x;
	int y;
}point;

int N, K;
int board[101][101];

int L;
queue<DirInfo> q;
int RESULT;

int dirx[] = { 1,0,-1,0 };
int diry[] = { 0,1,0,-1 };

deque<point> Snake;
int currdirection;

void ChangeDir(char c)
{
	if (c == 'L')
	{
		currdirection = currdirection - 1;
		if (currdirection < 0)
			currdirection = 3;
	}
	else if (c == 'D')
	{
		currdirection = currdirection + 1;
		if (currdirection > 3)
			currdirection = 0;
	}
}
bool canmove()
{
	auto headpos = Snake.front();

	int nextx = headpos.x + dirx[currdirection];
	int nexty = headpos.y + diry[currdirection];
	if (nextx == 0 || nextx == N + 1 || nexty == 0 || nexty == N + 1)
		return false;

	if (board[nexty][nextx] == SNAKE)
		return false;

	Snake.push_front({ nextx,nexty });
	if (board[nexty][nextx] != APPLE)
	{
		board[Snake.back().y][Snake.back().x] = 0;
		Snake.pop_back();
	}
	board[nexty][nextx] = SNAKE;
	return true;
}

void solve()
{
	Snake.push_front({ 1,1 });
	board[1][1] = SNAKE;
	currdirection = 0;
	
	RESULT = 0;
	while (!q.empty())
	{
		auto info = q.front();
		q.pop();
		while (RESULT != info.time)
		{
			if (canmove() == false)
			{
				RESULT++;
				return;
			}
			RESULT++;
		}
		ChangeDir(info.d);
	}

	while (1) {
		if (canmove() == false) {
			RESULT++;
			return;
		}
		RESULT++;
	}
}

int main(int argc, char** argv)
{
	cin >> N >> K;
	memset(board, 0, sizeof(board));
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> y >> x;
		board[y][x] = APPLE;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int time;
		char direction;
		cin >> time >> direction;
		q.push({ time,direction });
	}

	solve();

	cout << RESULT << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}