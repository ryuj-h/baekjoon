#include<iostream>
#include <queue>

using namespace std;

int N;
int M;
int SOLVE = 0;
bool visit[101];
bool arr[101][101];

void bfs(int root)
{
	queue <int> q;
	visit[root] = true;
	q.push(root);
	while (!q.empty())
	{
		int currnode = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (visit[i])
				continue;
			if (arr[currnode][i])
			{
				SOLVE++;
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = true;
		arr[to][from] = true;
	}

	bfs(1);
	cout << SOLVE << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}