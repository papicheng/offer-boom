//�����ַ������������ĸ�������֣����Ӧλ�ñ���Ϊ1������Ϊ0������һ��01�����Ƚϣ������ƶ�

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