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


int combination_failed(int n,int m)
{
    int res=1;
    int diff=n-m;
    if(diff<m)
    {
        diff=diff^m;
        m=diff^m;
        diff=diff^m;
    }
    while(n>diff)
    {
        res*=n;
        --n;
    }
    while(m)
    {
        res/=m;
        --m;
    }
}

int combination(int n,int m)
{
    if(m==0||m==n)
    {
        return 1;
    }
    vector<vector<int>> dp(n,vector<int>(n));
    for(int j=0;j<m;++j)
    {
        dp[j][j]=1;
        for(int i=0;i<n;++i)
        {
            if(j==0)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
            
        }
    }
    return dp[n][m];
}

#include<iostream>
#include<vector>
using namespace std;
long long combination_2(long long n)
{
    return n*(n-1)/2;
}
int main()
{
    long long n(0),dis(0);
    cin>>n>>dis;
    long long tmp(0);
    long long right(0),left(0),res(0);
    vector<long long> vec;
    while(n)
    {
        cin>>tmp;
        vec.push_back(tmp);
        while(right>=2&&vec[right]-vec[left]>dis)
        {
            left++;
        }
        res+=combination_2(right-left);
        ++right;
        --n;
    }
    cout<<res%99997867 ;
    return 0;
}