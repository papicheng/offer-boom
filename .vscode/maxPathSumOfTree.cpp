/*功能：*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * 
 */
struct TreeNode {
     int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int dfs(TreeNode* root,int& val)
{
    if(!root)
    {
        return 0;
    }
    int leftMax=max(0,dfs(root->left,val));
    int rightMax=max(0,dfs(root->right,val));
    val=max(val,root->val+leftMax+rightMax);
    return root->val+max(leftMax,rightMax);//返回经过root的单边最大分支给上游
}
int maxPathSum(TreeNode* root)
{
    int val=INT_MIN;
    dfs(root,val);
    return val;
}


int main()
{
    
    return 0;
}
