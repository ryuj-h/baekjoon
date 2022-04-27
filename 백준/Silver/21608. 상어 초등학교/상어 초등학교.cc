#include<iostream>
#include <cstring>

using namespace std;

int stuinfo[401][4];
int arr[21][21];
int N;

void print()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int getnearfirend(int x, int y, int fr[])
{
	static int dirx[4] = { 0,0,-1,1 };
	static int diry[4] = { -1,1,0,0 };

	int frinum = 0;
	for (int d = 0; d < 4; d++)
	{
		if (x + dirx[d] < 0 || x + dirx[d] >= N || y + diry[d] < 0 || y + diry[d] >= N)
			continue;
		for (int i = 0; i < 4; i++)
		{
			if (arr[y + diry[d]][x + dirx[d]] == fr[i])
			{
				frinum++;
				break;
			}
		}
	}
	return frinum;
}


int getpoint()
{
	int point = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int curr = getnearfirend(x, y, stuinfo[arr[y][x]]);
			if (curr == 0)
				point = point + 0;
			else if (curr == 1)
				point = point + 1;
			else if (curr == 2)
				point = point + 10;
			else if (curr == 3)
				point = point + 100;
			else if (curr == 4)
				point = point + 1000;

		}
	}
	return point;
}

int getnearblank(int x, int y)
{
	static int dirx[4] = { 0,0,-1,1 };
	static int diry[4] = { -1,1,0,0 };

	int blanknum = 0;
	for (int d = 0; d < 4; d++)
	{
		if (x + dirx[d] < 0 || x + dirx[d] >= N || y + diry[d] < 0 || y + diry[d] >= N)
			continue;
		if (arr[y + diry[d]][x + dirx[d]] == 0)
			blanknum++;
	}
	return blanknum;
}

void solve(int stu, int fr1,int fr2,int fr3,int fr4)
{
	int minimumx = 99999;
	int minimumy = 99999;
	int maxnumfriend = -1;
	int maxblank = -1;

	int frds[] = { fr1,fr2,fr3,fr4 };
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (arr[y][x] == 0)
			{
				int frinum = getnearfirend(x, y, frds);
				int currblank = getnearblank(x, y);
				if (frinum > maxnumfriend)
				{
					minimumx = x;
					minimumy = y;
					maxblank = currblank;
					maxnumfriend = frinum;
				}
				else if (frinum == maxnumfriend)
				{
					if (currblank > maxblank)
					{
						minimumx = x;
						minimumy = y;
						maxblank = currblank;
						maxnumfriend = frinum;
					}
					else if (currblank == maxblank)
					{
						if (y < minimumy)
						{
							minimumx = x;
							minimumy = y;
							maxblank = currblank;
							maxnumfriend = frinum;
						}
						else if (y == minimumy)
						{
							if (x < minimumx)
							{
								minimumx = x;
								minimumy = y;
								maxblank = currblank;
								maxnumfriend = frinum;
							}
						}
					}
				}
			}
		}
	}
	arr[minimumy][minimumx] = stu;
}

int main(int argc, char** argv)
{
	int point = 0;
	cin >> N;
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < N*N; i++)
	{
		int A, B, C, D, E;
		cin >> A >> B >> C >> D >> E;
		solve(A, B, C, D, E);
		stuinfo[A][0] = B;
		stuinfo[A][1] = C;
		stuinfo[A][2] = D;
		stuinfo[A][3] = E;
	}
	cout << getpoint() << endl;


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}