/*���ܣ�O(n) ȡ��������ÿ��Ԫ���ұߵ�һ���������Ԫ��*/
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
    stack<int> st;//����û���ҵ��ұߵ�һ���������
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
