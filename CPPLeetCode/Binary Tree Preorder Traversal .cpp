#include <iostream>
#include <stack>
#include <set>
#include "Solutions.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	set<TreeNode*> visited;
	stack<TreeNode*> path;
	if (root == nullptr)
		return result;
	path.push(root);
	visited.insert(root);
	result.push_back(root->val);
	while (!path.empty())
	{
		while ((path.top()->left != nullptr)&&(visited.find(path.top()->left)==visited.end()))
		{
			result.push_back(path.top()->left->val);
			visited.insert(path.top()->left);
			path.push(path.top()->left);
		}
		TreeNode *cur = path.top();
		path.pop();
		if (cur->right != nullptr&&visited.find(cur->right) == visited.end())
		{
			visited.insert(cur->right);
			result.push_back(cur->right->val);
			path.push(cur->right);
		}
	}
	return result;
}