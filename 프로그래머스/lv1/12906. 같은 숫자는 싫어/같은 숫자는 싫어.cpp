#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int lastnumber = -1;
    for(const auto number: arr)
    {
        if (number != lastnumber)
        {
            answer.push_back(number);
            lastnumber = number;
        }
    }
    return answer;
}