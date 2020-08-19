/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;
int sumfun(int m){
        int total = 0;
        while(m){
            total += (m % 10);
            m /= 10;
        }
        return total;
    }
    void movefun(int m, int n, int k, int i, int j, vector<bool> flag, int& count){
        int index = i*n + j;
        if(i<0 || i==m || j< 0 || j == n || (sumfun(i)+sumfun(j) > k) || flag[index] == true )
        {
            return;
        }
        flag[index] = true;
        count++;
        movefun(m, n, k, i+1, j, flag,count);
        flag[index] = false;
        movefun(m, n, k, i, j+1, flag,count);
        flag[index] = false;
        movefun(m, n, k, i-1, j, flag,count);
        flag[index] = false;
        movefun(m, n, k, i, j-1, flag,count);
        flag[index] = false;
        count --;
    }
    int movingCount(int m, int n, int k) {
        int i = 0, j = 0, count = 0;
        vector<bool> flag(m*n);
        movefun(m, n, k, i, j, flag, count);
        return count;
    }

int main()
{
    int m = 2, n = 3, k = 1;
    cout <<movingCount(m,n,k);
    return 0;
}
