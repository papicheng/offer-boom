///��һ�Ѳ�ͬ��ˮ����ÿ����ֻ�ܵõ�һ��ˮ������ÿ���˵õ��������

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
	//�����������ԣ������ʽ����������Ҫ������K�����е�Kֵ������������������
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