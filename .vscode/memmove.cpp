/*���ܣ�*/
#include<bits/stdc++.h>

using namespace std;

void* memmove_test(void* dest, const void* src, size_t count){
    //�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
    assert(src != NULL && dest != NULL);
    char* tmp_dest = (char*) dest;
    const char* tmp_src = (const char*)src;
    if(tmp_src < tmp_dest)//��src��ַС��dest��ַʱ����ͷ���п���
    {
        while(count--){
            *tmp_dest++ = *tmp_src++;
        }
    }
    else if(tmp_dest < tmp_src){
        //��src��ַ����dest��ַʱ���Ӻ���ǰ���п���
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
