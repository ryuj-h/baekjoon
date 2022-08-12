#include <string>
#include <vector>

using namespace std;

int gsize = 0;
int gtarget = 0;
int gresult = 0;
vector<int> gnumbers;

void dfs(int index, int sum)
{
    if (index == gsize)
    {
        if (sum == gtarget)
        {
            gresult++;
        }
        return;
    }
    dfs(index+1,sum + gnumbers[index]);
    dfs(index+1,sum - gnumbers[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    gsize = numbers.size();
    gtarget = target;
    gnumbers = numbers;
    dfs(0,0);
    return gresult;
}