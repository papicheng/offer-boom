/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

struct A{
    virtual void func();
};
struct B:A{};
struct F{};
struct D:A, F{
    void func();//meant to declare a new function but 
};//accidentally overrides A::func()

struct G{
    virtual int func(int n){
        return n;
    }
};
struct  H:G
{
    virtual double func(double n)//accidentally create a new virtual function
    {
        return n;
    }
};



int main()
{
    H *p = new H;
    cout<< p->func(5) << endl;
    cout<< p->func(5.5) << endl;
    return 0;
}
