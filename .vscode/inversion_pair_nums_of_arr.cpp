/*���ܣ�
�鲢����һ�������е�����Զ���
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
    int global_count = 0;
    int reversePairs(vector<int>& nums) {
        vector<int> copyarr(nums.size(), 0);
        merge_sort(nums, copyarr, 0, nums.size()-1);
        return global_count;
    }

    void merge_sort(vector<int>& nums, vector<int>& copyarr, int left, int right) {
        if (left >= right) return;
        int mid = (left+right) / 2;
        merge_sort(nums, copyarr, left, mid);
        merge_sort(nums, copyarr, mid+1, right);
        int i = left, j = mid+1, k = left;
        while (i <= mid && j <= right) {
            if (nums[j] < nums[i]) {
                copyarr[k++] = nums[j++];
                global_count += (mid-i+1);         // �ؼ��㣬Ҳ�ǹ鲢������ӵ�Ψһһ�д��롣
            } else {
                copyarr[k++] = nums[i++];
            }
        }
        if (i <= mid) copy(nums.begin()+i, nums.begin()+mid+1, copyarr.begin()+k);
        if (j <= right) copy(nums.begin()+j, nums.begin()+right+1, copyarr.begin()+k);
        copy(copyarr.begin()+left, copyarr.begin()+right+1, nums.begin()+left);
    }
};

void print( vector<int>const &a)
{
    for(auto i:a)
    {
        cout<<i<<"  ";
    }
    cout<<endl;
}

int main()
{
	vector<int>a={7,5,6,4};
    vector<int>b={4,26,8,5};
    copy(a.begin()+1,a.begin()+3,b.begin());//copy�Ḳ���Ǹ�λ�õ�����
    print(b);
    return 0;
}