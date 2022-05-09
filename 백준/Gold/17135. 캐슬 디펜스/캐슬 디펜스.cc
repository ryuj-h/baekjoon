#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, D;
int board[16][16];

typedef struct
{
	int x;
	int y;
}point;

vector<point> teams;//궁수들
vector<point> enemys;//적들


int ourturn()
{
	int killed = 0;
	vector<point> targets;
	for (auto& team : teams)
	{
		point selected = { 16,16 };
		int mindist = 16 * 16;
		for (auto& enemy : enemys)
		{
			int dist = abs(team.x - enemy.x) + abs(team.y - enemy.y);
			if (dist < mindist && dist <= D)
			{
				mindist = dist;
				selected = enemy;
			}
			else if (dist == mindist)
			{
				if (enemy.x < selected.x)
				{
					mindist = dist;
					selected = enemy;
				}
			}
		}
		if (selected.x != 16 && selected.y != 16)
		{
			bool find = false;
			for (auto& target : targets)
			{
				if (selected.x == target.x &&
					selected.y == target.y)
				{
					find = true;
					break;
				}
			}
			if (find == false)
			{
				targets.push_back(selected);
			}
		}
	}
	killed = targets.size();

	for (auto& target : targets)
	{
		for (vector<point>::iterator it = enemys.begin(); it != enemys.end();) {
			if ((*it).x == target.x &&
				(*it).y == target.y) {
				it = enemys.erase(it);
			}
			else {
				++it;
			}
		}
	}
	return killed;
}

void enemyturn()
{
	for (auto& enemy : enemys)
	{
		enemy.y = enemy.y + 1;
	}

	for (vector<point>::iterator it = enemys.begin(); it != enemys.end();) {
		if ((*it).y >= N) {
			it = enemys.erase(it);
		}
		else {
			++it;
		}
	}
}

int SOLVE = 0;

void dfs(int currx,int numteam)
{
	auto saveteam = teams;
	if (numteam == 3)
	{
		auto saveenemys = enemys;
		
		int fullkill = 0;
		while (true)
		{
			fullkill = fullkill + ourturn();
			enemyturn();
			if (enemys.empty())
			{
				SOLVE = max(fullkill, SOLVE);
				break;
			}
		}
		enemys = saveenemys;
		return;
	}
	for (int i = currx + 1; i < M; i++)
	{
		teams.push_back({i,N});
		dfs(i, numteam + 1);
		teams = saveteam;
	}
}

void solution()
{
	dfs(-1, 0);
}

int main()
{
	cin >> N;
	cin >> M;
	cin >> D;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == 1)
			{
				enemys.push_back({ x,y });
			}
		}
	}
	solution();
	cout << SOLVE << endl;
}
