#include <iostream>
#include <algorithm>
#include <vector>

int N;

std::vector<uint64_t> fibo;

using namespace std;

uint64_t FIBO(int numb)
{
	static bool init = false;
	if (init == false)
	{
		fibo.push_back(0);
		fibo.push_back(1);
		init = true;
	}
	if (numb == 0 || numb == 1)
		return fibo[numb];
	else if (numb >= fibo.size())
		fibo.push_back(FIBO(numb - 1) + FIBO(numb - 2));
	return fibo[numb];
}

int main()
{
	cin >> N;
	auto res = FIBO(N);
	cout << res << endl;
}