/*���ܣ�*/
#include<bits/stdc++.h>

using namespace std;
template<class ...  T>
void func(T ... args)
{
    cout<<"num is"<<sizeof ...(args)<<endl;
}
template<class T>
//�ݹ���ֹ����
void print(T t)
{
    cout<<t<<endl;
}
//չ������
template<class T,class ... Args>
void print(T head,Args... args)
{
    cout<<head<<",";
    print(args...);
}

int main()
{
    print(1,2,3,4);
    return 0;
}
