/*���ܣ�*/
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;        
        hash[0] = 1;                //�������ǰ׺��Ϊ0������ǰ׺��Ϊ0�����������������ʼ��Ϊ1
        int sum = 0;
        int ans = 0;
        for (int num : nums) {
            sum += num;
            ans += hash[sum - k];   //����ǰ׺��Ϊ sum - k ������ĸ���
            hash[sum]++;            //ǰ׺��Ϊsum�ĸ���++���������Ҫд�ں��棬д��ǰ���п����Լ��õ����Լ���
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
        if(r>=base)//�ڸý����в����ܴ����������
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
