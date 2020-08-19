/*功能：
由前序后序求中序
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> v;
void deal(int pl, int pr, vector<int>& pre, int sl, int sr, vector<int>& suf){
    if(pl > pr) return;
    if(pl == pr){
        v.push_back(pre[pl]);
        return;
    }
    int pos = -1;
    for(int i = sl; i <= sr; ++i){
        if(suf[i] == pre[pl + i]){
            pos = i;
        }
    }

    deal(pl + 1, pos - sl + pl + 1, pre, sl, pos,  suf);
    v.push_back(pre[pl]);
    deal(pos - sl + pl + 2, pr, pre, pos + 1, sr - 1, suf);
}
vector<int> solve(int n, vector<int>& pre, vector<int>& suf){
    deal(0, n - 1, pre, 0, n - 1, suf);
    return v;
}
int main()
{
    
    return 0;
}
