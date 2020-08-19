/*功能：三个线程轮流依次打印abc*/
#include<bits/stdc++.h>
#include<thread>
#include<mutex>

using namespace std;

mutex mtx;
condition_variable cv;

char arr[] = {'a', 'b', 'c'};
char message = 'a';

void print(int i){
    for(int j = 0; j < 10; ++j){
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [=] {return message == arr[i];});
        cout<<arr[i]<<endl;
        message = arr[(i+ 1) % 3];
        lk.unlock();
        cv.notify_all();
    }
}

int main()
{
    thread t[3];
    for(int i = 0;i < 3; ++i){
        t[i] = thread(print, i);
    }
    for(int i = 0; i < 3; ++i){
        t[i].join();
    }
    return 0;
}
