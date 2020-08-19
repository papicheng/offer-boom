//���鼯
#include<bits/stdc++.h>
using namespace std;
// int father[] = {-1,1,1,2,2,5,5};
const int N = 110;

int father[N];
bool isRoot[N];//��¼ÿ���ڵ��Ƿ���Ϊĳ�����ϵĸ��ڵ�

//·��ѹ����������·���ϵĽڵ��father���ĳɸ��ڵ�
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }//x�Ѿ��Ǹ��ڵ�
    
    while(a != father[a]){
        int z = a;
        a = father[a]; //�����ҳ���һ�����ڵ�
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

//Ӧ�ã��ҳ������ѵ�����
void init(int n){//��ʼ��father[i]Ϊi�� ��flag[i] Ϊfalse
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