#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[1001];
int indegree[1001];
int answer[1001];


void bfs()
{
	queue<int> q;
	
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
		answer[i] = 1;
	}

	while (!q.empty())
	{
		auto nb = q.front();
		q.pop();

		for (auto nb2 : graph[nb])
		{
			indegree[nb2] = indegree[nb2] - 1;
			if (indegree[nb2] == 0)
			{
				q.push(nb2);
				answer[nb2] = max(answer[nb2], answer[nb] + 1);
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		graph[A].push_back(B);
		indegree[B]++;
	}

	bfs();

	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << " ";
	}
}