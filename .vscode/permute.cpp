/*功能：全排列*/
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& res, int len, int index){
    if(index == len){
        res.push_back(nums);
    }
    for(int i = index; i < len; ++i){
        swap(nums[i], nums[index]);
        dfs(nums, res, len, index + 1);
        swap(nums[i], nums[index]);
    }
}
void dfs_alpha(string& str, vector<string>& res, int len, int index){
    if(index == len){
        res.push_back(str);
    }
    for(int i = index ; i <  len; ++i){
        swap(str[i], str[index]);
        dfs_alpha(str, res, len, index + 1);
        swap(str[i], str[index]);
    }
}
void print(vector<vector<int>> res){
    for(auto i : res){
        for(auto j : i){
            cout<<j<<"  ";
        }
        cout<<endl;
    }
}
void print_vec(vector<string> vec){
    for(auto str : vec){
        cout<<str<<endl;
    }
}
int main()
{
    vector<int> nums = {1,3,5};
    vector<vector<int>> res;
    dfs(nums, res, nums.size(), 0);
    print(res);

    string str = "abc";
    vector<string> vec;
    dfs_alpha(str, vec, str.size(), 0);
    print_vec(vec);

    return 0;
}
