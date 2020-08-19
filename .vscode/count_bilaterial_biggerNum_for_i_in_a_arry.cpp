/*功能：
小Q在周末的时候和他的小伙伴来到大城市逛街，一条步行街上有很多高楼，共有n座高楼排成一行。
小Q从第一栋一直走到了最后一栋，小Q从来都没有见到这么多的楼，所以他想知道他在每栋楼的位置处能看到多少栋楼呢？（当前面的楼的高度大于等于后面的楼时，后面的楼将被挡住） 
*/

///单调栈
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

int main()
{
    int n=0;
    cin>>n;
    int *height=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>height[i];
    }
    stack<int> left,right;
    vector<int> res_left,res_right;
    for (int i = 0,j=n-1; i < n,j>=0; i++,j--)
    {
        res_left.push_back(left.size());
        res_right.push_back(right.size());
        while (!left.empty()&&left.top()<=height[i])
        {
            left.pop();
        }
        while (!right.empty()&&right.top()<=height[j])
        {
            right.pop();
        }
        left.push(height[i]);
        right.push(height[j]);
    }
    reverse(res_right.begin(),res_right.end());
    for (int i = 0; i < n; i++)
    {
        cout<<res_left[i]+res_right[i]+1<<" ";
    }
    
    
    return 0;
}
