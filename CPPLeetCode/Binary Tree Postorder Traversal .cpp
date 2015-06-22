#include <iostream>
#include <stack>
#include <set>
#include "Solutions.h"

using namespace std;

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	if (root == nullptr)
		return result;
	stack<TreeNode*> path;
	set<TreeNode*> visited;
	visited.insert(root);
	path.push(root);
	while (!path.empty())
	{
		while (path.top()->left != nullptr&&visited.find(path.top()->left) == visited.end())
		{
			visited.insert(path.top()->left);
			path.push(path.top()->left);
		}
		if (path.top()->right == nullptr||visited.find(path.top()->right)!=visited.end())
		{
			result.push_back(path.top()->val);
			path.pop();
		}
		else
		{
			if (path.top()->right != nullptr&&visited.find(path.top()->right) == visited.end())
			{
				visited.insert(path.top()->right);
				path.push(path.top()->right);
			}
		}
	}
	return result;
}