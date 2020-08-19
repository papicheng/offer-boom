/*输入描述：
共N+2行，第一行是M,N两个正整数；
第二行分别是M台计算机服务器可用内存大小；
其后的N行，每一行是每个请求的内存大小、计算费用两个正整数

输出：估算后的最佳收益结果总值

示例：
输入：
3 5
10 12 15
8 10
12 11
16 22
13 14
9 11
输出：
36


*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include<map>
#include <unordered_map>
using namespace std;

int main()
{
    int n,m,B,val,data;
    cin>>n>>m;
    vector<int>host;
    for(int i=0;i<n;++i)
    {
        cin>>data;
        host.push_back(data);
    }
    vector<int> bvar;
    vector<int> vvar;
    for(int i=0;i<m;++i)
    {
        cin>>B>>val;
        bvar.push_back(B);
        vvar.push_back(val);
    }
    sort(host.begin(),host.end());
    int cost;
    int index;
    for(int i=0;i<n;++i)
    {
        int tem=0;
        for(int j=0;j<m;++j)
        {
            if(host[i]>=bvar[j]&&bvar[j]>tem)
            {
            tem=bvar[j];
            index=j;
            }
        }
        bvar[index]=0;
        cost+=vvar[index]; 
    }
    cout<<cost<<endl;
    return 0;
}