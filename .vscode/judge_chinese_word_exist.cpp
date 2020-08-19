/*功能：
首先，要清楚汉字的编码格式，汉字是双字节的编码格式。

汉字第一个字节：是从0xB0开始编码；

汉字第二个字节：是从0xA1开始编码。

有了以上的了解就不难识别出是一个字符串中是够包含汉字了，只需要检验紧邻的两个字节即可，只需判断（第一个字节 >= 0xB0 && 第二个字节 >= 0xA1）就行。
*/
#include<bits/stdc++.h>

using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int first(unsigned char ch)
{
  if(ch>=0xb0&&ch<=0xf7)
   return 1;
  else
   return 0;
}
int second(unsigned char ch)
{
    if(ch>=0xa1&&ch<=0xfe)
   return 1;
  else
   return 0;
}
int check(const char* p)
{
  int i=0;
  for(i=0;i<strlen(p)-1;i++)
     if(first(p[i])&&second(p[i+1]))
       return 1;
return 0;
}
 
 
main()
{
const char* str= "中国";
check(str)?puts("there has character!"):puts("there has none character!");
 
}
