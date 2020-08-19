
#include<iostream>
#include<string>
#include<sstream>
#include<set>

using namespace std;

string* fun(string number, int n, int m)
{
	string s("0123456789abcdefghijklmnopqrstuvwxyz");
	int si = n;
	set<int>se;
	while (si) {
		--si;
		se.insert(s[si]);
	}
	for (int ni = 0; ni < number.size(); ++ni) {
		if (se.find(number[ni]) == se.end()) {
			number = number.substr(0, ni);
			break;
		}
	}
	unsigned int i = 0;
	int num = 0;
	while (i < number.size())
	{
		num = num * n + number[i] - '0';
		i++;
	}

	i = 0;
	string* ret = new string;
	while (num > 0)
	{
		ret->push_back(s[num % m]);
		num /= m;
	}

	int begin = 0;
	int end = ret->size() - 1;
	while (begin < end)
	{
		char tmp = (*ret)[begin];
		(*ret)[begin] = (*ret)[end];
		(*ret)[end] = tmp;
		begin++;
		end--;
	}

	return ret;
}

int main()
{
	int n, m;
	cin >> n >> m;
	//string s("123abc");
	string s;
	cin >> s;
	string* ret = fun(s, n, 10);
	//cout << *ret << endl;
	stringstream ss;
	ss << (*ret);
	int num;
	ss >> num;
	//cout << num << endl;
	delete ret;
	ret = NULL;

	int res = num % m;
	cout << res << endl;
	return 0;
}