#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include "Solutions.h"

using namespace std;

class BSTIterator {
private:
	TreeNode* root;
	queue<int> minValue;
	stack<TreeNode*> path;
	void rightTreeValue(TreeNode *rightNode)
	{
		stack<TreeNode*> tmpPath;
		set<TreeNode*> visited;
		TreeNode* cur = rightNode;
		tmpPath.push(cur);
		while (!tmpPath.empty())
		{
			while (tmpPath.top()->left != nullptr&&visited.find(tmpPath.top()->left)==visited.end())
			{
				visited.insert(tmpPath.top()->left);
				tmpPath.push(tmpPath.top()->left);
			}
			TreeNode* tmp = tmpPath.top();
			tmpPath.pop();
			minValue.push(tmp->val);
			if (tmp->right != nullptr)
			{
				visited.insert(tmp->right);
				tmpPath.push(tmp->right);
			}
		}
	}
	void initMinvalue()
	{
		if (root == nullptr)
			return;
		TreeNode* cur = root;
		while (cur->left != nullptr)
		{
			path.push(cur);
			cur = cur->left;
		}
		minValue.push(cur->val);
		if (cur->right!=nullptr)
			rightTreeValue(cur->right);
	}
public:
	BSTIterator(TreeNode *root) {
		if (root == nullptr)
			return;
		this->root = root;
		initMinvalue();
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (minValue.empty() && path.empty())
			return false;
		else
			return true;

	}

	/** @return the next smallest number */
	int next() {
		if (!minValue.empty())
		{
			int result = minValue.front();
			minValue.pop();
			return result;
		}
		else
		{
			TreeNode* t = path.top();
			path.pop();
			minValue.push(t->val);
			if (t->right!=nullptr)
				rightTreeValue(t->right);
			return next();
		}
	}
};
