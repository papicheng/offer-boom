/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

char* strA(){
    char str[] = "hello world";
    char src[] = "stop";
    strcpy(str, "stop");
    return str;
}

void getmemory(char * p){
    p = (char*) malloc(100);
    const char* stra = strA();
    printf("%s\n", stra);
    strcpy(p, stra);
}

int main()
{
    char *str = NULL;
    getmemory(str);
    printf("%s\n", str);
    free(str);
    return 0;
}
