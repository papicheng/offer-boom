#include<iostream>
#include<vector>
 using namespace std;
 int mian()
 {
	int a=12;
	cout<<"hello world"<<endl;
	return 0;
 }
 
int getNum(int n)
{
	int sum=0;
	while(n)
	{
		int tmp=n%10;
	sum=sum+tmp*tmp;
	n/=10;
	}
	return sum;
}

bool isHappy(int n)
{
	int slow = n,fast=n;
	do{
		slow=getNum(slow);
		fast=getNum(fast);
		fast=getNum(fast);
	}while(slow!=fast);
	return slow==1;
}