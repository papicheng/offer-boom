/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

int strlen_test(char* str){
    int i = 0 ;
    while(*str != '\0'){
        i++;
        str++;
    }
    return i;
}

int main()
{
    char* str = "1234";
    cout<<strlen_test(str)<<endl;
    cout<<str<<endl;
    return 0;
}
