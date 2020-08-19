/*¹¦ÄÜ£ºswap*/
#include<iostream>

using namespace std;

int main()
{
    int a=1,b=4;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a= "<<a<<"  "<<"b= "<<b<<endl;
    return 0; 
}
