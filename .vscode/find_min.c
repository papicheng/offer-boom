//求最小数
#include<stdio.h>
#include<stdlib.h>

int Min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int a=0,b=0;
    scanf("%d",&a);
    scanf("%d",&b);
    int result=Min(a,b);
    printf("Minimal number is %d",result);
    return 0;
}