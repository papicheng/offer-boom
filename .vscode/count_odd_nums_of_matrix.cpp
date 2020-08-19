/*¹¦ÄÜ£º*/
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


int oddCells(int n, int m, vector<vector<int>>& indices) {
    map<int,int> mp_row;
    map<int,int> mp_col;
    for(auto vec:indices)
    {
        mp_row[vec[0]]++;
        mp_col[vec[1]]++;
    }
    vector<vector<int>> matrix(n,vector<int>(m));
    auto iter_row=mp_row.begin();
    while (iter_row!=mp_row.end())
    {
        for(int i=0;i<m;++i)
        {
            matrix[(*iter_row).first][i]+=(*iter_row).second;
        }
        iter_row++;
    }
    auto iter_col=mp_col.begin();
    while(iter_col!=mp_col.end())
    {
        for(int i=0;i<n;++i)
        {
            matrix[i][(*iter_col).first]+=(*iter_col).second;
        }
        iter_col++;
    }
    int res=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(matrix[i][j]&1==1)
            {
                ++res;
            }
        }
    }
    return res;
}

int main()
{
    int n=2,m=2;
    vector<vector<int>> indices={{1,1},{0,0}};
    int res=oddCells(n,m,indices);
    cout<<res<<endl;
    return 0;
}
