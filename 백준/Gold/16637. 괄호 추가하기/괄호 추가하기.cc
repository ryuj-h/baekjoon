#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

char sik[200];
int N;
int SOLVE = -999999999;

int calc(int num1, int num2, char c)
{
	int result;
	switch (c)
	{
	case '-':result = num1 - num2; break;
	case '+':result = num1 + num2; break;
	case '*':result = num1 * num2; break;
	default:
		break;
	}
	return result;
}

void dfs(int index, int value)
{
	//cout << sik[index] - '0' << endl;
	//cout << value << endl;
	if (index + 2 >= N)
	{
		SOLVE = max(SOLVE, value);
		return;
	}

	char c = sik[index + 1];
	int tmp = calc(value, sik[index + 2] - '0', c);
	dfs(index + 2, tmp);
	if (index + 4 <= N)
	{
		int tmp2 = calc(sik[index+2] - '0', sik[index + 4] - '0', sik[index + 3]);
		int tmp1 = calc(value, tmp2, c);
		dfs(index + 4, tmp1);
	}

}

int main()
{
	cin >> N;
	cin >> sik;

	dfs(0, sik[0]-'0');
	cout << SOLVE << endl;
}
