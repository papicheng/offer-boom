/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for(long long i = 0; i < digits.size(); ++i){
            num = 10 * num + digits[i];
        }
        num += 1;
        vector<int> vec;
        while (num)
        {
            vec.push_back(num % 10);
            num /= 10;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
// @lc code=end

