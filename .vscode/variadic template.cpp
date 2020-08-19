/*功能：*/
#include<bits/stdc++.h>

using namespace std;
template<class ...  T>
void func(T ... args)
{
    cout<<"num is"<<sizeof ...(args)<<endl;
}
template<class T>
//递归终止函数
void print(T t)
{
    cout<<t<<endl;
}
//展开函数
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
