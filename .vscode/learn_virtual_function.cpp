//Ðéº¯Êý ´¿Ðéº¯Êý

#include<bits/stdc++.h>

using namespace std;

unordered_set<string> se;

class A{
    public:
    virtual void out1() = 0;
    virtual ~A(){
        cout<< "~A" << endl;
    }
    virtual void out2(){
        cout<<"A out2" << endl;
    }
    void out3(){
        cout<< "A out3" << endl;
    }
}; 
class B : public A{
    public:
    virtual ~B(){
        cout<< "~B" << endl;
    }
    void out1(){
        cout<<"B out1" <<endl;
    }
    void out2(){
        cout<<"B out2" << endl;
    }
    void out3(){
        cout<<"B out3" << endl;
    }
};

int main(){
    A* ab = new B;
    ab->out1();
    ab->out2();
    ab->out3();

    B* bb = new B;
    bb->out1();
    bb->out2();
    bb->out3();

    // delete ab;
    // delete bb;

    B b;
    b.out1();
    b.out2();
    b.out3();

    return 0;
}
