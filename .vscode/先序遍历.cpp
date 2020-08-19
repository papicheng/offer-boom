#include<iostream>
#include<vector>
#include<stack>
using namespace std;



//Definition for binary tree
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};
int main()
{
    
    return 0;
}


vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *p=root;
    while(p||!st.empty())
    {
        if(p)
        {
            res.push_back(p->val);
            st.push(p);
            p=p->left;
        }
        else
        {
            p=st.pop();
            st.pop();
            p=p->right;
        }
        
    }
    return res;
}