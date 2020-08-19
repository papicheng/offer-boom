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

vector<vector<int>> groupThePeople1(vector<int>& groupSizes) {
    sort(begin(groupSizes),end(groupSizes));
    vector<vector<int>> vec_res;
    vector<int> vec_temp;
    int count=0;
    for(int i=0;i<groupSizes.size();)
    {
        int t=count;
        for(int j=0;j<groupSizes[i];++j)
        {
            vec_temp.emplace_back(groupSizes[t+j]);
            count++;
        }
        vec_res.push_back(vec_temp);
        vec_temp.clear();
        i=count;
    }
    return vec_res;
}

// class Solution {
// public:
//     vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
//         vector<int> mp[groupSizes.size()+1];
//         vector<vector<int>> v;
//         for(int i=0;i<groupSizes.size();i++){
//             mp[groupSizes[i]].push_back(i);
//             if(mp[groupSizes[i]].size()==groupSizes[i]) {
//                 v.push_back(mp[groupSizes[i]]);
//                 mp[groupSizes[i]].clear();
//             }
//         }
//         return v;
//     }
// };
vector<vector<int>> groupThePeople_zhulin(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        vector<vector<int>> v;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
            if(mp[groupSizes[i]].size()==groupSizes[i]) {
                v.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
            }
        }
        return v;
    }

//这是第一次提交的版本
vector<vector<int>> groupThePeople_zhulin1(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();++i)
        {
            mp[groupSizes[i]].push_back(i);
        }
        auto iter=mp.begin();
        vector<int> tmp;
        vector<vector<int>> vecres;
        while(iter!=mp.end())
        {
            int i=0;
            int len=(*iter).first;
            while(i<(*iter).second.size())
            {
                int j=i,k=0;
                while(k<len)
                {
                    tmp.push_back((*iter).second[j]);
                    ++j;
                    ++k;
                }
                i=j;
                vecres.push_back(tmp);
                tmp.clear();
            }
            iter++;
        }
        return vecres;
    }
// int main()
// {
//     vector<int> groupSizes={2,1,3,3,3,2};
//     vector<vector<int>> vec_res=groupThePeople(groupSizes);
//     for(auto i:vec_res)
//     {
//         cout<<"[";
//         for(auto j:i)
//         {
//             cout<<j<<",";
//         }
//         cout<<"]";
//     }
//     return 0;
// }
int main()
{
    char(*ch)[10];
    char tmp[10]="dfd";
    char str[10]="dggfd";
    ch=&tmp;
    ch=&str;
    return 0;
}