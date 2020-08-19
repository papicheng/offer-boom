/*���ܣ�
СQ����ĩ��ʱ�������С�����������й�֣�һ�����н����кܶ��¥������n����¥�ų�һ�С�
СQ�ӵ�һ��һֱ�ߵ������һ����СQ������û�м�����ô���¥����������֪������ÿ��¥��λ�ô��ܿ������ٶ�¥�أ�����ǰ���¥�ĸ߶ȴ��ڵ��ں����¥ʱ�������¥������ס�� 
*/

///����ջ
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
