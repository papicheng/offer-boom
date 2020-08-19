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

vector<string>ans;
void dfs(string s,int index)
{
    int n=s.size();
    if(index==n)
    {
        ans.push_back(s);
    }
    for(int i=index;i!=n;++i)
    {
        string tmp=s;
        swap(tmp[index],tmp[i]);
        dfs(tmp,index+1);
    }
}
vector<string> permutaion(string s)
{
    dfs(s,0);
    return ans;
}

vector<string> permutaiton_(string s)
{
    sort(s.begin(),s.end());
    vector<string> res;
    res.emplace_back(s);
    while (next_permutation(s.begin(),s.end()))
    {
        res.emplace_back(s);
    }
    return res;
}


int main()
{
    
    return 0;
}
