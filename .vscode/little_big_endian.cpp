/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;


int main()
{
    unsigned int x = 1;
    if(1 == *(unsigned char*) &x){
        cout<<"little endian" <<endl;
    }
    else{
        cout<<"big endian" <<endl;
    }
    return 0;
}
