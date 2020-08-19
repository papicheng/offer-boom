/*求数组的逆序对
两种方法：1.逆序对，2.归并
*/
#include<bits/stdc++.h>

using namespace std;

int n;
int a[1005], c[1005];//原始数组a，数组数组c

int lowbit(int x){
    return x & (-x);
}

void update(int i , int k){     //往第i个结点插入k
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i){      //求A[1 ~ i]的和
    int sum = 0;
    while(i > 0){
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    //有问题啊啊啊
    long long ans;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int t;
        scanf("%d", &t);
        update(i, t);
        ans += i - getsum(t);
    }
    for(int i = 1; i <= n; ++i){
        cout<< c[i] <<endl;
    }
    cout<<"ans: "<< ans<<endl;
    return 0;
}
