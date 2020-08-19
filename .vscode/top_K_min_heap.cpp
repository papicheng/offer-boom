//    Top-K问题是一个十分经典的问题，一般有以下两种方式来描述问题：在10亿的数字里，找出其中最大的100个数；或者在一个包含n个整数的数组中，找出最大的100个数。

/*
*代码采用STL中的最小优先队列实现，由于STL中自带最小优先队列，其底层就是二叉堆实现，
*所以就不再手写二叉堆了。最小优先队列顶层元素总是队列中最小的元素，也就是二叉堆堆顶。
*/
 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
/*由于STL自带优先队列是默认最大优先的，所以自己写了一个比较函数，将其改为最小优先*/
struct cmp1 {
	bool operator ()(int &a, int &b) {
		return a<b;											//最小值优先
	}
};
 
int main() {
	//这里用来测试，输入格式：先输入需要求的最大K个数中的K值，再依次输入数据流
	int K = 0;
	cin >> K;
	int tmp = 0;
	int i = 0;
	priority_queue<int,vector<int>,cmp1> minHeap;			//建立最小优先队列
	while (cin >> tmp) {									//循环输入数据流
		if (i < K) {										//先建立一个K个大小的优先队列，也就是K大小的二叉堆
			minHeap.push(tmp);
		}
		else {												//算法实现
			if (tmp <= minHeap.top())
				continue;
			else if (tmp > minHeap.top()) {
				minHeap.pop();
				minHeap.push(tmp);
			}
		}
		i++;
	}
	while (!minHeap.empty()) {								//输出最大的K个数
		cout << minHeap.top() << endl;
		minHeap.pop();
	}
	return 0;
}
 