#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

typedef struct
{
	int x;
	int y;
}point;

bool arr[200][200];

void print(int N)
{
	cout << endl;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (arr[y][x])
			{
				cout << "■";
			}
			else
			{
				cout << "□";
			}
		}
		cout << endl;
	}
	cout << endl;
}


bool visit[200];
int NODESIZE = 0;
bool solutionfound = false;

void dfs(int currnode)
{
	if (currnode == NODESIZE - 1)
	{
		solutionfound = true;
		return;
	}

	for (int i = 0; i < NODESIZE; i++)
	{
		if (arr[currnode][i] == false)
			continue;
		if (visit[i])
			continue;

		visit[i] = true;
		dfs(i);
	}
}


int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		memset(arr, false, sizeof(arr));
		memset(visit, false, sizeof(visit));
		solutionfound = false;

		int n;
		int homex, homey;
		int rockx, rocky;

		cin >> n;
		NODESIZE = n + 2;

		//0,0 집 n+1,n+1 콘서트장
		//그사이 전부 편의점
		vector<point> pointes;
		cin >> homex >> homey;
		pointes.push_back({ homex,homey });
		for (int j = 0; j < n; j++)
		{
			int storex, storey;
			cin >> storex>> storey;
			pointes.push_back({ storex,storey });
		}
		cin >> rockx>> rocky;
		pointes.push_back({ rockx,rocky });

		
		//노드 사이 간선 작업
		for (int i = 0; i < n + 1; i++)
		{
			auto curr = pointes[i];
			for (int j = i + 1; j < n + 2; j++)
			{
				auto target = pointes[j];
				auto distance = abs(curr.x - target.x) + abs(curr.y - target.y);

				//50미터 마다 맥주 한병 * 20개 1000미터
				//각 거리가 1000미터보다 가깝다면 이어져있다고 가정
				if (distance <= 1000)
				{
					arr[i][j] = true;
					arr[j][i] = true;
				}
			}
		}
		//print(n + 2);
		
		visit[0] = true;
		dfs(0);
		if (solutionfound)
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}
}