/*功能：二叉树最小深度*/
#include<bits/stdc++.h>

using namespace std;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;
};
//递归版
int fun1(Tree* root){
    if(!root) return 0;
    return min(fun1(root->left), fun1(root->right));
}
//非递归版
int fun2(Tree* root){
    if(!root) return 0;
    if(!root->left || !root->right) return 1;
    queue<Tree*> qu;
    qu.push(root);
    int len = 1;
    int depth = 0;
    int next = 0;
    while (qu.size() > 0)
    {
        Tree* node = qu.front();
        qu.pop();
        len--;
        if(!node->left && !node->right){
            depth++;
            break;
        }
        if(node->left){
            qu.push(node->left);
            next++;
        }
        if(node->right){
            qu.push(node->right);
            next++;
        }
        if(len == 0){
            depth++;
            len = next;
            next = 0;
        }
    }
    return depth;
}

int main()
{
    
    return 0;
}
