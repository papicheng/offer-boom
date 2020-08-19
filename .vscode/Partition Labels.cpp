/*功能：
763. 划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]
解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
思路：用map统计出现的次数，再从左到右遍历字符串，字符每出现一次就减一，直到左边的子串对应的map里的数都为0为止，然后统计子串的长度。
*/
#include<bits/stdc++.h>

using namespace std;

static const auto ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.size() == 0 || S.size() == 1) return {int(S.size())};
        map<char, int> mp;
        for(int i = 0; i < S.size(); ++i){
            mp[S[i]]++;
        }
        vector<int> vecres;
        int start = 0, left = 0, right = 0;
        bool flag=1;//初次进入
        while(right < S.size()){
            while(flag || left < right){
                while(mp[S[left]] != 0){
                    mp[S[right++]]--;
                }
                flag = 0;
                ++left;
            }
            vecres.emplace_back(left-start);
            start = left;
            flag = 1;
        }
       return vecres;
    }
};

class SolutionZhulin {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0]<b[0];
    }
    vector<int> partitionLabels(string S) {
        vector<vector<int> > f(26, vector<int>(2, 0));
        int n=S.size();
        for(int i=0;i<n;i++){
            if(f[S[i]-'a'][0]==0) f[S[i]-'a'][0]=i+1;
            if(f[S[n-1-i]-'a'][1]==0) f[S[n-1-i]-'a'][1]=n-1-i+1;
        }
        sort(f.begin(),f.end(),cmp);
        vector<int> v;
        for(int i = 1; i <26; ++i){
            if(f[i-1][0]==0) continue;
            if(f[i][0] <f[i-1][1]){
                f[i][0] =f[i-1][0];
                if(f[i-1][1]>f[i][1]) f[i][1]=f[i-1][1];
            }
            else v.push_back(f[i-1][1]-f[i-1][0]+1);
        }
        v.push_back(f[25][1]-f[25][0]+1);
        return v;
    }
};

int main()
{
    string S = "ababcbacadefegdehijhklij";
    Solution so;
    vector<int> vecres=so.partitionLabels(S);
    for(auto i:vecres)
    {
        cout<<i<<" ";
    }
    return 0;
}
