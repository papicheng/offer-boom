/*功能：
找出多叉树的公共祖先
*/
#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> invert_tree(vector<vector<int>> node_data_list){
    map<int,vector<int>> mp;
    for(auto i:node_data_list){
        mp[i[1]].push_back(i[0]);
    }
    for(auto& i:mp){
        reverse(i.second.begin(),i.second.end());
    }
    stack<int> s;
    s.push(0);
    vector<vector<int>> res;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        vector<int> v=mp[t];
        for(int i=0;i<v.size();i++){
            s.push(v[i]);
            res.push_back({v[i],t});
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> v = {{1,0},{2,1},{5,2},{6,5},{7,5},{3,1},{4,1}};
    vector<vector<int>> res = invert_tree(v);
    for(auto i: res){
        cout<< i[0] << ","<<i[1]<<endl;
    }
    return 0;
}
