#include<iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	vector<int> moneys = { 500,100,50,10,5,1 };
	int money;
	cin >> money;
	money = 1000 - money;
	int count = 0;
	for (auto mon : moneys)
	{
		if (money / mon >= 1)
		{
			count = count + money / mon;
			money = money % mon;
		}
	}
	cout << count;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}