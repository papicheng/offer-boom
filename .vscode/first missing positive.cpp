/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 1;
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<n && nums[i]!=nums[nums[i]]){
                cout<<"i nums[i] nums[nums[i]]: "<<i<<" "<<nums[i]<<" "<<nums[nums[i]]<<endl;
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i=1;i<n;i++){
            cout<<"i nums[i]: "<<i<<" "<<nums[i]<<endl;
            if(nums[i]!=i)
                return i;
        }
        return nums[0]==n?n+1:n;
    }
int main()
{
    vector<int> nums = {1,2,4,3,5,7,8,9,11,12};
    cout<< firstMissingPositive(nums)<<endl;
    return 0;
}
