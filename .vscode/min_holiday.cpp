// /*功能：
// 由于业绩优秀，公司给小Q放了 n 天的假，身为工作狂的小Q打算在在假期中工作、锻炼或者休息。他有个奇怪的习惯：不会连续两天工作或锻炼。只有当公司营业时，小Q才能去工作，只有当健身房营业时，小Q才能去健身，小Q一天只能干一件事。给出假期中公司，健身房的营业情况，求小Q最少需要休息几天。

// 画出状态转移图
// */
// # include <iostream>
// # include <cstdlib>
// # include <cstring>
// # include <stack>
// # define mem(a,b) memset(a,b,sizeof(a))
// using namespace std;
  
// int main(void){
//     int n ;
//     while(cin>>n){
//         int gym[n],i, work[n];
//         for ( i=0; i<n; ++i )
//             cin>>work[i];
//         for( i=0; i<n; ++i )
//             cin>>gym[i];
//         int dp[n+1][3]; // 0是休息，1是锻炼，2是工作
//         //memset(dp, 0x3f, sizeof(dp));
//         dp[0][0] = dp[0][1] = dp[0][2] = 0;
//         for ( int i=1; i<=n; ++i ){
//             if ( gym[i-1] == 1 ){
//                 // 可以锻炼
//                 dp[i][1] = min( dp[i-1][0], dp[i-1][2] );
//             }
//             if ( work[i-1] == 1 ){
//                 // 可以工作
//                 dp[i][2] = min( dp[i-1][0], dp[i-1][1] );
//             }
//             dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
//         }
//         int res = min(dp[n][0], min(dp[n][1], dp[n][2]));
//         cout<<res<<endl;
//     }
//     return 0;
// }


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> work(n), slp(n);
    for (int i = 0; i < n; ++i)
        cin >> work[i];
    for (int i = 0; i < n; ++i)
        cin >> slp[i];
    vector<vector<int>> dp(3, vector<int>(n + 1));
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
        if (slp[i - 1]) {
            dp[1][i] = max(dp[2][i - 1], dp[0][i - 1]) + 1;
        }
        if (work[i - 1]) {
            dp[2][i] = max(dp[1][i - 1], dp[0][i - 1]) + 1;
        }
    }
    cout << n - max(dp[0][n], max(dp[1][n], dp[2][n])) << endl;
 
    return 0;
}