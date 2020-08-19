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

vector<vector<int>> largeGroupPositions(string S) {
    int count=0;
    int start=0,end=0;
    vector<vector<int>> vecres;
    for(int i=0;i<S.size()-1;++i)
    {
        ++end;
        if(S[i]==S[i+1])
        {
            ++count;
        }
        else
        {
            if(count>=2)
            {
                vecres.push_back({start+1,end-1});
            }
            start=i;
            count=0;
        }
        if(count==S.size()-1&&count>=2)
            vecres.push_back({start,count});
    }
    return vecres;
}
int main()
{
    string S="aaa";
    vector<vector<int>>vec= largeGroupPositions( S);
    return 0;
}
