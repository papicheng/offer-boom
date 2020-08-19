#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define LL long long
#define MAXN 100+10
#define MAXM 20000+10
#define INF 0x3f3f3f3f
using namespace std;
LL sum(LL N)//求N阶乘中 末尾连续的0的个数
{
    LL ans = 0;
    while(N)
    {
        ans += N / 5;
        N /= 5;
    }
    return ans;
}
int k = 1;
int main()
{
    int t;
    LL Q;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &Q);
        LL left = 1, right = 1000000000000;//一開始开小了 醉了
        LL ans = 0;
        while(right >= left)
        {
            int mid = (left + right) >> 1;
            if(sum(mid) == Q)//相等时 要赋值给ans
            {
                ans = mid;
                right = mid - 1;
            }
            else if(sum(mid) > Q)
                right = mid - 1;
            else
                left = mid + 1;
        }
        printf("Case %d: ", k++);
        if(ans)
            printf("%lld\n", ans);
        else
            printf("impossible\n");
    }
    return 0;
}