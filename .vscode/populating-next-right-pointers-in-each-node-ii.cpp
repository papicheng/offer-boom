/*¹¦ÄÜ£º*/
#include<iostream>
#include<queue>
using namespace std;

/**
 * Definition for binary tree with next pointer.

 */
 struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
   };

void connect_fail(TreeLinkNode *root) 
{
    if(!root) 
    {
        return;
    }
    if(root->left&&root->right)
    {
        root->left->next=root->right;
    }
    if(root->next&&root->next->left&&root->right)
    {
        root->right->next=root->next->left;
    }
    else if(root->next&&root->next->right&&root->right)
    {
        root->right->next=root->next->right;
    }
    else if(root->next&&root->next->left&&root->left)
    {
        root->left->next=root->next->left;
    }
    else if(root->next&&root->next->right&&root->left)
    {
        root->left->next=root->next->right;
    }
    connect_fail(root->left);
    connect_fail(root->right);
}

void connect_fail_1(TreeLinkNode* root)
{
    if(!root) return;
    queue<TreeLinkNode*> qu;
    if(root->left)
    {
        qu.push(root->left);
    }
    if(root->right){
        qu.push(root->right);
    }
    if(root->next->left)
    {
        qu.push(root->next->left);
    }
    if(root->next->right)
    {
        qu.push(root->next->right);
    }
    TreeLinkNode* temp=qu.front();
    qu.pop();
    while(!qu.empty())
    {
        temp->next=qu.front();
        temp=qu.front();
        qu.pop();
    }
    connect_fail_1(root->left);
    connect_fail_1(root->right);
}

void connect_success_1(TreeLinkNode* root)
{
    if(!root) return;
    queue<TreeLinkNode*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        int n=qu.size();
        for(int i=0;i<n;++i)
        {
            TreeLinkNode* tmp=qu.front();
            qu.pop();
            if(tmp->left)
            {
                qu.push(tmp->left);
            }
            if(tmp->right)
            {
                qu.push(tmp->right);
            }
            if(i!=n-1)
            {
                tmp->next=qu.front();
            }
            else 
            {
                tmp->next=NULL;
            }
        }
    }
}
void connect(TreeLinkNode* root)
{
    while (root)
    {
        TreeLinkNode first(-1);
        auto pre=&first;
        for(auto node=root;node;node=node->next)
        {
            if(node->left)
            {
                pre->next=node->left;
                pre=node->left;
            }
            if(node->right)
            {
                pre->next=node->right;
                pre=node->right;
            }
        }
        root=first.next;
    }
    
}
int main()
{
    
    return 0;
}
