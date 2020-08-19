#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Sharedptr {
public:
	//�ղ������죬 ��ָ��
	Sharedptr():count(0), ptr((T*) 0){}
	//���캯�� count ����new����
	Sharedptr(T* p) : count(new int(1)), ptr(p){}
	//�������캯����ʹ�����ô�����һ
	Sharedptr(Sharedptr<T>& other) : count(&(++ *other.count)), ptr(other.ptr){}
	//����operator*��operator->ʵ��ָ�빦��
	T* operator->() { return ptr;}
	T& operator*() { return *ptr; }
	//����operator =
	//���ԭ����sharedptr�Ѿ��ж������������ö��������һ���ж������Ƿ�Ϊ�㣨�Ƿ����delete),Ȼ���µ����ö��������һ
	Sharedptr<T>& operator = (Sharedptr<T>& other) {
		if (this == &other) return *this;
		++* other.count;
		if (this->ptr && 0 == -- * this->count) {
			delete count;
			delete ptr;
			cout << "delete ptr =" << endl;
		}
		this->ptr = other.ptr;
		this->count = other.count;
		return *this;
	}
	//�������� ʹ�����ô�����һ���ж������Ƿ�Ϊ�㣬���Ƿ����delete
	~Sharedptr() {
		if (ptr && -- * count == 0) {
			delete count;
			delete ptr;
			cout << "delete ptr ~" << endl;
		}
	}
	int getRef() {
		return *count;
	}
private:
	int* count;
	T* ptr;
};

int main(int argc, const char* argv[]) {
	Sharedptr<string> pstr(new string("abc"));
	cout << "pstr:" << pstr.getRef() << " " << *pstr << endl;

	Sharedptr<string> pstr2(pstr);
	cout << "pstr:" << pstr.getRef() << " " << *pstr << endl;
	cout << "pstr2:" << pstr2.getRef() << " " << *pstr2 << endl;

	Sharedptr<string> pstr3(new string("hao"));
	cout << "pstr3:" << pstr3.getRef() << " " << *pstr3 << endl;
	
	pstr3 = pstr2;
	cout << "pstr:" << pstr.getRef() << " " << * pstr << endl;
	cout << "pstr2:" << pstr2.getRef() << " " << *pstr2 << endl;
	cout << "pstr3:" << pstr3.getRef() << " " << *pstr3 << endl;

	return 0;
}