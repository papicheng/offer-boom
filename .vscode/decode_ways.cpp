/*功能：
链接：https://www.nowcoder.com/questionTerminal/a2539eb0a9ec4c54a055091e706072cc
来源：牛客网

一条仅包含字母‘A’-‘Z’的消息用下列的方式加密成数字
'A' -> 1?'B' -> 2?...?'Z' -> 26
现在给出加密成数字的密文，请判断有多少种解密的方法
例如：
给出的密文为“12”，可以解密为"AB"(1 2) 或者"L"(12).
所以密文"12"的解密方法是2种.
*/
#include<iostream>

using namespace std;


int numDecodings(string s)
{
    if(s.size()==0) return 0;
    if(s[0]=='0') return 0;
    int len=s.size();
    int *dp=new int [len+1]();
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=len;++i)
    {
        if(s[i-1]>'1'&&s[i-1]<='9')
            dp[i]+=dp[i-1];
        if(s[i-2]=='1'||(s[i]-2=='2'&&s[i-1]>='0'&&s[i-1]<='6'))
            dp[i]+=dp[i-2];
    }
    return dp[len];
}

int main()
{
    int res=numDecodings("12");
    cout<<res<<endl;
    return 0;
}
