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
LL sum(LL N)//��N�׳��� ĩβ������0�ĸ���
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
        LL left = 1, right = 1000000000000;//һ�_ʼ��С�� ����
        LL ans = 0;
        while(right >= left)
        {
            int mid = (left + right) >> 1;
            if(sum(mid) == Q)//���ʱ Ҫ��ֵ��ans
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