#include <bits/stdc++.h>
using namespace std;

class A{
    public:
    virtual void say(int x){
        cout<<x<<endl;
    }
};
class B : public A{
    public:
    void say(int x){
        cout << this << endl;
        cout << x << endl;
        cout <<"class B" << endl;
    }
};

typedef void (*func)(void* , int x);
int main(){
    cout<< sizeof(B) <<endl;
    B b;
    b.say(123);
    A &a = b;
    A *c = &b;
    a.say(123);
    c->say(123);
    ((func **)(&b))[0][0](&b, 123);
    return 0;
}