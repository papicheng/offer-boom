/*功能：O(n) 取得数组中每个元素右边第一个比它大的元素*/
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


vector<int> findNum(vector<int>& nums)
{
    stack<int> st;//保存没有找到右边第一个最大的序号
    int i=0;
    vector<int> vecres(nums.size());
    while (i<nums.size())
    {
        if(!st.empty()&&nums[i]>nums[st.top()])
        {
            vecres[st.top()]=nums[i];
            st.pop();
        }
        else
        {
            st.push(i++);
        }
    }
     while (!st.empty())
     {
         vecres[st.top()]=-1;
         st.pop();
     }
     return vecres;
}
int main()
{
    vector<int> a={6,8,9,2,3,5,6};
    vector<int> b=findNum(a);
    for(auto i:b)
    {
        cout<<i<<" ";
    }
    return 0;
}
