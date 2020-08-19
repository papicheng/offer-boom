//并查集
#include<bits/stdc++.h>
using namespace std;
// int father[] = {-1,1,1,2,2,5,5};
const int N = 110;

int father[N];
bool isRoot[N];//记录每个节点是否作为某个集合的根节点

//路径压缩，将所有路径上的节点的father都改成根节点
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }//x已经是根节点
    
    while(a != father[a]){
        int z = a;
        a = father[a]; //继续找出上一个根节点
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);

    if(faA != faB)
        father[faA] = faB;
}

//应用，找出好朋友的组数
void init(int n){//初始化father[i]为i， 且flag[i] 为false
    for(int i = 1; i <= n; ++i){
        father[i] = i;
        isRoot[i] = false;
    }
}
int main(){
    int n , m, a, b;
    scanf("%d %d", &n, &m);
    init(n);
    for(int i = 0; i < m ;++i){
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    for(int i = 1; i <= n; i++){
        isRoot[findFather(i)] = true;
    }
    int ans = 0; 
    for(int i = 1;i <= n; ++i){
        ans += isRoot[i];
    }
    printf("%d\n", ans);
    return 0;
}