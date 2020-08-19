// function：
// 使用并查集判断图中是否含有环
// 须知：parent[x1] = x2 表示顶点x1的父节点是x2
#include<iostream>
using namespace std;

#define VERTICES 6

// 初始化
void initialize(int parent[], int rank[]){
    for(int i=0; i < VERTICES; i++){
        parent[i] = -1;// 初始化每个顶点的父节点是-1
        rank[i] = 0;// 用来路径压缩
    }
}

// 查找节点的根
int find_root(int x, int parent[]){
    int x_root = x;
    while(parent[x_root] != -1){
        x_root = parent[x_root];
    }
    return x_root;
}

// 集合合并
int union_vertices(int x, int y, int parent[], int rank[]){
    // 1 -- 合并成功
    // 0 -- 合并失败,即x,y已经在同一个集合内
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root == y_root)
        return 0;
    else{ // 路径压缩
        if(rank[x_root] > rank[y_root])
            parent[y_root] = x_root;
        else if(rank[x_root] < rank[y_root])
            parent[x_root] = y_root;
        else{
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return 1;
    }
}

int main(int argc, char const *argv[]) {
    int parent[VERTICES];
    int rank[VERTICES];
    /* 代码中的图如下所示，1, 3, 4, 2组成一个环
     *        0
     *          \
     *            1
     *          /   \
     *        2         3
     *        |   \   |
     *        5         4
    */
    int edges[6][2] = { {0, 1}, {1, 2}, {1, 3},
                        {2, 5}, {3, 4}, {5, 6} };// 图中所有的边集合
    initialize(parent, rank);
    for(int i=0; i < 6; ++i){
        int x = edges[i][0];
        int y = edges[i][1];
        if(union_vertices(x, y, parent, rank) == 0){
            cout<<"Cycle detected."<<endl;
            return 0;
        }
    }
    cout<<"No cycle."<<endl;
    return 0;
}