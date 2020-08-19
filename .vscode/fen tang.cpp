#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct cmp{
	bool operator ()(int& a, int& b) {
		return a < b;//最大值优先
	}
};

int main() {
	//这里用来测试，输入格式：先输入需要求的最大K个数中的K值，再依次输入数据流
	int T = 0;
	cin >> T;
	vector<int> res;
	while (T)
	{
		priority_queue<int, vector<int>, cmp> bigheap_s;			//建立最大优先队列
		int n, m;//水果种类，人数
		cin >> n >> m;
		vector<int> fruits;
		int fruit_num;
		int sum = 0;//水果总数
		while (n)
		{
			cin >> fruit_num;
			sum += fruit_num;
			bigheap_s.push(fruit_num);
			--n;
		}
		int avg = sum / m;
		res.push_back(0);
		while (avg)
		{
			int count = 0;
            priority_queue<int, vector<int>, cmp> bigheap=bigheap_s;
			while (bigheap.top() >= avg)
			{
				int topNum = bigheap.top();
				bigheap.pop();
				bigheap.push(topNum - avg);
				++count;
				if (count == m)
				{
					res[res.size() - 1] = avg;
					break;
				}
			}
            if(count==m)
                break;
			--avg;
		}
		--T;
	}
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] <<endl;
	return 0;
}
