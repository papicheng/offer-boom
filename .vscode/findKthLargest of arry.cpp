/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;
inline int partition(vector<int>& a, int l, int r){
    int x = a[r], i = l - 1;
    for(int j = l ; j < r; ++j){
        if(a[j] <= x){
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return 1 + i;
}
inline int randomPartition(vector<int>& a, int l , int r){
    int i = rand() % (r - l + 1) + 1;
    swap(a[i], a[r]);
    return partition(a, l ,r );
}
int quickSelect(vector<int>& a, int l , int r , int index){
    int q = randomPartition(a, l , r);
    if(q == index){
        return a[q];
    }else
    {
        return q < index ? quickSelect(a , q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }
    
}
int findKthLargest(vector<int>& nums, int k)
{
    srand(time(0));
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
}

int main()
{
    
    return 0;
}
