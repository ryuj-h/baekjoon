#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M, V;

bool arr[1001][1001];
bool visit[1001];

void dfs(int currnode)
{
	cout << currnode << " ";

	for (int i = 1; i <= N; i++)
	{
		if (arr[currnode][i] && !visit[i])
		{
			visit[i] = true;
			dfs(i);
		}
	}
}


void bfs(int root)
{
	queue <int> q;
	visit[root] = true;
	q.push(root);
	while (!q.empty())
	{
		int currnode = q.front();
		q.pop();

		cout << currnode << " ";

		for (int i = 1; i <= N; i++)
		{
			if (visit[i])
				continue;
			if (arr[currnode][i])
			{
				visit[i] = true;
				q.push(i);
			}
		}
	}
	cout << endl;
}

int main() {
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = true;//양방향
		arr[to][from] = true;
	}


	visit[V] = true;
	dfs(V);
	cout << endl;
	memset(visit, false, sizeof(visit));
	bfs(V);

	return 0;
}