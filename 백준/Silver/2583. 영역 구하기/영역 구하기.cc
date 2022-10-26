#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101];
bool visied[101][101];
int M,N,K;
std::vector <int> answ;

typedef struct 
{
    int x;
    int y;
}Point;

void printmap()
{
    for(int yy = 0; yy < M;yy ++){
        for (int xx = 0;xx <N;xx++){
            cout << arr[yy][xx];
        }
        cout <<endl;
    }
}


void bfs(const Point & stpnt){
    static int dx[4] = {0,0,-1,1};
    static int dy[4] = {-1,1,0,0};
    queue<Point> q;


    arr[stpnt.y][stpnt.x] = 1;
    q.push(stpnt);
    int size = 0;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        size++;
        for(int i = 0; i<4;i++){
            int nxtx = curr.x + dx[i];
            int nxty = curr.y + dy[i];

            if (nxtx < 0 || nxtx >= N || nxty < 0 || nxty >= M)
                continue;
            if (arr[nxty][nxtx] == 1)
                continue;
            arr[nxty][nxtx] = 1;
            q.push(Point{nxtx,nxty});
        }
    }
    answ.push_back(size);
}

void solve(){
    for(int y = 0; y< M;y++){
        for (int x = 0; x< N; x++){
            if (arr[y][x] == 0){
                bfs(Point{x,y});
            }
        }
    }
}

//wsl

int main(){
    memset(arr,0,sizeof(arr));
    memset(visied,0,sizeof(visied));
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++){
        int x1,y1,x2,y2;
        cin >>x1>>y1>>x2>>y2;

        for (int yy = y1;yy <y2;yy++){
            for(int xx = x1; xx < x2;xx ++){
                arr[yy][xx] = 1;
            }
        }
    }
    solve();
    sort(answ.begin(), answ.end());
    cout << answ.size() <<endl;
    for (auto vv : answ){
        cout << vv <<" ";
    }
}