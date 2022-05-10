#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, L;
int board[101][101];
bool visit[20];

bool is_path(vector<int>* line)
{
	bool start = true;
	bool set[101] = { false, };
	for (int i = 0; i < line->size() - 1; i++)
	{
		int curr = (*line)[i];
		int next = (*line)[i + 1];

		if (curr == next)//높이가 같으면
		{
			//아무것도 안하고 넘어감
		}
		else if (curr - next == 1)//내려가는경우
		{
			for (int j = i + 1; j <= i + L; j++)
			{
				if (j >= N)
					return false;
				if (set[j])
					return false;
				int nnext = (*line)[j];
				if (nnext != next)
					return false;
				set[j] = true;
			}
			i = i + L - 1;
		}
		else if (curr - next == -1)//올라가는경우
		{
			for (int j = i; j >= i - L + 1; j--)
			{
				if (j < 0)
					return false;
				if (set[j])
					return false;
				int prev = (*line)[j];
				if (prev != curr)
					return false;
				set[j] = true;
			}
		}
		else
			return false;
	}
	return true;
}

int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	vector<vector<int>> lines;

	for (int y = 0; y < N; y++)
	{
		vector<int>line;
		vector<int>line2;
		for (int x = 0; x < N; x++)
		{
			line.push_back(board[y][x]);
			line2.push_back(board[x][y]);
		}
		lines.push_back(line);
		lines.push_back(line2);
	}

	int res = 0;
	for (auto& vv : lines)
	{
		if (is_path(&vv))
		{
			res++;
		}
	}
	cout << res;

}