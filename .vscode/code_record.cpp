/*���ܣ�*/
#include<iostream>
#include<time.h>
using namespace std;

//����ĳ�����Դ�0....n-1������ȸ��ʵ����m�����ظ��������������Ǽ���nԶ����m
//����
// �����forѭ��ѭ��n�Σ�������������ʱ�����i,��֪�����m����ֵͬ��Ҫ�������㣬��Ϊÿ������Ķ���iֵ����iֵÿ�ζ��ǲ�һ���ģ�m--��֤�˳����������m��ֵ���ֹͣѭ����
// ��i=0ʱ��rand()%(n-i)��ȡֵ��ΧΪ0��n-1����n��������ʱҪ���0ֻ��Ҫrand()%(n-i)С��m����i=0������ĸ���Ϊm/n;
// ��i=1ʱ��rand()%(n-i)��ȡֵ��ΧΪ0��n-2����n-1��������i=0û�б��������m--δ��ִ�У���ʱi=1������ĸ���Ϊm/(n-1)����i=0�Ѿ�������ˣ���m��Ϊm-1����ʱi=1������ĸ���Ϊ(m-1)/(n-1)���ɸ����۵�֪ʶ����֪��ʱi=1������ĸ���Ϊ
// P=(1-m/n)*(m/(n-1))+m/n*((m-1)/(n-1))=m/n���Դ����ƣ���֪ÿ����������ĸ��ʶ�Ϊm/n
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
//prim�����Ĺ����Ƿֽ�������,n��2��ʼ
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
