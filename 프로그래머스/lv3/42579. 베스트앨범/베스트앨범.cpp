
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#include <map>

using namespace std;

typedef struct {
	int number;
	int plays;
}Song;

std::map <std::string, std::vector<Song >> mmap;

bool cmp(const pair<std::string,std::vector<Song>>& a,
	const pair<std::string, std::vector<Song>>& b)
{
	int aplaysize = 0;
	int bplaysize = 0;
	for (auto& song : a.second)
		aplaysize = aplaysize + song.plays;
	for (auto& song : b.second)
		bplaysize = bplaysize + song.plays;

	return aplaysize > bplaysize;
}

bool cmp2(const Song & a, const Song& b)
{
	if (a.plays > b.plays)
		return true;
	else if (a.plays == b.plays)
		if (a.number < b.number)
			return true;
	return false;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	

	for (int i = 0; i < genres.size(); i++)
	{
		auto genre = genres[i];
		int play = plays[i];
		mmap[genre].push_back({i,play});
	}

	vector<pair<std::string, std::vector<Song>>> vec;

	for (auto& it : mmap) {
		vec.push_back(it);
	}
	sort(vec.begin(), vec.end(), cmp);
	for (auto& it : vec) {
		sort(it.second.begin(), it.second.end(), cmp2);
	}

	for (auto& it : vec) {
		int limit = 0;
		for (auto& it2 : it.second) {
			if (limit == 2)
				break;
			answer.push_back(it2.number);
			limit++;
		}
	}

	return answer;
}


int main()
{
	solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });

}