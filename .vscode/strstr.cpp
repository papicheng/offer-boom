/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

char* strstr_test(char* str, const char* sub){
    for(int i = 0; i < strlen(str);i++){
        char* p = &str[i];
        char* q = const_cast<char*>(sub);
        while(*p == *q){
            p++;
            q++;
            if(*q == '\0'){
                return &str[i];
            }
        }
    }
    return NULL;
}

int main()
{
    const char haystack[20] = "RUNOOB";
    const char needle[10] = "NOOB";
    char* ret;
    ret = strstr_test(const_cast<char*>(haystack), needle);
    cout<< "substr:" << ret<<endl;
    return 0;
}
