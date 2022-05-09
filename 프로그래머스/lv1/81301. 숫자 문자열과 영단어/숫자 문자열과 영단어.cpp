#include <string>
#include <vector>

using namespace std;

std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to){
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
    return str;
}
std::string strs[]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
std::string nums[]= {"0","1","2","3","4","5","6","7","8","9",};

int solution(string s) {
    int answer = 0;
    
    for(int i= 0; i<10;i++)
    {
        ReplaceAll(s,strs[i],nums[i]);
    }
    answer = std::stoi(s);
    return answer;
}