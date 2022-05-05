#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int F, S, G, U, D;
int SOLVE = 0;
bool flag = false;

bool visit[2000001] = { false, };

typedef struct
{
	int floor;
	int turn;
}info;

void bfs()
{
	queue <info> q;
	q.push({ S,0 });

	visit[S] = true;
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		if (G == curr.floor)
		{
			flag = true;
			SOLVE = curr.turn;
			break;
		}

		if (curr.floor + U <= F)
		{
			if (visit[curr.floor + U] == false)
			{
				visit[curr.floor + U] = true;
				q.push({ curr.floor + U , curr.turn + 1 });
			}
		}

		if (curr.floor - D > 0)
		{
			if (visit[curr.floor - D] == false)
			{
				visit[curr.floor - D] = true;
				q.push({ curr.floor - D, curr.turn + 1 });
			}
		}
	}
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	
	bfs();
	
	if (flag == false)
		cout << "use the stairs" << endl;
	else
		cout << SOLVE << endl;
	//cout << SOLVE << endl;
}