/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

void *memcpy(void *dest, const void *src, size_t count){
    char *d;
    const char *s;
    if(dest > src + count || dest < src){
        d = (char*)dest;
        s = (char*)src;
        while (count--){
            *d++ = *s++;
        }
    }
    else{
        //overlap
        d = (char*)(dest + count - 1);
        s = (char*)(src + count - 1);
        while (count--){
            *d-- = *s--;
        }
    }
    return dest;
}


int main()
{
    char str[] = "hello";
    char* dest = (char*) malloc(100);
    memcpy(dest, str, strlen(str) + 1);
    printf("%s\n", dest);
    return 0;
}
