/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int dif = INT_MAX;
    static bool cmp(int a, int b){
        return a < b;
    }
    void func(vector<int>& stones, int sum, int avg, int sum1, int sum2, int i){
        if(sum1 >= avg && sum2 >= avg){
            if(2 * sum1 - sum < dif) dif = 2 * sum1 - sum;
            if(2 * sum2 - sum < dif) dif = 2 * sum2 - sum;
            return;
        }
        if(sum1 >= avg){
            if(2 * sum1 - sum < dif) dif = 2 * sum1 - sum;
            return;
        }
        if(sum2 >= avg){
            if(2 * sum2 - sum < dif) dif = 2 * sum2 - sum;
            return;
        }
        if(i >= stones.size()) return;
        if(dif <= 1) return;
        func(stones, sum,avg, sum1 + stones[i], sum2, i + 1);
        func(stones, sum, avg, sum1, sum2 + stones[i], i + 1);
        return;
    }
    int lastStoneWeightII(vector<int>& stones) {
        /*
        priority_queue<int, vector<int>, less<int>> pq;
        for(auto i:stones){
            pq.push(i);
        }
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int dif = a - b;
            if(dif > 0){
                pq.push(dif);
            }
        }
        if(pq.empty()){
            return 0;
        }
        else
        {
            return pq.top();
        } 
        */
       int sum = 0;
       for(auto i : stones){
           sum += i;
       }
       int avg = (sum+1) >> 1;
       func(stones, sum, avg, 0, 0, 0);
       return dif;
    }
};
// @lc code=end

