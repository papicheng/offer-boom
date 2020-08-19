/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

int strcmp_test(const char* str1, const char* str2){
    assert(str1 != NULL && str2 != NULL);
    while(*str1 != NULL && *str2 != NULL && *str1 == *str2){
        str1++;
        str2++;
    }
    if(*(unsigned char*) str1 < *(unsigned char*) str2){
        return -1;
    }
    else if(*(unsigned char*) str1 > *(unsigned char*) str2){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    const char* str1 = "12345";
    const char* str2 = "12345";
    cout<< strcmp_test(str1, str2)<<endl;
    return 0;
}
