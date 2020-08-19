/*功能：*/
#include<bits/stdc++.h>

using namespace std;

class length{
    public:
    int len;
    public:
    //前缀++的声明
    length operator++();
};
length length::operator++(){
    cout<<"前缀++" <<endl;
    len++;
    return *this;
}
length length::operator++(int){
    cout<< "后缀++"<< endl;
    length tmp = *this;
    len++;
    return tmp;
}

int main()
{
    length l;
    l.len = 0;
    ++l.len;
    cout<<l.len<<endl;
    return 0;
}
