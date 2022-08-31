#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    vector<int> array = queue1;
    int left = 0;
    int right = queue1.size();
    
    unsigned long long q1sum = 0;
    unsigned long long q2sum = 0;
    
    for(const auto num: queue1)
    {
        q1sum+=num;
    }
    for(const auto num: queue2)
    {
        array.push_back(num);
        q2sum+=num;   
    }
    
    if ((q1sum + q2sum) % 2 == 1)
        return -1;
    
    unsigned long long goal = (q1sum + q2sum) /2;  
    
    
    while (right < array.size() && left <= right)
    {
        if (q1sum < goal)
        {
            q1sum += array[right];
            right++;
        }
        else if (q1sum > goal)
        {
            q1sum -=array[left];
            left++;
        }
        else
        {
            break;
        }
        answer ++;
    }
    if (q1sum != goal)
        return -1;
    
    return answer;
}