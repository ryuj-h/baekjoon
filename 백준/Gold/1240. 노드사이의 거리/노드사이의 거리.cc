#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int to;
	int dist;
}node;

int N, M;
vector<vector<node>> graph;
bool visited[1001];
int Solution;

void dfs(int curr, int goal, int depth, int dist) {
	if (depth == N)
		return;

	if (curr == goal) {
		Solution = min(Solution, dist);
		return;
	}
	
	for (const node & point : graph[curr]) {
		if (visited[point.to]) continue;

		visited[point.to] = true;
		dfs(point.to, goal, depth + 1, dist + point.dist);
		visited[point.to] = false;
	}



	/*for (int i = 1; i < N;i++) {
		if (curr == i)
			continue;
		dfs(i, goal, depth + 1, dist + graph_arr[curr][i]);
	}*/
}

int main() {
	graph.resize(1001);
	cin >> N >> M;
	for (int i = 0; i < N-1;i++) {
		int dist, a, b;
		cin  >> a >> b>> dist;
		graph[a].push_back({ b,dist });
		graph[b].push_back({ a,dist });
	}

	for (int i = 0; i < M; i++) {
		Solution = 2147483647;//INT_MAX;
		int start, end;
		cin >> start >> end;
		dfs(start, end, 0,0);
		cout << Solution << endl;
	}
}