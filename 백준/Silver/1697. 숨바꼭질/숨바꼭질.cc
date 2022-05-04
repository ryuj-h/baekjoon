#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visit[400001] = { 0, };

int N, K;
int SOLVE = 9999999;

typedef struct
{
	int num;
	int turn;
}ST;

void bfs()
{
	queue <ST> q;
	q.push({ N ,0});
	visit[N] =  true;
	while (!q.empty())
	{
		auto curr = q.front();
		int currnb = curr.num;
		int currturn = curr.turn;
		q.pop();
		if (curr.num == K)
		{
			SOLVE = curr.turn;
			break;
		}

		if (visit[curr.num + 1] == false)
		{

			visit[curr.num + 1] = true;
			q.push({ curr.num + 1,curr.turn + 1 });
		}
		if (curr.num - 1 >= 0)
		{
			if (visit[curr.num - 1] == false)
			{
				visit[curr.num - 1] = true;
				q.push({ curr.num - 1,curr.turn + 1 });
			}
		}
		if (curr.num * 2 - K <= K - currnb)
		{
			if (visit[curr.num * 2] == false)
			{

				visit[curr.num * 2] = true;
				q.push({ curr.num * 2,curr.turn + 1 });
			}
		}
	}
}

int main()
{
	cin >> N>> K ;
	
	bfs();
	cout << SOLVE << endl;
}