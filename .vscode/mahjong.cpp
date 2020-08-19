/*功能：*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;

vector<int> card(9);
//检查剩余的牌是否能组成n个顺子或刻子
bool hasTribel(int n)
{
    if(n==0)
    {
        return true;
    }
    for(int i=0;i<card.size();++i)
    {
        //因为仍是从1开始检查，因此若检查到其牌数>=3，则必定是刻子
        if(card[i]>2)
        {
            card[i]-=3;
            if(hasTribel(n-1))
            {
                //检查剩下的牌能否组成n-1个顺子或者刻子
                card[i]+=3;
                return true;
            }
            card[i]+=3;
        }
        //否则只能是顺子
        else if(i<card.size()-2&&card[i]>0&&card[i+1]>0&&card[i+2]>0)
        {
            card[i]--;
            card[i+1]--;
            card[i+2]--;
            if(hasTribel(n-1))
            {
                card[i]++;
                card[i+1]++;
                card[i+2]++;
                return true;
            }
            card[i]++;
            card[i+1]++;
            card[i+2]++;
        }
    }
    return false;
}
//检查能否和牌
bool isWin()
{
    for(int i=0;i<9;++i)
    {
        //依次把1-9作为雀头拿出来，检查剩下的12张牌能否组成顺子或者刻子
        if(card[i]<2)
        {
            continue;
        }
        card[i]-=2;
        if(hasTribel(4))
        {
            card[i]+=2;
            return true;
        }
        card[i]+=2;
    }
    return false;
}


int main()
{
    vector<int > res;
    int tmp;
    for(int i=0;i<13;++i)
    {
        cin>>tmp;
        card[tmp-1]++;
    }
    for(int i=0;i<9;++i)
    {
        if(card[i]>3)
        {
            continue;
        }
        card[i]++;
        if(isWin())
        {
            res.push_back(i+1);
        }
        card[i]--;
    }
    if(res.empty())
        {
            res.push_back(0);
        }
        for(int i=0;i<res.size();++i)
        {
            cout<<res[i]<<" ";
        }
    return 0;
}
