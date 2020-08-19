// function��
// ʹ�ò��鼯�ж�ͼ���Ƿ��л�
// ��֪��parent[x1] = x2 ��ʾ����x1�ĸ��ڵ���x2
#include<iostream>
using namespace std;

#define VERTICES 6

// ��ʼ��
void initialize(int parent[], int rank[]){
    for(int i=0; i < VERTICES; i++){
        parent[i] = -1;// ��ʼ��ÿ������ĸ��ڵ���-1
        rank[i] = 0;// ����·��ѹ��
    }
}

// ���ҽڵ�ĸ�
int find_root(int x, int parent[]){
    int x_root = x;
    while(parent[x_root] != -1){
        x_root = parent[x_root];
    }
    return x_root;
}

// ���Ϻϲ�
int union_vertices(int x, int y, int parent[], int rank[]){
    // 1 -- �ϲ��ɹ�
    // 0 -- �ϲ�ʧ��,��x,y�Ѿ���ͬһ��������
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root == y_root)
        return 0;
    else{ // ·��ѹ��
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
    /* �����е�ͼ������ʾ��1, 3, 4, 2���һ����
     *        0
     *          \
     *            1
     *          /   \
     *        2         3
     *        |   \   |
     *        5         4
    */
    int edges[6][2] = { {0, 1}, {1, 2}, {1, 3},
                        {2, 5}, {3, 4}, {5, 6} };// ͼ�����еı߼���
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