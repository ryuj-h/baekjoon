#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M, K;
int board[51][51];

typedef struct {
	int x;
	int y;
	int num;
}Order;

Order orders[6];
bool visit[6] = { false ,};

void rotate(int x, int y,int num)
{
	int step = 1;
	while (true)
	{
		if (step > num)
			break;

		int lefttopx = x - step;
		int lefttopy = y - step;
		int righttopx = x + step;
		int righttopy = y - step;
		int leftbottomx = x - step;
		int leftbottomy = y + step;
		int rightbottomx = x + step;
		int rightbottomy = y + step;

		deque<int> tolinar;

		for (int xx = lefttopx; xx < righttopx; xx++)
			tolinar.push_back(board[lefttopy][xx]);
		for (int yy = righttopy; yy < rightbottomy; yy++)
			tolinar.push_back(board[yy][righttopx]);
		for (int xx = rightbottomx; xx > leftbottomx; xx--)
			tolinar.push_back(board[leftbottomy][xx]);
		for (int yy = leftbottomy; yy > lefttopy; yy--)
			tolinar.push_back(board[yy][lefttopx]);

			int tmp = tolinar.back();
			tolinar.pop_back();
			tolinar.push_front(tmp);

		for (int xx = lefttopx; xx < righttopx; xx++)
		{
			int tmp = tolinar.front();
			tolinar.pop_front();
			board[lefttopy][xx] = tmp;
		}
		for (int yy = righttopy; yy < rightbottomy; yy++)
		{
			int tmp = tolinar.front();
			tolinar.pop_front();
			board[yy][righttopx] = tmp;
		}
		for (int xx = rightbottomx; xx > leftbottomx; xx--)
		{
			int tmp = tolinar.front();
			tolinar.pop_front();
			board[leftbottomy][xx] = tmp;
		}
		for (int yy = leftbottomy; yy > lefttopy; yy--)
		{
			int tmp = tolinar.front();
			tolinar.pop_front();
			board[yy][lefttopx] = tmp;
		}
		step++;
	}
}


int SOLUTION = 9999999;


void dfs(int index, int depth)
{
	int tmpboard[51][51];
	memcpy(tmpboard, board, sizeof(board));
	if (depth == K)
	{
		int mmin = 9999999;
		for (int yy = 0; yy < N; yy++)
		{
			int tmp = 0;
			for (int xx = 0; xx < M; xx++)
			{
				tmp = tmp + board[yy][xx];
			}
			mmin = min(mmin, tmp);
		}

		SOLUTION = min(mmin, SOLUTION);
		return;
	}
	
	for (int i = 0; i < K; i++)
	{
		if (visit[i])
			continue;

		visit[i] = true;
		rotate(orders[i].x, orders[i].y, orders[i].num);
		dfs(i, depth + 1);
		visit[i] = false;
		memcpy(board,tmpboard, sizeof(board));
	}
}

int main()
{
		cin >> N >> M >> K;
		for (int yy = 0; yy < N; yy++)
		{
			for (int xx = 0; xx < M; xx++)
			{
				cin >> board[yy][xx];
			}
		}

		for (int i = 0; i < K; i++)
		{
			int y, x, num;
			cin >> y >> x >> num;
			y--;
			x--;
			orders[i].x = x;
			orders[i].y = y;
			orders[i].num = num;
		}
		

		int tmpboard[51][51];
		memcpy(tmpboard, board, sizeof(board));
		for (int i = 0; i < K; i++)
		{
			visit[i] = true;
			rotate(orders[i].x, orders[i].y, orders[i].num);
			dfs(i, 1);
			visit[i] = false;
			memcpy(board, tmpboard, sizeof(board));
		}
		cout << SOLUTION << endl;
}