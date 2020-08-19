/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 1;
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<n && nums[i]!=nums[nums[i]])
                swap(nums[i],nums[nums[i]]);
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=i)
                return i;
        }
        return nums[0]==n?n+1:n;
    }
int main(void)
{
    int n;
    cin>> n;
    vector<int> vec;
    for(int i = 0; i<n;++i){
        int tmp;
        cin>> tmp;
        vec.push_back(tmp);
    }
    printf("%d\n",firstMissingPositive(vec));
  return 0;
}
