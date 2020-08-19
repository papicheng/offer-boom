/*功能：*/
#include<iostream>
#include<time.h>
using namespace std;

//下面的程序可以从0....n-1中随机等概率的输出m个不重复的数。这里我们假设n远大于m
//解析
// 由这个for循环循环n次，且在满足条件时才输出i,可知，输出m个不同值的要求已满足，因为每次输出的都是i值，而i值每次都是不一样的，m--保证了程序在输出了m个值后就停止循环。
// 在i=0时，rand()%(n-i)的取值范围为0到n-1，共n个数，此时要输出0只需要rand()%(n-i)小于m，故i=0被输出的概率为m/n;
// 在i=1时，rand()%(n-i)的取值范围为0到n-2，共n-1个数，若i=0没有被输出，则m--未被执行，此时i=1被输出的概率为m/(n-1)，若i=0已经被输出了，则m变为m-1，此时i=1被输出的概率为(m-1)/(n-1)；由概率论的知识，可知此时i=1被输出的概率为
// P=(1-m/n)*(m/(n-1))+m/n*((m-1)/(n-1))=m/n；以此类推，可知每个数被输出的概率都为m/n
void knuth(int n, int m)
{ 
    srand((unsigned int)time(0)); 
    for (int i = 0; i < n; i++) { 
        if (rand()%(n-i)<m) { 
            cout << i << endl;
            m--;
        }
     }
}
//prim函数的功能是分解质因数,n从2开始
void prim(int m, int n)
 {
     if (m >= n)
     {
         while (   m%n     ) n++;
         m/=n;
         prim(m, n);
         cout << n << endl;
     }
 }

void example(char acWelcome[]){
    printf("%d",sizeof(acWelcome));
    return;
}
int main(){
    char acWelcome[]="Welcome to Huawei Test";
    example(acWelcome);
    return 0;
}
