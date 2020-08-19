/*功能：*/
#include <bits/stdc++.h>
using namespace std;
void mergesort(vector<int> &a,int l,int r)
{
    //设置递归边界
    if(l==r) return;
    //将左右两个子区间排成有序的
    int m=(l+r)>>1;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    int lp=l,rp=m+1,s=0;
	vector<int>b(a.size());
    ///合并两个子区间
    while(lp<=m&&rp<=r)
    {
        if(a[lp]<a[rp])
        {
            b[s]=a[lp];
            ++lp;
        }
        else
        {
            b[s]=a[rp];
            ++rp;
        }
        ++s;
    }
    //将有区间有剩余的数据装进b数组
    while (lp<=m)
    {
        b[s]=a[lp];
        ++lp;
        ++s;
    }
    while(rp<=r)
    {
        b[s]=a[rp];
        ++rp;
        ++s;
    }
    //将b数组赋值回原来的区间
    for(int i=l;i<=r;++i) a[i]=b[i-l];
}
int main()
{
	vector<int>a={5,6,3,2,7,6,3,1};
    mergesort(a,0,a.size()-1);
    for(auto i:a) cout<<i<<" ";
    return 0;
}
