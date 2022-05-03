#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct
{
	int x;
	int y;
}point;

int N;
int M;
int SOLVE = 0;
bool visit[101][101];
int arr[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int bfs(int x, int y)
{
	if (visit[y][x])
		return 0;
	if (arr[y][x] == 0)
		return 0;
	queue < point > q;
	int res = 1;

	visit[y][x] = true;
	q.push({ x,y });
	while (!q.empty())
	{
		auto currnode = q.front();
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nextx = currnode.x + dx[d];
			int nexty = currnode.y + dy[d];

			if (nextx < 0 || nextx == N || nexty < 0 || nexty == N)
				continue;
			if (visit[nexty][nextx])
				continue;
			if (arr[nexty][nextx] == 1)
			{
				visit[nexty][nextx] = true;
				q.push({ nextx,nexty });
				res++;
			}
		}
	}
	return res;
}

int main(int argc, char** argv)
{
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			scanf("%1d", &arr[y][x]);
		}
	}
	
	vector<int> result;
	
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int res = bfs(x, y);
			if (res)
				result.push_back(res);
		}
	}

	std::sort(result.begin(), result.end());


	cout << result.size() << endl;
	for (auto v : result)
		cout << v << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}