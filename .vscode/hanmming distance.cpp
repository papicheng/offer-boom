/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

int gethamming(int a, int b){
        int cnt = 0;
        int n =  32;
        while(n--){
            cnt += (a & 1 ^ b & 1);
            a = a>>1;
            b = b>>1;
        }
        return cnt;
    }

int main()
{
    int a = 4, b = 14;
    cout<< gethamming(a, b) <<endl;
    return 0;
}
