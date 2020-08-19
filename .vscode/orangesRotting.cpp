/*���ܣ��ڸ����������У�ÿ����Ԫ���������������ֵ֮һ��

ֵ?0?����յ�Ԫ��
ֵ?1?�����������ӣ�
ֵ?2?�����õ����ӡ�
ÿ���ӣ��κ��븯�õ����ӣ��� 4 ���������ϣ����ڵ��������Ӷ��ḯ�á�

����ֱ����Ԫ����û����������Ϊֹ�����뾭������С����������������ܣ�����?-1��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rotting-oranges
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/
#include<bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;//1 �ĸ���
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
