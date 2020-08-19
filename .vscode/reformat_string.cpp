/*���ܣ�*/
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

// ����һ����������ֺ���ĸ���ַ��� s�����е���ĸ��ΪСдӢ����ĸ��

// ���㽫���ַ������¸�ʽ����ʹ���������������ַ������Ͷ���ͬ��Ҳ����˵����ĸ����Ӧ�ø������֣������ֺ���Ӧ�ø�����ĸ��

// ���㷵�� ���¸�ʽ���� ���ַ���������޷���Ҫ�����¸�ʽ�����򷵻�һ�� ���ַ��� ��

// ��Դ�����ۣ�LeetCode��
// ���ӣ�https://leetcode-cn.com/problems/reformat-the-string
// ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

string reformat(string s) {
    string digit(""),alph("");
    for(int i=0;i<s.size();++i)
    {
        if(isalpha(s[i]))
        {
            alph+=s[i];
        }
        else if(isdigit(s[i]))
        {
            digit+=s[i];
        }
    }
    int d_len=digit.size();
    int a_len=alph.size();
    string longstr,shortstr;
    if(abs(d_len-a_len)<=1)
    {
        if(d_len>a_len)
        {
            longstr=digit;
            shortstr=alph;
        }
        else
        {
            longstr=alph;
            shortstr=digit;
        }
    }
    string res("");
    for(int i=0;i<shortstr.size();++i)
    {
        res+=longstr[i];
        res+=shortstr[i];
    }
    if(longstr.size()>shortstr.size())
    {
        res+=longstr[longstr.size()-1];
    }
    return res;
}
int main()
{
    string input;
    cin>>input;
    string res;
    res=reformat(input);
    cout<<res;
    return 0;
}
