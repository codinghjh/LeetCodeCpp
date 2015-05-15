#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

vector<vector<int>> findSum(TreeNode* root, int sum, vector<int> parent)
{
	vector<vector<int>> result;
	if (root == NULL)
		return result;
	if (root->left == NULL&&root->right == NULL)
	{
		if (root->val == sum)
		{
			parent.push_back(root->val);
			result.push_back(parent);
		}
		return result;
	}
	if (root->left != NULL)
	{
		parent.push_back(root->val);
		vector<vector<int>> tmp = findSum(root->left, sum - root->val, parent);
		if (tmp.size()>0)
			for (int i = 0; i != tmp.size(); i++)
			{
				result.push_back(tmp[i]);
			}
	}
	if (root->right != NULL)
	{
		if (root->left==NULL)
			parent.push_back(root->val);
		vector<vector<int>> tmp = findSum(root->right, sum - root->val, parent);
		if (tmp.size()>0)
			for (int i = 0; i != tmp.size(); i++)
			{
				result.push_back(tmp[i]);
			}
	}
	return result;
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<int> parent;
	return findSum(root, sum, parent);
}