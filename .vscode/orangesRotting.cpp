/*功能：在给定的网格中，每个单元格可以有以下三个值之一：

值?0?代表空单元格；
值?1?代表新鲜橘子；
值?2?代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回?-1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include<bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;//1 的个数
        queue<vector<int>> qu;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0;  j < grid[0].size(); j++){
                if( grid[i][j] == 2){
                    qu.push({i, j});
                }
                else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        vector<vector<int>> dir = {{1,0}, {-1, 0},{0, 1}, {0, -1}};
        int res = 0;
        while(qu.size()){
            auto q = qu.front();
            qu.pop();
            for(auto vec : dir){
                int x = q[0] + vec[0];
                int y = q[1] + vec[1];
                if( x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) continue;
                grid[x][y] = grid[q[0]][q[1]] + 1;
                qu.push({x, y});
                res = grid[x][y] - 2;
                cnt--;
            }
        }
        return (cnt == 0) ? res : -1;
    }
int main()
{
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int res = orangesRotting(grid);
    cout<< res<< endl;
    return 0;
}
