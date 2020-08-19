/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int big = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            if(sum > big){
                big = sum;
            }
        }
        return big;
    }
};
// @lc code=end

