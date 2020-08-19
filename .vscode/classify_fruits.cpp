///分一堆不同的水果，每个人只能得到一种水果，求每个人得到的最大数

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include<queue>
using namespace std;

int main() {
	//这里用来测试，输入格式：先输入需要求的最大K个数中的K值，再依次输入数据流
	int T, n, m, ai;
	cin >> T;
	vector<int> res;
	while (T) {
		--T;
		cin >> n >> m;
		int i = 0;
		priority_queue<int, vector<int>, less<int> > p;
		int sum = 0;
		while (i < n) {
			i++;
			cin >> ai;d
			p.push(ai);
			sum += ai;
		}
		int k = sum / m;
		while (k >= 0) {
			i = 0;
			bool flag = true;
			priority_queue<int, vector<int>, less<int> > q = p;
			while (i < n) {
				i++;
				int u = q.top();
				if (u >= k) {
					q.pop();
					q.push(u - k);
				}
				else flag = false;
			}
			if (flag) {
				res.push_back(k);
				break;
			}
			k--;
		}
	}
	for (int i = 0; i < res.size(); i++) cout << res[i]<< endl;
	
	return 0;
}