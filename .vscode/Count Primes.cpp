/*功能：
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

*/
#include<bits/stdc++.h>

using namespace std;


bool iszhishu(int n){
        int m = sqrt(n);
        for(int i = 2; i <= m; ++i){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if( n < 2) return 0;
        int count = 0;
        for( int i = 2; i <= n; ++ i){
            if(iszhishu(i)){
                ++count;
                cout<< i<<"  ";
            }
        }
        return count;
    }

int main()
{
    int n = 10;
    int res = countPrimes(n);
    return 0;
}
