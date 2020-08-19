/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count = 0;
    void dfs(int d, int f, int target){
        if(target < 0 || d < 1 ) return;
        if(target == 0) {
            ++count;
            return;
        }
        for(int i = 1; i < f; ++i){
            dfs(d, f, target - i);
            dfs(d - 1, f, target);
            target += i;
        }
    }
    int numRollsToTarget(int d, int f, int target) {
        // dfs(d, f, target);
        // return count;
        int count =0;
        for(int i = 0; i < d; ++i){
            for(int j = 0; j < f; ++j){
                if
            }
        }
    }
};
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int ccc=1000000007;
        map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<d;i++){
            map<int,int> temp;
            for(int j=1;j<f+1;j++){
                for(auto k:mp){
                    temp[k.first+j]=(temp[k.first+j]+k.second)%ccc;
                }
            }
            swap(mp,temp);
            temp.clear();
        }
        return mp[target];
    }
};
int main()
{
    int d = 2, f = 6, target = 7;
    Solution s; 
    int res = s.numRollsToTarget(d, f, target);
    cout<<res<<endl;
    return 0;
}


