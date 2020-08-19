/*功能：
鸡蛋掉落
示例 1：

输入：K = 1, N = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
示例 2：

输入：K = 2, N = 6
输出：3
示例 3：

输入：K = 3, N = 14
输出：4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-egg-drop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
#include<bits/stdc++.h>

using namespace std;


int find(int K, int N) {
    if(K == 0 || N == 0) return 0;
    if(K == 1) return N;
    if(N == 1) return 1;
    int little = N + 1;
    for(int x = 1; x <= N; x ++){
        little = min(little, max(find(K, N-x), find(K-1, x-1)) + 1);
    }
    return little;
}

int main()
{
    int K,N;
    cin>>K>>N;
    int res = find(K, N);
    cout<<res;
    return 0;
}