#include <string>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

int distance(int x1,int y1,int x2,int y2)
{
    return abs(x2-x1) + abs(y2-y1);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int arr[3][4];
    memset(arr,0,sizeof(arr));
    int lx = 0;
    int ly = 3;
    int rx = 2;
    int ry = 3;
    for(const int number: numbers)
    {
        string Hand;
        if(number == 1 || number ==4 || number== 7)
        {
            if(number ==1)
            {
                lx = 0;
                ly = 0;
            }else if (number == 4)
            {
                lx = 0;
                ly = 1;    
            }else if (number == 7)
            {
                lx = 0;
                ly = 2;    
            }
            Hand = "L";
        }
        else if ( number == 3|| number == 6|| number == 9)
        {
            if(number ==3)
            {
                rx = 0;
                ry = 0;
            }else if (number == 6)
            {
                rx = 0;
                ry = 1;    
            }else if (number == 9)
            {
                rx = 0;
                ry = 2;    
            }
            Hand = "R";
        }
        else
        {
            int tx,ty;
            if(number == 2)
            {
                tx = 1;
                ty = 0;
            }else if (number == 5)
            {
                tx = 1;
                ty = 1;
            }else if (number == 8)
            {
                tx = 1;
                ty = 2;
            }else if (number == 0)
            {
                tx = 1;
                ty = 3;
            }
            int ld = distance(lx,ly,tx,ty);
            int rd = distance(rx,ry,tx,ty);
            if(ld <rd)
            {
                Hand = "L";
            }
            else if (ld == rd)
            {
                if (hand == "left"){
                    Hand = "L";
                }else
                {
                    Hand ="R";
                }
            }
            else
            {
                Hand = "R";
            }
            if (Hand == "L")
            {
                lx =tx;
                ly =ty;
            }else
            {
                rx = tx;
                ry = ty;
            }
        }
        answer += Hand;
    }
    
    return answer;
}