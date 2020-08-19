/*功能：*/
#include<bits/stdc++.h>

using namespace std;

void* memmove_test(void* dest, const void* src, size_t count){
    //判断dest指针和src指针是否为空，若为空抛出异常
    assert(src != NULL && dest != NULL);
    char* tmp_dest = (char*) dest;
    const char* tmp_src = (const char*)src;
    if(tmp_src < tmp_dest)//当src地址小于dest地址时，从头进行拷贝
    {
        while(count--){
            *tmp_dest++ = *tmp_src++;
        }
    }
    else if(tmp_dest < tmp_src){
        //当src地址大于dest地址时，从后往前进行拷贝
        tmp_src += count - 1;
        tmp_dest += count - 1;
        while(count--){
            *tmp_dest-- = *tmp_src--;
        }
    }
    return dest;
}

int main()
{
    
    return 0;
}
