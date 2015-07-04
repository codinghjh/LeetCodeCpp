#include <iostream>
#include <queue>
#include <vector>
#include "Solutions.h"

using namespace std;

vector<int> rightSideView(TreeNode* root) {
	vector<int> result;
	if (root == nullptr)
		return result;
	queue<TreeNode*>pre;
	pre.push(root);
	while (!pre.empty())
	{
		queue<TreeNode*>cur;
		result.push_back(pre.back()->val);
		while (!pre.empty())
		{
			TreeNode* tmp = pre.front();
			pre.pop();
			if (tmp->left != nullptr)
				cur.push(tmp->left);
			if (tmp->right != nullptr)
				cur.push(tmp->right);
		}
		if (!cur.empty())
			pre = cur;
	}
	return result;
}