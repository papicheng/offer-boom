/*功能：
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
输入: [3,30,34,5,9]
输出: 9534330
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;

class Solution {
public:
	static bool myCompare(const string& a1, const string& a2)
	{
		return a1 + a2 > a2 + a1;
	}
	string largestNumber(vector<int>& nums) {
		vector<string> temp;
		for (auto i : nums) temp.push_back(to_string(i));
		sort(temp.begin(), temp.end(), myCompare);
		if (temp[0] == "0") return "0";
		string s = "";
		for (auto i : temp) s += i;
		return s;
	}
};
  

int main()
{
    return 0;
}
