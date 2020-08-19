
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


struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

void mid_traverse(TreeNode* root, vector<char> & vec)
{
	if (root)
	{
		mid_traverse(root->left,vec);
		vec.push_back(root->val);
		mid_traverse(root->right,vec);
	}
}
void string_to_tree(string str)
{
	string answer = "";
	if (str.size() == 0)
	{
		return;
	}
	stack<TreeNode*> stack;
	bool dircFlag = true;

	int length = str.size();
	char currentValue = str[0];
	TreeNode* node = new TreeNode(currentValue);
	//保存根节点位置
	TreeNode* root = node;
	for (int i = 1; i < length; i++)
	{
		currentValue = str[i];
		//当前字符的四种情况
		if (currentValue == '(')
		{
			stack.push(node);
			dircFlag = true;
		}
		else if (currentValue == ')')
		{
			stack.pop();
			dircFlag = false;
		}
		else if (currentValue == ',')
		{
			dircFlag = false;
		}
		else
		{
			node = new TreeNode(currentValue);
			if (dircFlag)
			{
				stack.top()->left = node;
			}
			else
			{
				stack.top()->right = node;
			}

		}

	}
	vector<char> res;
	mid_traverse(root,res);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
}


int main()
{
	string input_str = "1(2(3,4(,5)),6(7,))";
	//string  input_str = "1(3,2(0,1))";
	string_to_tree(input_str);
	return 0;
}
