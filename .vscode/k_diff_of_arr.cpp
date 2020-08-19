/*功能：
输入: [3, 1, 4, 1, 5], k = 2
输出: 2
解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个1，但我们只应返回不同的数对的数量。

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



int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0,right=1,ans=0;
        while(right<nums.size()&&left<nums.size()-1)
        {
            while(right<nums.size()&&left<right&&nums[right]-nums[left]<k)
            {
                ++right;
            }
            if(right<nums.size()&&left<right&&left<nums.size()-1&&nums[right]-nums[left]==k)
            {  
                ++ans;
                ++right;
                ++left;
            }
            else if(right<nums.size()&&left<right&&left<nums.size()-1&&nums[right]-nums[left]>k)
            {
                ++left;
            }
            if(right<nums.size()&&right==left)
            {
                ++right;
            }
        }
        return ans;
    }



int mai22n()
{
    vector<int> a={1,3,1,5,4};
    int ans=findPairs(a,0);
    cout<<ans<<endl;
    return 0;
}


#include <iostream>
using namespace std;
void f(double*a,double* b,double R[2]){
    R[0]=a[0]*b[0];
    R[1]=a[1]*b[1];
    cout<<"R[0]="<<R[0]<<endl;
    cout<<"R[1]="<<R[1]<<endl;
} 
int main22(){
    double a[2]={0.2,0.3};
    double b[2]={0.5,0.7};
    double S[2];
    f(a,b,S);
    cout<<"S[0]="<<S[0]<<endl;
    cout<<"S[1]="<<S[1]<<endl;
    return 0;
}

void Test(int (&array)[5])
{
	cout << "size:" << sizeof(array) << endl;
	for (int i = 0; i < sizeof(array)/4; i++)
	{
		cout << array[i] << " ";
	}
}
int main()
{
    int  array[5] = {1,2,3,4,5};
    Test(array);
    return 0;
}