#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

TreeNode* inAndPostTree(vector<int>& in, vector<int>& post, int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd)
		return NULL;
	TreeNode* root = new TreeNode(post[postEnd]);
	if (inStart == inEnd)
		return root;
	int i = inStart;
	for (i; (i != inEnd+1) && (in[i] != post[postEnd]);i++);
	root->left = inAndPostTree(in, post,inStart,i-1,postStart,postStart+i-inStart-1 );
	root->right = inAndPostTree(in, post,i+1,inEnd,postStart+i-inStart,postEnd-1);
	return root;
}

TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
	return inAndPostTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}