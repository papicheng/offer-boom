/*���ܣ�շת����������Լ��*/
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while( r){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int a , b;
    cin>> a >> b;
    cout<< gcd(a, b) << endl;
    return 0;
}
