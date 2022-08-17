#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool dfs(string start,const vector<vector<string>> tickets,
         vector<string> &answer,vector<bool> &visit, int USED)
{   
    answer.push_back(start);
    if (USED == tickets.size())
    {
        return true;
    }
    
    for(int i= 0; i< tickets.size();i++)
    {
        if(visit[i])
            continue;
        if(tickets[i][0] == start)
        {
            visit[i] = true;
            bool T = dfs(tickets[i][1],tickets, answer, visit,USED+1);
            if(T)
                return true;
            visit[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;    
    vector<bool> Visit(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN",tickets,answer,Visit,0);
    
    return answer;
}