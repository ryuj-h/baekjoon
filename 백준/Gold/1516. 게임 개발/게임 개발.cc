#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int N;
vector<int> graph[501];
int indegree[501];
int Time[501];
int answer[501];


void bfs()
{
	queue<int> q;
	
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
		answer[i] = Time[i];
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
			}
			answer[nb2] = max(answer[nb2], answer[nb] + Time[nb2]);
		}
	}
}

int main()
{
	cin >> N;

	int A, B;
	for (int i = 1; i <= N; i++)
	{
		cin >> Time[i];

		int B;
		while (true)
		{
			cin >> B;
			if (B == -1)
				break;
			graph[B].push_back(i);
			indegree[i]++;
		}
	}

	bfs();

	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << endl;
	}
}