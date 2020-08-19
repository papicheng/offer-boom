/*功能：
二进制中有多少个1
把一个32-bit整型转成二进制，其中包含多少个1，比如5的二进制表达是101，其中包含2个1
*/
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int bit=1,count=32,res=0;
    while (count)
    {
        if(n&bit)
            ++res;
        bit=bit<<1;
        --count;
    }
    cout<<res;
    return 0;
}
