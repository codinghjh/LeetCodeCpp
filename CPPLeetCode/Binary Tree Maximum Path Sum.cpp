#include <iostream>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int maxPs=INT_MIN;

int calMax(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int result = root->val;
	int lmax = calMax(root->left);
	int rmax = calMax(root->right);
	result = max(root->val, max(root->val + lmax, root->val + rmax));
	if (lmax + rmax + root->val > maxPs)
		maxPs = lmax + rmax + root->val;
	if (result > maxPs)
		maxPs = result;
	return result;
}

int maxPathSum(TreeNode* root) {
	calMax(root);
	return maxPs;
}
