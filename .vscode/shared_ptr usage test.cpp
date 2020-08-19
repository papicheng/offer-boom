#include <iostream>
#include <future>
#include <thread>

using namespace std;
class Person
{
public:
    Person(int v) {
        value = v;
        std::cout << "Cons" <<value<< std::endl;
    }
    ~Person() {
        std::cout << "Des" <<value<< std::endl;
    }

    int value;

};

int main()
{
    shared_ptr<Person> p1(new Person(1));// Person(1)的引用计数为1
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    shared_ptr<Person> p2 = make_shared<Person>(2);
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    cout<< "p2.use_count:"<<p2.use_count()<<endl;
    p1.reset(new Person(3));// 首先生成新对象，然后引用计数减1，引用计数为0，故析构Person(1)
                            // 最后将新对象的指针交给智能指针
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    shared_ptr<Person> p3 = p1;//现在p1和p3同时指向Person(3)，Person(3)的引用计数为2
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    cout<< "p3.use_count:"<< p3.use_count()<<endl;
    p1.reset();//Person(3)的引用计数为1
    p3.reset();//Person(3)的引用计数为0，析构Person(3)
    return 0;
}