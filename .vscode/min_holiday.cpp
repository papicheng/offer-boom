// /*���ܣ�
// ����ҵ�����㣬��˾��СQ���� n ��ļ٣���Ϊ�������СQ�������ڼ����й���������������Ϣ�����и���ֵ�ϰ�ߣ������������칤���������ֻ�е���˾Ӫҵʱ��СQ����ȥ������ֻ�е�����Ӫҵʱ��СQ����ȥ����СQһ��ֻ�ܸ�һ���¡����������й�˾��������Ӫҵ�������СQ������Ҫ��Ϣ���졣

// ����״̬ת��ͼ
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
//         int dp[n+1][3]; // 0����Ϣ��1�Ƕ�����2�ǹ���
//         //memset(dp, 0x3f, sizeof(dp));
//         dp[0][0] = dp[0][1] = dp[0][2] = 0;
//         for ( int i=1; i<=n; ++i ){
//             if ( gym[i-1] == 1 ){
//                 // ���Զ���
//                 dp[i][1] = min( dp[i-1][0], dp[i-1][2] );
//             }
//             if ( work[i-1] == 1 ){
//                 // ���Թ���
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