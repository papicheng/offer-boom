/*功能：*/
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;        
        hash[0] = 1;                //空数组的前缀和为0，所以前缀和为0的连续子数组个数初始化为1
        int sum = 0;
        int ans = 0;
        for (int num : nums) {
            sum += num;
            ans += hash[sum - k];   //加上前缀和为 sum - k 的数组的个数
            hash[sum]++;            //前缀和为sum的个数++，这条语句要写在后面，写在前面有可能自己用到了自己。
            // cout<<sum<<endl;
        }
        return ans;
    }
};
int convert(int val,int base)
{
    int ans=0,wight=1,r;
    while(val)
    {
        r=val%10;
        val/=10;
        if(r>=base)//在该进制中不可能存在这个数。
            return -1;
        ans+=wight*r;
        wight*=base;
    }
    return ans;
}

int main()
{
    int res = convert(11,2);
    cout<<res;
    return 0;
}
