/*手写一个vector*/
#include<iostream>
using namespace std;
template<typename T>
class Myvector
{
public:
	Myvector()
	{
		data=NULL;
		capacity=size=0;
	}
	Myvector(const Myvector& other)
	{
		if(this==&other)
			return;
		data=new T[other.size];
		for(int i=0; i<size; i++)
			data[i]=other[i];
		
		capacity=other.capacity;
		size=other.size;	
	}
	T& operator[](int index)
	{
		if(index>=size)
		{
			cout<<"Overflow!"<<endl;
		}
		return data[index];
	}
	const Myvector& push_back(const T temp)
	{
		if(size>=capacity)
		{
			T* newData=new T[capacity*2+1];
			memmove(newData,data,size*sizeof(T));
			delete[] data;
			data=newData;
			capacity=capacity*2+1;
		}
		data[size++]=temp;
		return *this;
	}
    unsigned int GetSize()
	{
		return size;
	}
	unsigned int GetCapacity()
	{
		return capacity;
	}
private:
	T* data;
	unsigned int capacity;
	unsigned int size;
};
class T
{
public:
	T(int a=0):b(a)
	{
	}
 
	int b;
};
 
int main()
{
	Myvector<T> tvec;
	tvec.push_back(T(1));
	cout<<tvec.GetSize()<<endl;
	cout<<tvec.GetCapacity()<<endl;
	tvec.push_back(T(2));
    cout<<tvec.GetSize()<<endl;
	cout<<tvec.GetCapacity()<<endl;
	tvec.push_back(T(3));
	cout<<tvec.GetSize()<<endl;
	cout<<tvec.GetCapacity()<<endl;
	tvec.push_back(T(4));
    cout<<tvec.GetSize()<<endl;
	cout<<tvec.GetCapacity()<<endl;
	tvec.push_back(T(5));
	cout<<tvec.GetSize()<<endl;
	cout<<tvec.GetCapacity()<<endl;
	cout<<"输出元素："<<endl;
	cout<<tvec[0].b<<endl;
	cout<<tvec[1].b<<endl;
	cout<<tvec[2].b<<endl;
	cout<<tvec[3].b<<endl;
	cout<<tvec[4].b<<endl;

    return 0;
}