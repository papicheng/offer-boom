/*���ܣ�
���ȣ�Ҫ������ֵı����ʽ��������˫�ֽڵı����ʽ��

���ֵ�һ���ֽڣ��Ǵ�0xB0��ʼ���룻

���ֵڶ����ֽڣ��Ǵ�0xA1��ʼ���롣

�������ϵ��˽�Ͳ���ʶ�����һ���ַ������ǹ����������ˣ�ֻ��Ҫ������ڵ������ֽڼ��ɣ�ֻ���жϣ���һ���ֽ� >= 0xB0 && �ڶ����ֽ� >= 0xA1�����С�
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
const char* str= "�й�";
check(str)?puts("there has character!"):puts("there has none character!");
 
}
