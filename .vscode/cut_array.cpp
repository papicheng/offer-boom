/*���ܣ�*/
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



// ����һ���������� nums ��С���뽫 nums �и�����ɸ��ǿ������飬ʹ��ÿ������������ߵ��������ұߵ��������Լ������ 1 ��Ϊ�˼������Ĺ���������������ٿ����гɶ��ٸ������顣



// ��Դ�����ۣ�LeetCode��
// ���ӣ�https://leetcode-cn.com/problems/qie-fen-shu-zu
// ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
