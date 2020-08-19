/*¹¦ÄÜ£º*/
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



int main()
{
    int N(0);
    cin>>N;
    vector<int> maxCnt;
    while (N)
    {
        int M(0);
        pair<int,int>xy;
        map<pair<int,int>,int> preTimes;
        map<pair<int,int>,int> times;
        cin>>M;
        while(M)
        {
            int len(0);
            cin>>len;
            maxCnt.push_back(0);
            for(int i=0;i<len;++i)
            {
                cin>>xy.first>>xy.second;
                if(preTimes.count(xy))
                {
                    times[xy]=preTimes[xy]+1;
                }
                else
                {
                    times[xy]=1;
                }
                if(times[xy]>maxCnt[maxCnt.size()-1])
                {
                    maxCnt[maxCnt.size()-1]=times[xy];
                }
            }
            preTimes.clear();
            preTimes.swap(times);
            M--;
        }
        N--;
    }
    for(int i=0;i<maxCnt.size();++i)
    {
        cout<<maxCnt[i]<<endl;
    }

    return 0;
}
