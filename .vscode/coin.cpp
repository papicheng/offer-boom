/*功能：硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

*/
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

int waysToChange(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        vector<int> coins={1,5,10,25};
        for(auto coin:coins)
        {
            for(int i=coin;i<=n;++i)
            {
                dp[i]=(dp[i]+dp[i-coin])%1000000007;
            }
        }
        return dp[n];
    }
int main()
{
    int n=5;
    int res;
    res=waysToChange(n);
    cout<<res<<endl;
    return 0;
}

