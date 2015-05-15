#include <iostream>
#include <vector>
#include <queue>
#include "Solutions.h"

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;
	if (root == NULL)
		return result;
	queue<TreeNode*> upLevel;
	queue<TreeNode*> nextLevel;
	bool isReverse = false;
	upLevel.push(root);
	while (!upLevel.empty())
	{
		vector<int> v1,v2;
		while (!upLevel.empty())
		{
			TreeNode* t = upLevel.front();
			upLevel.pop();
			if (t->left != NULL)
				nextLevel.push(t->left);
			if (t->right != NULL)
				nextLevel.push(t->right);
			v1.push_back(t->val);
		}
		if (isReverse)
		{
			for (int i = v1.size() - 1; i >= 0; i--)
				v2.push_back(v1[i]);
			result.push_back(v2);
		}
		else
			result.push_back(v1);
		isReverse = !isReverse;
		while (!nextLevel.empty())
		{
			upLevel.push(nextLevel.front());
			nextLevel.pop();
		}
	}
	
	return result;
}