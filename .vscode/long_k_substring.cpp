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

int longestSubstring(string s,int k)
{
    unordered_map<char,int> umap;
    for(auto c:s)
    {
        umap[c]++;
    }
    vector<int> split_pos;
    for(int i=0;i<s.size();++i)
    {
        if(umap[s[i]]<k)
        {
            split_pos.emplace_back(i);
        }
    }
    if(split_pos.size()==0)
    {
        return s.size();
    }
    split_pos.emplace_back(s.size());
    int left(0),res(0);
    for(int i=0;i<split_pos.size();++i)
    {
        int len=split_pos[i]-left;
        if(len>res)
        {
            res=max(res,longestSubstring(s.substr(left ,len),k));
        }
        left=split_pos[i]+1;
    }
    return res;
}

int main()
{
    
    return 0;
}
