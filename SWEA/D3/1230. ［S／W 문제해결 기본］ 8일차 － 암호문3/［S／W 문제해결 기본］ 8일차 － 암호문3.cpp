

#include<iostream>
#include <vector>

using namespace std;


std::vector<int> v;

int main(int argc, char** argv)
{
	int test_case;
	for (test_case = 1; test_case <= 11; ++test_case)
	{
		int N;
		cin >> N;

		v.resize(N);
		for (int i = 0; i < N;i++) {
			int nb;
			cin >> nb;
			v[i] = nb;
		}

		int M;
		cin >> M;
		for (int i = 0; i < M;i++) {
			char c;
			cin >> c;
			if (c == 'I') {
				int x, y;
				cin >> x >> y;
				for (int j = 0; j < y; j++) {
					int s;
					cin >> s;
					v.insert(v.begin() + x + j, s);
				}
			}
			else if (c == 'D') {
				int x, y;
				cin >> x >> y;
				v.erase(v.begin() + x, v.begin() + x + y);
			}
			else if (c == 'A') {
				int y;
				cin >> y;
				for (int j = 0; j < y; j++) {
					int  s;
					cin >> s;
					v.emplace_back(s);
				}

			}
		}

		cout << "#" << test_case;
		for (int i = 0; i < 10; i++) {
			printf(" %d", v[i]);
		}
		printf("\n");
		v.clear();
	}
}
