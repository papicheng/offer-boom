/*功能：*/
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
        int len=s.size();
        bool* flag=new bool[len+1];
        flag[0]=true;
        unordered_set<string> us;
        for(int i=0;i<wordDict.size();++i)
        {
            us.insert(wordDict[i]);
        }
        for(int i=0;i<len;++i)
        {
            for(int j=i;j<len;++j)
            {
                if(flag[i]&&us.find(s.substr(i,j-i+1))!=us.end())
                {
                    flag[i+1]=true;
                    break;
                }
            }
        }
        return flag[len];
    }

int main()
{
    string s="1234";
    string a=s.substr(0,2);
    cout<<a<<endl;
    return 0;
}
