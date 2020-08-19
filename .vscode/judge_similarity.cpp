//输入字符串，如果是字母或者数字，则对应位置编码为1，否则为0，如另一个01串做比较，求相似度

#include<iostream>

using namespace std;

int main()
{
	string a,b;
    // cin>>a>>b;
    a="@!%12dgsa";
    b="010111100";
    string c="";
    for(int i=0;i<a.size();++i)
    {
        if(isalnum(a[i]))
            c+="1";
        else
            c+="0";
    }
    int count=0;
    for(int i=0;i<b.size();++i)
    {
        if(b[i]==c[i])
            ++count;
    }
    float res=float(count)/(float(b.size()))*100;
    printf("%.2f%%",res);
    return 0;
}