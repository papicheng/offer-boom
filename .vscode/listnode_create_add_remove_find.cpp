//链表创建、增删改查

#include <iostream>
using namespace std;

struct listnode {
	int val;
	listnode* next;
	listnode(int x) :val(x),next(NULL) {}
};

void print(listnode* root) {
	listnode* cur = root;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

listnode* creat() {
	listnode* root = new listnode(-1);
	listnode* cur = root;
	for (int i = 0; i < 4; ++i) {
		listnode* tmp = new listnode(i);
		cur->next = tmp;
		cur = cur->next;
	}
	return root;
}

listnode* remove(listnode* root, int x) {
	listnode* cur = root;
	while (cur)
	{
		if (cur->val == x) {
			listnode* back = cur->next;
			cur->val = back->val;
			cur->next = back->next;
			delete back;
			return root;
		}
		cur = cur->next;
	}
	return root;
}

listnode* add(listnode* root, int x) {
	listnode* cur = root;
	while (cur->next)
	{
		cur = cur->next;
	}
	listnode* tmp = new listnode(x);
	cur->next = tmp;
	return root;
}

bool find(listnode* root, int x) {
	listnode* cur = root;
	while (cur) {
		if (cur->val == x) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}

int main()
{
	listnode* root = creat();
	print(root);
	root = remove(root, 2);
	print(root);
	root = add(root, 5);
	print(root);
	cout << find(root, 5) << endl;
	return 0;
}
