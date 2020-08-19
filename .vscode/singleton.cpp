#include<iostream>
using namespace std;
class Singleton{
	public:
	static Singleton * getInstance(int temp){
		if(m_Instance == NULL){
			m_Instance = new Singleton(temp);
		}
		return m_Instance;
	}
	static void DestroyInstance(){
		if(m_Instance != NULL){
			delete m_Instance;
			m_Instance = NULL;
		}
	}
	int getTest(){return m_test;}

	private:
	int m_test;
	Singleton(int temp) {m_test = temp;}
	static Singleton *m_Instance;
};

Singleton * Singleton::m_Instance = NULL;

int main(int argc, char * argv[]){
	Singleton *singletonObj = Singleton::getInstance(10);
	Singleton *singletonObj2 = Singleton::getInstance(11);
	cout<<singletonObj->getTest()<<endl;
	cout<<singletonObj2->getTest()<<endl;

	Singleton::DestroyInstance();
	return 0;
}
//懒汉模式
class single_lanhan{
	private:
	single_lanhan(){}
	~single_lanhan(){}
	public:
	static single_lanhan* getinstance();
};
single_lanhan* single_lanhan::getinstance(){
	static single_lanhan obj;
	return & obj;
}
//饿汉模式
class single_ehan{
	private:
	static single_ehan* p;
	single_ehan(){}
	~single_ehan(){}
	public:
	static single_ehan* getinstance();
};
