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
    shared_ptr<Person> p1(new Person(1));// Person(1)�����ü���Ϊ1
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    shared_ptr<Person> p2 = make_shared<Person>(2);
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    cout<< "p2.use_count:"<<p2.use_count()<<endl;
    p1.reset(new Person(3));// ���������¶���Ȼ�����ü�����1�����ü���Ϊ0��������Person(1)
                            // ����¶����ָ�뽻������ָ��
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    shared_ptr<Person> p3 = p1;//����p1��p3ͬʱָ��Person(3)��Person(3)�����ü���Ϊ2
    cout<< "p1.use_count:"<< p1.use_count()<<endl;
    cout<< "p3.use_count:"<< p3.use_count()<<endl;
    p1.reset();//Person(3)�����ü���Ϊ1
    p3.reset();//Person(3)�����ü���Ϊ0������Person(3)
    return 0;
}