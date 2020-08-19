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
typedef long long LL;
using namespace std;

//定理：求N！
// 中  末尾连续0的个数
LL sum(LL N)
{
    LL ans = 0;
    while(N)
    {
        ans += N / 5;
        N /= 5;
    }
    return ans;
}
int factorial(int n)
{
    int res=1;
    while(n)
    {
        res*=n;
        --n;
    }
    cout<<res;
}

int main()
{
    int n;
    //cin>>n;
    int res;
    res=sum(10);
    cout<<res;
    return 0;
}
