/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            int dif = target - nums[i];
            if(mp.count(dif)){
                return {mp[dif] , i};
            }
            else
            {
                mp[nums[i]] = i;
            }
            
        }
        return {};
    }
};
// @lc code=end

