/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x){};
};

typedef struct Node Node;

int mian(){
    Node* pre, cur ,head;
    head = (Node*)malloc(sizeof(Node))
    return 0;
}

int cnt = 0;
        queue<vector<int>> que;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
                else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        int ans = 0;
        vector<vector<int>> dd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!que.empty()){
            auto q = que.front();
            que.pop();
            for(auto d : dd){
                int dx = q[0] + d[0];
                int dy = q[1] + d[1];
                if(dx < 0 || dx >= grid.size()) continue;
                if(dy < 0 || dy >= grid[0].size()) continue;
                if(grid[dx][dy] != 1) continue;
                grid[dx][dy] = grid[q[0]][q[1]] + 1;
                cnt--;
                que.push({dx, dy});
                ans = grid[dx][dy] - 2;
            }
        }
        return (cnt == 0) ? ans : -1;