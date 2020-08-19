/*前序和后序求中序*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* search(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd) {
    if(preStart > preEnd || postStart > postEnd) {  //递归终止条件
        return NULL;
    }
    int rootVal = pre[preStart];
    TreeNode* root = new TreeNode(rootVal);
    for(int i = postStart; i < postEnd; ++i) {  //这里由于postEnd已经是root了，所以此处查找的时候不能再包含
        if(post[i] == pre[preStart + 1]) {  //这里由于是后序+前序 所以这里要找到的左子树的根节点
            root->left = search(pre, preStart + 1, preStart + i - postStart + 1, post, postStart, i);
            root->right = search(pre, preStart + i - postStart + 2, preEnd, post, i + 1, postEnd - 1);
            break;
        }
    }
    return root;
}
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    TreeNode* root = search(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    return root;
}
vector<int> vec;
void dfs(TreeNode* root){
    if(! root) return;
    dfs(root->left);
    vec.push_back(root->val);
    dfs(root->right);
}
vector<int> solve(int n, vector<int>& pre, vector<int>& suf) {
    TreeNode* root = constructFromPrePost(pre, suf);
    dfs(root);
    return vec;
}
int main(){
    vector<int> pre = {3,2,1,4,5};
    vector<int> suf = {1,5,4,2,3};
    vector<int> res = solve(pre.size(), pre, suf);
    for(auto i : res){
        cout<< i <<" ";
    }
    return 0;
}