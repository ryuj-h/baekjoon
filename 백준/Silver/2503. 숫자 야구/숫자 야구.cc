#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int tc = 0;
bool posible[1000];

int main() {
	cin >> tc;
	memset(posible, true, sizeof(posible));
	for (int i = 123; i <= 999;i++) {
		int 일, 십, 백;
		일 = i % 10;
		십 = (i / 10) % 10;
		백 = i / 100;
		if (일 == 십 || 일 == 백 || 십 == 백)
			posible[i] = false;
		if (일 == 0 || 십 == 0)
			posible[i] = false;
	}


	for (int ti = 0; ti < tc;ti++) {
		int nb;
		int str;
		int ball;
		cin >> nb >> str >> ball;
		
		vector<int> A(3, 0), B(3, 0);
		A[0] = nb % 10;
		A[1] = (nb / 10) % 10;
		A[2] = nb / 100;


		for (int i = 123; i <= 999;i++) {
			B[0] = i % 10;
			B[1] = (i / 10) % 10;
			B[2] = i / 100;

			int sstr = 0;
			int bball = 0;

			if (posible[i]) {
				for (int ii = 0; ii < 3;ii++) {
					for (int jj = 0; jj < 3; jj++) {
						if (ii == jj && A[ii] == B[jj]) {
							sstr++;
						}
						if (ii != jj && A[ii] == B[jj]) {
							bball++;
						}
					}
				}
				if (!(sstr == str && bball == ball)) {
					posible[i] = false;
				}
			}
		}
	}

	int ansers = 0;
	for (int i = 123; i <= 999;i++) {
		if (posible[i])
			ansers++;
	}
	cout << ansers << endl;
}