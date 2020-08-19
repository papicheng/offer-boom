/*���ܣ�
���ӣ�https://www.nowcoder.com/questionTerminal/a2539eb0a9ec4c54a055091e706072cc
��Դ��ţ����

һ����������ĸ��A��-��Z������Ϣ�����еķ�ʽ���ܳ�����
'A' -> 1?'B' -> 2?...?'Z' -> 26
���ڸ������ܳ����ֵ����ģ����ж��ж����ֽ��ܵķ���
���磺
����������Ϊ��12�������Խ���Ϊ"AB"(1 2) ����"L"(12).
��������"12"�Ľ��ܷ�����2��.
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
