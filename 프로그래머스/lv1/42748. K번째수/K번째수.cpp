#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto cmd: commands)
    {
        vector<int> na;
        for(int i= cmd[0]; i <  cmd[1] + 1; i++)
        {
            na.push_back(array[i-1]);
        }
        std::sort(na.begin(),na.end());
        answer.push_back(na[cmd[2]-1]);
    }
    
    return answer;
}