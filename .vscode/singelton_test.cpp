#include <iostream>
#include <process.h>
#include <windows.h>
using namespace std;
 
class Singelton{
private:
    Singelton(){
        m_count ++;
        printf("Singelton begin\n");
        Sleep(1000);                            // ��sleepΪ�˷Ŵ�Ч��
        printf("Singelton end\n");
    }
    static Singelton *single;
public:
    static Singelton *GetSingelton();
    static void print();
    static int m_count;
};
 
Singelton *Singelton::single = nullptr;
int Singelton::m_count = 0;
 
Singelton *Singelton::GetSingelton(){
    if(single == nullptr){
        single = new Singelton;
    }
    return single;
}
 
void Singelton::print(){
    cout<<"m_count: "<<m_count<<endl;
}
// �ص�����
void threadFunc(void *p){
    DWORD id = GetCurrentThreadId();        // ����߳�id
     cout<<"id: "<<id<<endl;
    Singelton::GetSingelton()->print();      // ���캯�������ʵ�������þ�̬��Ա����
}
 
int main(int argc, const char * argv[]) {
    int threadNum = 3;
    HANDLE threadHdl[100];
     
    // ����3���߳�
    for(int i = 0; i<threadNum; i++){
        threadHdl[i] = (HANDLE)_beginthread(threadFunc, 0, nullptr);
    }
     
    // �������̵ȴ����е��߳̽��������˳�
    for(int i = 0; i<threadNum; i++){
        WaitForSingleObject(threadHdl[i], INFINITE);
    }
    cout<<"main close"<<endl;                 // ��֤�������Ƿ�������˳�
    return 0;
}