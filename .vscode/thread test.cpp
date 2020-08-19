

#define CHOOSE 1
#define ONE 1
#define TWO 2
#define THREE 3

#if (CHOOSE == ONE)
#include <iostream>

#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

#define NUM_THREADS 5

void say_hello(int id){
    while (1)
    {
        _sleep(1000);
        mtx.lock();
        cout<<"线程# "<< id <<endl;
        mtx.unlock();
    } 
}
void testPrint(string str){
    while (1)
    {
        _sleep(2000);
        cout<< str <<endl;
    }
    
}
int main(){
    thread tids[NUM_THREADS];    
    for(int i = 0; i < NUM_THREADS - 1; ++i){
        tids[i] = thread(say_hello,  i + 1);
    }
    tids[4] = thread(testPrint,"++++");
    for (auto& th : tids) th.join();

    pthread_exit(NULL);
    return 0;
}

#elif (CHOOSE == TWO)


#include <iostream>

#include <thread>

std::thread::id main_thread_id = std::this_thread::get_id();

void hello()  
{
    std::cout << "Hello Concurrent World\n";
    if (main_thread_id == std::this_thread::get_id())
        std::cout << "This is the main thread.\n";
    else
        std::cout << "This is not the main thread.\n";
}

void pause_thread(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";
}

int main() {
    std::thread t(hello);
    std::cout << t.hardware_concurrency() << std::endl;//可以并发执行多少个(不准确)
    std::cout << "native_handle " << t.native_handle() << std::endl;//可以并发执行多少个(不准确)
    t.join();
    std::thread a(hello);
    a.detach();
    std::thread threads[5];                         // 默认构造线程

    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; ++i)
        threads[i] = std::thread(pause_thread, i + 1);   // move-assign threads
    std::cout << "Done spawning threads. Now waiting for them to join:\n";
    for (auto &thread : threads)
        thread.join();
    std::cout << "All threads joined!\n";
}

#endif