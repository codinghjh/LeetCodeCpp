#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include "Solutions.h"

using namespace std;

TreeNode * cur = NULL;

void beginFlatten(TreeNode* root)
{
	if (root == NULL)
		return;
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	if (left != NULL)
	{
		cur->right = left;
		cur->left = NULL;
		cur = cur->right;
		beginFlatten(left);
	}
	if (right!=NULL)
	{
		cur->right = right;
		cur->left = NULL;
		cur = cur->right;
		beginFlatten(right);
	}

}

void flatten(TreeNode* root) {
	cur = root;
	beginFlatten(root);
}