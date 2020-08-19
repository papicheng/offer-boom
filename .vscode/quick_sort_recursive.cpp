/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

void print(vector<int>& arr){
    for(auto i : arr){
        printf("%d ", i);
    }
    printf("\n");
}
void quick_sort(vector<int>&arr, int left, int right)
{
    if(left<right)
    {
        int i=left,j=right,x=arr[left];
        while (i<j)
        {
            while (i<j&&arr[j]>=x)
            {
                --j;
            }
            if(i<j)
            {
                arr[i++]=arr[j];
            }
            while (i<j&&arr[i]<=x)
            {
                ++i;
            }
            if(i<j)
            {
                arr[j--]=arr[i];
            }
            arr[i]=x;
        }

        print(arr);
        quick_sort(arr,left,i-1);
        quick_sort(arr,i+1,right);
    }
}

int main()
{
//     9
// 25 84 21 47 15 27 68 35 20
    int n = 9;
    // vector<int> arr={25, 84, 21, 47, 15, 27, 68, 35, 20};
    vector<int> arr;
    cin>> n;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin>> tmp;
        arr.push_back(tmp);
    }
    quick_sort(arr,0,arr.size()-1);   
    print(arr);
    return 0;
}
