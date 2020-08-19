/*功能：
换钱的方法数，
给定数组arr,arr中所有的值都为正数且不重复。每个值代表一种面值的货币 ，每种货币可以使用任意张，再给定一个正数aim带帽要找的钱，求还钱有多少种方法。
*/
#include<iostream>
#include<vector>

using namespace std;

int process(vector<int>arr, int index, int aim)
{
    int res=0;
    if(index==arr.size())
        res=aim==0?1:0;
    else
    {
        for(int i=0;arr[index]*i<=aim;++i)
            res+=process(arr,index+1,aim-arr[index]*i);
    }
    return res;
}

int chargeCount(vector<int>arr, int aim)
{
    if(arr.size()==0||aim<0)
        return 0;
    return process(arr, 0,aim);
}

int dpsolve(vector<int>arr,int aim)
{
    if(arr.size()==0||aim<0)
        return 0;
    int *dp=new int[aim+1];
    for(int i=0;arr[0]*i<=aim;++i)
        dp[arr[0]*i]=1;
    for(int i=1;i<arr.size();++i)
        for(int j=1;j<=aim;++j)
            dp[j]+=j-arr[i]>=0?dp[j-arr[i]]:0;
    return dp[aim];
}


int main()
{
    vector<int> arr={5,10,25,1};
    int aim=15;
    int res=chargeCount(arr,aim);
    cout<<res<<endl;
    res=dpsolve(arr,aim);
    cout<<res<<endl;
    return 0;
}
