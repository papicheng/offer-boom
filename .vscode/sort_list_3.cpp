/*功能：

一个有序链表通过增减删除，每个节点输出三次
输入：1 2 3
输出：1 1 1 2 2 2 3 3 3

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







int main()
{
    map<int,int> mp;
    string line;
    string item;
    getline(cin,line);
    istringstream items(line);
    vector<int> vec;
    while (items>>item)
    {
        int tmp=atoi( item.c_str() );
        vec.push_back(tmp);
        mp[tmp]++;
    }
    map<int,int>::iterator iter=mp.end();
    int a=vec[0];
    int b=vec[vec.size()-1];
    iter=mp.begin();
    if(a<b)
    {
        while(iter!=mp.end())
        {
            for(int i=0;i<3;++i)
            {
                cout<<iter->first<<" ";
            }
            iter++;
        }
    }
    else
    {
        iter=mp.end();
        iter--;
        while (iter!=mp.begin())
        {
            for(int i=0;i<3;++i)
            {
                cout<<iter->first<<" ";
            }
            iter--;
        }
        for(int i=0;i<3;++i)
        {
            cout<<iter->first<<" ";
        }
    }

    return 0;
}
