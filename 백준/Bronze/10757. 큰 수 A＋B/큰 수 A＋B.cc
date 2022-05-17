#include<iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
#include <string>

using namespace std;

string a, b;

int Sumarr[10001];
queue<int> Av;
queue<int> Bv;


int main(int argc, char** argv)
{
	cin >> a >> b;
	
	int maxsize = max(a.size(), b.size());

	for (int i = a.size() - 1; i >= 0; i--)
		Av.push(a[i] - '0');

	for (int i = b.size() - 1; i >= 0; i--)
		Bv.push(b[i] - '0');

	
	for (int i = 0; i < maxsize; i++)
	{	
		int A = 0;
		int B = 0;
		
		if (!Av.empty())
		{
			A = Av.front();
			Av.pop();
		}
		if (!Bv.empty())
		{
			B = Bv.front();
			Bv.pop();
		}
		Sumarr[i] = Sumarr[i] + A + B;
		if (Sumarr[i] > 9)
		{
			Sumarr[i + 1] = Sumarr[i + 1] + 1;
			Sumarr[i] = Sumarr[i] % 10;
		}
	}

	if (Sumarr[maxsize] > 0)
		cout << Sumarr[maxsize];
	for (int i = maxsize - 1; i >= 0; i--)
	{
		cout << Sumarr[i];
	}

	return 0;
}