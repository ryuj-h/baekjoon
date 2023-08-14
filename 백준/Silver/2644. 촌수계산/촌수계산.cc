#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;

int T1, T2;

int M;


bool arr[101][101];
int distoarr[101];
bool visit[101];
bool flag = false;
int SOLVE;


void bfs()
{
	std::queue<int> q;

	distoarr[T1] = 0;
	visit[T1] = true;
	q.push(T1);

	while (!q.empty())
	{
		auto currnode = q.front();
		int currdisto = distoarr[currnode];
		
		if (currnode == T2)
		{
			flag = true;
			SOLVE = currdisto;
			return;
		}
		
		q.pop();



		for (int i = 1; i <= N; i++)
		{
			if (arr[currnode][i] == false)
				continue;
			if (visit[i])
				continue;
			
			visit[i] = true;
			distoarr[i] = distoarr[currnode] + 1;

			q.push(i);
		}

	}



}

int main()
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));

	cin >> N;
	cin >> T1 >> T2;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = true;
		arr[to][from] = true;
	}
	bfs();
	if (flag)
		cout << SOLVE << endl;
	else
		cout << -1;
}