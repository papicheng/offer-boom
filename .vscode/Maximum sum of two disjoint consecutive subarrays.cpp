/*???????????????*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int SumOfTwoSubarray(const vector<int> &n)
{
	if (n.size() < 2)
	{
		throw exception();
	}
	vector<int> left(n.size()), right(n.size());
	int sum = n[0], maxnum = n[0];
	left[0] = n[0];
	right.back() = n.back();
	for (uint32_t i = 1; i < n.size()-1; ++i)
	{
		if (sum > 0)
			sum += n[i];
		else
			sum = n[i];
		if (sum > maxnum)
		{
			maxnum = sum;			
		}	
		left[i] = maxnum;
	}
	sum = n.back();
	maxnum = n.back();
	for (uint32_t i = n.size()-2; i >=1; --i)
	{
		if (sum > 0)
			sum += n[i];
		else
			sum = n[i];
		if (sum > maxnum)
		{
			maxnum = sum;
		}
		right[i] = maxnum;
	}
	int res = INT_MIN;
	for (uint32_t i = 0; i < n.size() - 1; ++i)
		res = max(res, left[i] + right[i + 1]);
	return res;
}
int main(){
    // vector<int> vec = {1, -1, 2, 2, 3, -3, 4, -4, 5, -5};
    // cout<< SumOfTwoSubarray(vec)<<endl;
    int n = 0;
    cin>> n;
    string str;
    while (n--)
    {
        // cin>> str;
        int m;
        cin>>m;
        vector<int> vec(m);
        for(int i = 0 ; i < m; ++i){
            cin>> vec[i];
        }
        cout<< SumOfTwoSubarray(vec)<<endl;
        cin>>str;
    }
    return 0;
}
/*
3

10
1 -1 2 2 3 -3 4 -4 5 -5

5
-5 9 -5 11 20

10
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/