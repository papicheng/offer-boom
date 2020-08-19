#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
string s;
int main()
{
   cin>>n;
     cin>>s;
     int cnt=1;
     for(int i=0;i<n-1;i++)
        if(s[i]!=s[i+1])
        cnt++;
      printf("%d\n",cnt<n-1?cnt+2:n);
}