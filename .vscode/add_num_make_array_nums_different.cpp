///至少添加几个数就可以使数组中的数不一样
/*
输入：
4           //数组长度
1 3 1 4      //数组中的数
输出：
1

第一个数加一，构成2 3 1 4
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n,data;
    cin>>n;
    vector<int>tem;
    for(int i=0;i<n;++i)
    {
        cin>>data;
        tem.push_back(data);
    }
    sort(tem.begin(),tem.end());
    int i=0; 
    long long int count=0;
    while(i<n-1){
        while(tem[i]>=tem[i+1]) {
            tem[i+1]++;
            count++;
        }
        i++;
    }
    cout<<count<<endl;
    return 0;
}