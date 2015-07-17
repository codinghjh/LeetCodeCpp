#include <iostream>
#include <queue>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int getLeftHeight(TreeNode* root)
{
	int h = 0;
	TreeNode* cur = root;
	while (cur != nullptr)
	{
		h++;
		cur = cur->left;
	}
	return h;
}
int getRightHeight(TreeNode* root)
{
	int h = 0;
	TreeNode* cur = root;
	while (cur != nullptr)
	{
		h++;
		cur = cur->right;
	}
	return h;
}

int countNodes(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int l = getLeftHeight(root->left);
	int r = getRightHeight(root->right);
	if (l == r)
	{
		return (2 << l) - 1;
	}
	else
		return countNodes(root->left) + countNodes(root->right) + 1;
}
