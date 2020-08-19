/*功能：*/
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

// 给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

// 请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

// 请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reformat-the-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
