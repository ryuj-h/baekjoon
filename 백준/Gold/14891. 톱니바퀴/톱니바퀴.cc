#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

//최상단 0
int t[4][8];

//맞다은부분 2, 6
int head[4] = { 0, };

int K;

bool visit[4] = { false ,};
void rotate(int iindex, int ddirection)
{
	queue<pair<int, int>> q;
	q.push(make_pair(iindex, ddirection));

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		int index = curr.first;
		int direction = curr.second;

		visit[index] = true;
		int beforeright = t[index][(head[index] + 2) % 8];
		int beforeleft = t[index][(head[index] + 6) % 8];

		//회전
		head[index] = (head[index] + direction + 8) % 8;

		//좌 회전 가능?
		if (index - 1 >= 0 && visit[index - 1] == false)
		{
			if (t[index - 1][(head[index - 1] + 2) % 8] != beforeleft)
			{
				q.push(make_pair(index - 1, -1 *direction));
			}
		}
		//우 회전 가능?
		if (index + 1 < 4 && visit[index + 1] == false)
		{
			if (t[index + 1][(head[index + 1] + 6) % 8] != beforeright)
			{
				q.push(make_pair(index + 1, -1 * direction));
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &t[i][j]); //한글자씩 입력받기
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		memset(visit, false, sizeof(visit));
		int target;
		int dir;
		cin >> target >> dir;
		target--;
		rotate(target, -1 * dir);
	}

	int point[] = { 1,2,4,8 };
	int get = 0;
	for (int i = 0; i < 4; i++)
	{
		if (t[i][head[i]] == 1)
		{
			get = get + point[i];
		}
	}
	cout << get;
}