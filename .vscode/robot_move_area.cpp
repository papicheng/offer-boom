/*功能：
机器人移动范围
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
#include<iostream>

using namespace std;

int getSum(int n)
{

    int sum=0;
    while (n)
    {
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int move(int m,int n,int i,int j, int k,bool* flag)
{
    int count=0;
    int index=i*n+j;
    if(i>=0&&i<m&&j>=0&&j<n&&!flag[index]&&(getSum(i)+getSum(j)<=k))
    {
        flag[index]=true;
        count=1+
        move(m,n,i,j+1,k,flag)+
        move(m,n,i,j-1,k,flag)+
        move(m,n,i+1,j,k,flag)+
        move(m,n,i-1,j,k,flag);
    }
    return count;
}

int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    bool* flag=new bool[n*m];
    int count= move(m,n,0,0,k,flag);
    cout<<count;
    return 0;
}
