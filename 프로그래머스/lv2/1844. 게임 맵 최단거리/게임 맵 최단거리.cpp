#include<vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct
{
    int x;
    int y;
}QDATA;


int solution(vector<vector<int> > maps)
{
    static int distx[] = {0,0,-1,1};
    static int disty[] = {-1,1,0,0};
    
    int answer = 0;
    
    const int M = maps.size();
    const int N = maps[0].size();

    vector<vector<bool>> visit(M, vector<bool>(N));
    vector<vector<int>> dist(M, vector<int>(N));

    
    queue<QDATA> q;
    
    q.push({0,0});
    visit[0][0] = true;
    dist[0][0] = 1;
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        
        if (curr.x == N-1 && curr.y == M-1)
            return dist[curr.y][curr.x];
        
        for(int d = 0; d < 4;d++)
        {
            int nextx = curr.x + distx[d];
            int nexty = curr.y + disty[d];
            
            if (nextx < 0 || nextx >= N || nexty <0 || nexty >=M )
                continue;
            if (maps[nexty][nextx] == 0)
                continue;
            if (visit[nexty][nextx])
                continue;
            
            q.push({nextx,nexty});
            visit[nexty][nextx] = true;
            dist[nexty][nextx] = dist[curr.y][curr.x] + 1;
        }
    }
    
    return -1;
}