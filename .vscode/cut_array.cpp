/*功能：*/
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



// 给定一个整数数组 nums ，小李想将 nums 切割成若干个非空子数组，使得每个子数组最左边的数和最右边的数的最大公约数大于 1 。为了减少他的工作量，请求出最少可以切成多少个子数组。



// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/qie-fen-shu-zu
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
int measure(int x,int y)
{
    int z=y;
    while(x%y!=0)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return z;
}

bool cutSuccess(vector<int> nums)
{
    int len=nums.size();
    if(measure(nums[0],nums[len-1])>1)
    {
        return true;
    }
    cutSuccess(vector<int>(nums.begin()+1,nums.end()));
    return false;
}

int splitArray(vector<int>& nums) {

}



int main()
{
    

    return 0;
}
