/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

char* strcat_test(char* strDest, const char* strSrc){
    assert(strDest != NULL && strSrc != NULL);
    char* address = strDest;
    while(*strDest != NULL && *strDest != '\0') strDest++;
    while(*strSrc != '\0'){
        *strDest = *strSrc;
        strDest++;
        strSrc++;
    }
    *strDest = '\0';
    return address;
}

int main()
{
    char* strDest = "1234";
    const char* strSrc = "567";
    cout << strcat_test(strDest, strSrc) <<endl;
    return 0;
}
