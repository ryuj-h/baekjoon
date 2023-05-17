#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;

int Get분해합(int nb) {
	int res = nb;
	while (nb > 0) {
		res += nb % 10;
		nb = nb / 10;
	}
	return res;
}


int main() {
	cin >> N;

	bool found = false;
	for (int i = 1; i < N;i++) {
		if (Get분해합(i) == N) {
			found = true;
			cout << i;
			break;
		}
	}
	if (!found)
		cout << 0;
}