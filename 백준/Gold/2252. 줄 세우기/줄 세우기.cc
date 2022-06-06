#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

//bool arr[32001][32001];

vector<int>graph[32001];

bool visited[32001];

stack <int> st;

int N, M;

void dfs(int index)
{
	visited[index] = true;


	for (auto nb : graph[index])
	{
		if (visited[nb])
			continue;
		dfs(nb);
	}

	st.push(index);
	//order.push_back(index);
}

int main()
{
	//memset(arr, 0, sizeof(arr));
	//memset(visited, false, sizeof(visited));

	cin >> N >> M;
	int a, b;
	for (int i = 1; i <= M; i++)
	{
		cin >> a>> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
			dfs(i);
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

}