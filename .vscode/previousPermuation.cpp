/*功能：*/
#include<bits/stdc++.h>

using namespace std;

vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
         if (nums.size() < 1) {
             return {};
         }
         int i = 0;
        // 从右向左遍历，找到第一个比当前值大的，然后从这个位置向后找比它小但是最接近的值，交换，
        // 然后后面的数据要从大到小排列
        for (i = nums.size() - 1; i >= 1; --i) {
            if (nums[i] < nums[i - 1]) {
                // 寻找从i位置开始向后比i-1位置小但是最接近的值
                int flag = i;
                int dis = nums[i - 1] - nums[i]; // > 0
                for (int j = i; j < nums.size(); j++) {
                    if ((nums[i - 1] - nums[j] > 0) && (nums[i - 1] - nums[j] < dis)) {
                        dis = nums[i - 1] - nums[j];
                        flag = j;
                    }
                }
                // 交换
                swap(nums[i-1], nums[flag]);
                
                // i --> end()，降序排列
                // 局部冒泡排序
                for (int k = i; k < nums.size(); k++) {
                    for (int l = k + 1; l < nums.size(); l++) {
                        if (nums[k] < nums[l]) {
                            swap(nums[k], nums[l]);
                        }
                    }
                }
                break;
            }
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
        }
        return nums;
    }
int main()
{
    string n;
    cin>> n;
    vector<int> vec;
    for(auto ch : n){
        vec.push_back(ch - '0');
    }
    vector<int> res = previousPermuation(vec);
    string ans = "";
    for(auto i : res){
        ans += to_string(i);
    }
    if(n == ans || ans > n){
        cout<<"Not found"<<endl;
        return 0;
    }
    cout<< ans<< endl;
    return 0;
}
