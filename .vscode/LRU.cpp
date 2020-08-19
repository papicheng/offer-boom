/*���ܣ�*/
#include<bits/stdc++.h>

using namespace std;

class LRUCache{
private:
	//LRU���ݽṹ
	struct Node{
		int key;
		int value;
		Node(int k,int v):key(k),value(v){}
	};
public:
	LRUCache(int c):capacity(c) {}
	int get(int key){
		if (cacheMap.find(key) == cacheMap.end())
			return -1; //�������ȱҳ�жϣ�����ҳ��ҳ������ڴ棬Ȼ��set(key, value)
		//��key�Ƶ���һ����������cacheMap 
		cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void set(int key, int value){
		if (cacheMap.find(key) == cacheMap.end()){
			//��̭���һ����Ȼ����ӵ���һ��λ��
			if (cacheList.size() == capacity){
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(Node(key,value));
			cacheMap[key] = cacheList.begin();
		} 
		else{
			//���½ڵ��ֵ��������ӵ���һ��λ��
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	int capacity;
	list<Node> cacheList;
	unordered_map<int, list<Node>::iterator> cacheMap;
};


int main()
{
    
    return 0;
}
