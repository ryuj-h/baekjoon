#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N ,M;

bool visit[201][201];
int arr[201][201];


int robotx, roboty;
int robotdirection;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int SOLVE = 1;

int changedir(int dir)
{
	return (dir + 3) % 4;
}

void pirnt()
{
	cout << endl;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << arr[y][x] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs()
{
	//pirnt();
	for (int i = 0; i < 4; i++)
	{
		robotdirection = changedir(robotdirection);
		int nextx = robotx + dx[robotdirection];
		int nexty = roboty + dy[robotdirection];

		if (nextx < 0 || nexty < 0 || nextx >= M || nexty >= N)
			continue;
		if (visit[nexty][nextx])
			continue;
		if (arr[nexty][nextx] != 0)
			continue;


		SOLVE++;
		//arr[nexty][nextx] = SOLVE;
		visit[nexty][nextx] = true;
		robotx = nextx;
		roboty = nexty;
		dfs();
	}

	int backdirect = changedir(changedir(robotdirection));
	int backx = robotx + dx[backdirect];
	int backy = roboty + dy[backdirect];

	if (backx < 0 || backy < 0 || backx >= M || backy >= N)
		return;
	if (arr[backy][backx] != 1)
	{
		robotx = backx;
		roboty = backy;
		dfs();
	}
	else
	{
		cout << SOLVE;
		exit(0);
	}
}

int main()
{
	cin >> N >> M;
	cin >> roboty >> robotx >> robotdirection;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> arr[y][x];
		}
	}

	arr[roboty][robotx] = -1;
	visit[roboty][robotx] = true;
	dfs();
	cout << SOLVE << endl;
}