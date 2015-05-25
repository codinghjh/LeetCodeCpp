#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;
int sum = 0;

void dfs(TreeNode* root, int val)
{
	if (root -> left == nullptr&&root->right == nullptr)
		sum = sum + val ;
	if (root->left != nullptr)
		dfs(root->left, val*10+root->left->val );
	if (root->right != nullptr)
		dfs(root->right, val * 10 + root->right->val);
}

int sumNumbers(TreeNode* root) {
	if (root == nullptr)
		return 0;
	dfs(root, root->val);
	return sum;
}