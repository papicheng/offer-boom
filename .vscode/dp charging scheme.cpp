/*功能：大疆笔试最优收费方案*/
#include<bits/stdc++.h>
/*功能：*/
using namespace std;

int monye(int start, int end) {
	int res = 0;
	if (end < 6) {
		return (end - start) * 10;
	}
	if (end < 10) {
		if (start < 6) {
			res += (6 - start) * 10;
		}
		res += (end - 6) * 5;
	}
	if (end >= 10) {
		if (start < 6) {
			res += (6 - start) * 10;
			res += 4 * 5;
		}
		else if (start < 10) {
			res += (10 - start) * 5;
		}
		res += (end - 10) * 2;
	}
	return res;
}

int main() {
	string line = "1 1 4, 2 2 6, 3 3 12, 4 6 10";
	// cin>> line;
	// cout<< "60, 2 4"<<endl;
	string item;
	// getline(cin,line);
	// cout<< line<<endl;
	istringstream items(line);
	deque<string> st1;
	stack<string> st2;
	vector<vector<int>> vec;
	int cnt = 1;

	vector<int> tmp(3);
	while (items >> item)
	{
		switch (cnt)
		{
		case 1:
			tmp[0] = atoi(item.c_str());
			cnt++;
			break;
		case 2:
			tmp[1] = atoi(item.c_str());
			cnt++;
			break;
		case 3:
			cnt = 1;
			if(item[item.size() - 1] == ',')
				tmp[2] = atoi(item.erase(item.size() - 1).c_str());
			else
			{
				tmp[2] = atoi(item.c_str());
			}
			vec.push_back(tmp);
		default:
			break;
		}
	}
	int n = vec.size();
	vector<int> dp(n, 0);
	vector<int> pre(n, 0);
	vector<vector<int>> id;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			if (vec[j][2] <= vec[i][1]) {
				pre[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			dp[i] = monye(vec[i][1], vec[i][2]);
			vector<int> tmp;
			tmp.push_back(vec[i][0]);
			id.push_back(tmp);
			continue;
		}
		if (pre[i] == 0) {
			int tmpMonye = monye(vec[i][1], vec[i][2]);
			if (tmpMonye > dp[i - 1]) {
				dp[i] = tmpMonye;
				vector<int> tmp;
				tmp.push_back(vec[i][0]);
				id.push_back(tmp);
			}
			else {
				dp[i] = dp[i - 1];
				vector<int> id_tmp;
				for (auto num : id[i - 1]) {
					id_tmp.push_back(num);
				}
				id.push_back(id_tmp);
			}
		}
		else {
			int tmpMonye = monye(vec[i][1], vec[i][2]) + dp[pre[i]];
			if (tmpMonye > dp[i - 1]) {
				dp[i] = tmpMonye;
				vector<int> id_tmp;
				for (auto num : id[pre[i]]) {
					id_tmp.push_back(num);
				}
				id.push_back(id_tmp);
				id[id.size() - 1].push_back(vec[i][0]);
			}
			else {
				dp[i] = dp[i - 1];
				vector<int> id_tmp;
				for (auto num : id[i - 1]) {
					id_tmp.push_back(num);
				}
				id.push_back(id_tmp);
			}
		}
	}
	cout << dp[dp.size() - 1] << ", ";
	for (auto i : id[id.size() - 1]) {
		cout << i << " ";
	}
	return 0;
}
// hello undo redo world.
//1 1 4, 2 2 6, 3 3 12, 4 6 10