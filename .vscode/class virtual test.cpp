/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

class A{
    void print(){
        cout<<"A" << endl;
    }
};
class B : public A{
    void print(){
        cout<<"B" << endl;
    }
};
class C : public C{
    void print(){
        cout<<"C" <<endl;
    }
};


int main()
{
    return 0;
}
