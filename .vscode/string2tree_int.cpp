///字符串转二叉树
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include<queue>
#include<stack>
using namespace std;
//结点数据结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
//树的先序遍历
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> v;
    if (root!=NULL){
        stack<TreeNode*> s1;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            v.push_back(root->val);
            if(root->right!=NULL) s1.push(root->right);
            if(root->left!=NULL) s1.push(root->left);
        }
    }
    return v;
}

vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> v;
    while(!s.empty()||root!=NULL){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            v.push_back(root->val);
            root=root->right;
        }
    }
    return v;
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> v;
    if (root!=NULL){
        stack<TreeNode*> s1;
        stack<int> s2;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root->val);
            if(root->left!=NULL) s1.push(root->left);
            if(root->right!=NULL) s1.push(root->right);
        }
        while(!s2.empty()) {
            v.push_back(s2.top());
            s2.pop();
        }
    }
    return v;
}
//将字符串转换为树结构
TreeNode* midTraceByStack(string str){
    if(str.length()==0) return NULL;
    stack<TreeNode*> s;
    bool dircFlag=true;
    //临时变量
    int length=str.length();
    int sum=0;
    int i=0;
    bool flag=false;
    while(true){
        if(str[i]>='0'&&str[i]<='9') sum=sum*10+(str[i]-'0');
        else if(str[i]=='-') flag=true;
        else break;
        i++;
    }
    if(flag){
        sum=-sum;
        flag=false;
    }
    TreeNode *node=new TreeNode(sum);
    //保存根结点位置
    TreeNode* root=node;
    TreeNode *temp;
    while(i<length){
        //当前字符的四种情况
        if(str[i]=='('){
            s.push(node);
            dircFlag=true;
            i++;
            sum=0;
        }
        else if(str[i]==')'){
            s.pop();    
            dircFlag=false;
            i++;
            sum=0;
        }
        else if(str[i]==','){
            dircFlag=false;
            i++;
            sum=0;
        }
        else{
            while(true){
                if(str[i]>='0'&&str[i]<='9') sum=sum*10+(str[i]-'0');
                else if(str[i]=='-') flag=true;
                else break;
                i++;
            }
            if(flag){
                sum=-sum;
                flag=false;
            }
            node=new TreeNode(sum);
            if(dircFlag){
                s.top()->left=node;
            }
            else{
                s.top()->right=node;
            }
        }
    }
    return root;
}

int max_gain(TreeNode *root,int& max_sum){
    if(root==NULL) return 0;
    int left_gain=max(max_gain(root->left,max_sum),0);
    int right_gain=max(max_gain(root->right,max_sum),0);
    int price_newpath=root->val + max(left_gain, right_gain);
    max_sum = max(max_sum, price_newpath);
    return price_newpath;
}
int maxPathSum(TreeNode *root){
    int max_sum=INT_MIN;
    max_gain(root,max_sum);
    return max_sum;
}
int main()
{
	string str = "-1(3,2)"; 
	TreeNode* root=midTraceByStack (str);
	
    printf("%d\n",maxPathSum(root));
	// vector<int> v=preorderTraversal (root);
	// for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    // printf("\n");

    // root=midTraceByStack (str);

    // v=inorderTraversal (root);
	// for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    // printf("\n");

    // root=midTraceByStack (str);

    // v=postorderTraversal (root);
	// for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    // printf("\n");

	return 0;
} 