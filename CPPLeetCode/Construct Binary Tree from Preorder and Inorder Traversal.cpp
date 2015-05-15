#include <iostream>
#include <vector>
#include <stack>
#include "Solutions.h"

using namespace std;

TreeNode* createTree(vector<int>& pre, vector<int>& in, int preStart, int preEnd, int inStart, int inEnd)
{

	if (preStart>preEnd)
		return NULL;
	TreeNode* root;
	root = new TreeNode(pre[preStart]);
	if (preStart==preEnd)
	{
		return root;
	}
	int i = 0;
	for (i = inStart; (i != inEnd + 1) && (pre[preStart] != in[i]); i++);
	root->left = createTree(pre,in,preStart+1,preStart+i-inStart,inStart,i-1);
	root->right = createTree(pre,in,preStart + i - inStart+1,preEnd,i+1,inEnd);
	return root;


}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return createTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}