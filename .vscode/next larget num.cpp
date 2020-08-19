/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;



vector<int> nextLarget(vector<int> a){
    stack<int> s;
    vector<int>ans(a.size());
    for(int i = 0; i < a.size();++i){
        while(s.size() && a[s.top()] < a[i]){
            auto top = s.top();
            s.pop();
            ans[top] = a[i];
        }
        s.push(i);
    }
    return ans;
}
void print(vector<int> a){
    for(auto i :a ){
        cout<<i<<" ";
    }
}
int main()
{
    vector<int> a = {1,7,5,1,9,2,5,1};
    vector<int> res = nextLarget(a);
    print(res);
    return 0;
}
