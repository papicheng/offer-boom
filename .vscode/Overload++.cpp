/*���ܣ�*/
#include<bits/stdc++.h>

using namespace std;

class length{
    public:
    int len;
    public:
    //ǰ׺++������
    length operator++();
};
length length::operator++(){
    cout<<"ǰ׺++" <<endl;
    len++;
    return *this;
}
length length::operator++(int){
    cout<< "��׺++"<< endl;
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
