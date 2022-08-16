#include <string>
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int g_N;
vector<bool> g_visit;

void bfs(int index,const vector<vector<int>> computers)
{
    queue<int> q;
    g_visit[index] = true;
    q.push(index);
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i = 0;i< g_N;i++)
        {
            if (i == curr)
                continue;
            if(computers[curr][i] == 1 && g_visit[i] == false)
            {
                g_visit[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    g_N = n;
    g_visit.resize(g_N);
    
    for(int i= 0;i<g_N;i++)
    {
        if(g_visit[i] == false)
        {
            bfs(i,computers);
            answer++;
        }
    }
    
    return answer;
}
