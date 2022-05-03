#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> v;
int B, C;
unsigned long long Sol = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		v.push_back(number);
	}
	cin >> B >> C;

	for (auto people : v)
	{
		people = people - B;
		Sol++;
		if (people > 0)
		{
			int BB = people / C;
			int CC = people % C;
			Sol = Sol + BB;
			if (CC > 0)
				Sol = Sol + 1;
		}
	}
	cout << Sol << endl;
	return 0;
}