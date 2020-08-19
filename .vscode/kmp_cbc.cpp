#include <bits/stdc++.h>

using namespace std;


vector<int> getNext(string subArr)
{
    vector<int> next(subArr.size());
    if(subArr.size()==1){
        next.emplace_back(-1);
        return next;
    }
    next[0]=-1;
    next[1]=0;
    int pos=2;
    int cn=0;
    while (pos<next.size())
    {
        if(subArr[pos-1]==subArr[cn])
        {
            next[pos++]=++cn;
        }
        else if(cn>0)
        {
            cn=next[cn];
        }
        else
        {
            next[pos++]=0;
        }
        return next;
    }
    
}
int getIndexOf(string s,string m)
{
    if(s==""||m==""||m.size()<1||s.size()<m.size())
    {
        return -1;
    }
    int si=0;
    int mi=0;
    vector<int> next=getNext(m);
    while(si<s.size()&&mi<m.size())
    {
        if(s[si]==m[mi])
        {
            si++;
            mi++;
        }
        else if(next[mi]==-1)
        {
            si++;
        }
        else
        {
            mi=next[mi];
        }
    }
    return mi==m.size()?si-mi:-1;
}

int main()
{
    string str = "abcabcababaccc";
    string match = "ababa";
    int ans=getIndexOf(str,match);
    cout<<ans<<endl;
    return 0;
}
