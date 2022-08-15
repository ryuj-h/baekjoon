#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
string g_target;
int result = 999;

bool onediff(string a, string b)
{
    int diff = 0;
    for(int i = 0; i< a.size();i++)
    {
        if(a.c_str()[i] != b.c_str()[i])
        {
            diff++;
        }
    }
    if (diff == 1)
        return true;
    else
        return false;
}

void dfs(string curr, const vector<string> words, vector<bool> visit,int step)
{
    if (onediff(curr,g_target))
    {
        cout << curr<<endl;
        result = min(result, step+1);
        return;
    }
    
    for(int i = 0; i<N;i++)
    {
        if(visit[i] == false && onediff(curr,words[i]))
        {
            visit[i] = true;
            
            dfs(words[i],words,visit,step+1);
            
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    N = words.size();
    g_target = target;
    
    bool found = false;
    for(const auto word:words)
    {
        if (word == target)
        {
            found = true;
            break;
        }
    }
    
    if(found == false)
    {
        return 0;
    }
    
    vector<bool>visit(N);
    
    dfs(begin,words,visit,0);
    
    return result;
}