/*功能：指数运算*/
#include<bits/stdc++.h>

using namespace std;


int main()
{
    float m = 2;
    int n = 7;
    float ans = 1;
    while(n){
        ans *= m;
        m *= m;
        n /= 2;
    }
    cout << ans << endl;
    return 0;
}
