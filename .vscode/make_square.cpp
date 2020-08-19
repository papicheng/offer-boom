/*功能：*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;







int main()
{
    
    return 0;
}


class Solution {
public:
    bool findSum(vector<int>& nums, vector<bool>& visited, int s, int target) {
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        int lastTarget = -1;
        for (int j=s; j>=0; j--) {
            if (visited[j]) {
                continue;
            }
            int t = target - nums[j];
            if (lastTarget == t) { // 这个目标已经递归过了，直接跳过
                continue;
            }
            if (t < 0) {
                continue;
            }
            visited[j] = true;
            lastTarget = t;
            if (findSum(nums, visited, j-1, lastTarget)) { //递归寻找下一个长度
                return true;
            } else {
                visited[j] = false;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) {
            return false;
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 4 > 0) {
            return false;
        }
        int edge = sum / 4;
        int res = 0;
        vector<bool> visited(size, false);
        for (int i=size-1; i>=0; i--) {
            if (visited[i]) {
                continue;
            }
            if (findSum(nums, visited, i, edge)) {
                res++;
            }
        }
        if (res != 4) {
            return false;
        }
        return true;
    }

};
