/*功能：
链接：https://www.nowcoder.com/questionTerminal/6a1815a85bfc411d9295bc017e6b6dbe
来源：牛客网

给定一颗二叉树，分别实现按层和 ZigZag 打印二叉树。
ZigZag遍历: 意思是第一层从左到右遍历，第二层从右到左遍历，依次类推。

输入描述:
第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。
以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)


输出描述:
先输出按层打印，再输出按ZigZag打印。
示例1
输入
8 1
1 2 3
2 4 0
4 0 0
3 5 6
5 7 8
6 0 0
7 0 0
8 0 0
输出
Level 1 : 1
Level 2 : 2 3
Level 3 : 4 5 6
Level 4 : 7 8
Level 1 from left to right: 1
Level 2 from right to left: 3 2
Level 3 from left to right: 4 5 6
Level 4 from right to left: 8 7
*/
#include<bits/stdc++.h>

using namespace std;

void printByLevel(int root, int* lc, int* rc){
    if(!root) return;
    deque<int> q;
    q.push_back(root);
    int level = 1;
    while(!q.empty()){
        int len = q.size();
        cout<<"Level " << level <<":";
        for(int i = 0; i < len; ++i){
            int cur = q.front();
            q.pop_front();
            cout<<" "<<cur;
            if(lc[cur]) q.push_back(lc[cur]);
            if(rc[cur]) q.push_back(rc[cur]);
        }
        cout<< endl;
        ++level;
    }
}
void printByZigZag(int root, int* lc, int* rc){
    if(!root) return;
    deque<int> q;
    int level = 1;
    q.push_back(root);
    while(!q.empty()){
        if(level & 1){
            cout<<"Level "<<level<<"from left to right:";
            int len = q.size();
            for(int i = 0; i < len; ++i){
                int cur = q.front();
                q.pop_front();
                cout<<" " <<cur;
                if(lc[cur]) q.push_back(lc[cur]);
                if(rc[cur]) q.push_back(rc[cur]);
            }
        }
        else{
            cout<< "Level "<< level <<"from right to left:";
            int len = q.size();
            for(int i = 0; i < len ; ++i){
                int cur = q.back();
                q.pop_back();
                cout<<" "<<cur;
                if(rc[cur]) q.push_front(rc[cur]);
                if(lc[cur]) q.push_front(lc[cur]);
            }
        }
        cout<<endl;
        ++level;
    }
}
int main()
{
    int n , root;
    cin>> n >> root;
    int p;
    int* lc = new int[n + 1];
    int* rc = new int[n + 1];
    for(int i = 0; i < n; ++i){
        cin>>p;
        cin>>lc[p]>>rc[p];
    }
    printByLevel(root, lc, rc);
    printByZigZag(root, lc, rc);
    return 0;
}
