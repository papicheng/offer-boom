/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            int mid = (right - left) / 2 + left;
            if(numbers[mid] < numbers[right]){
                right = mid;
            }
            else if(numbers[mid] >= numbers[right]){
                left = mid + 1;
            }
            else{
                right -= 1;
            }
            
        }
        return numbers[left];
    }

int main()
{
    vector<int> number = {2,2,2,0,1};//3,4,5,1,2};
    cout << minArray(number)<<endl;
    return 0;
}
