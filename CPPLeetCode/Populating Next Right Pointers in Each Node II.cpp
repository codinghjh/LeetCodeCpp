#include <iostream>
#include <queue>
#include "Solutions.h"

using namespace std;

void connect1(TreeLinkNode *root) {
	if (root == NULL)
		return;
	queue<TreeLinkNode*> parent;
	queue<TreeLinkNode*> child;
	parent.push(root);
	root->next = NULL;
	while (!parent.empty())
	{
		while (!parent.empty())
		{
			TreeLinkNode* treeNode = parent.front();
			parent.pop();
			if (treeNode->left != NULL)
				child.push(treeNode->left);
			if (treeNode->right != NULL)
				child.push(treeNode->right);
		}
		while (!child.empty())
		{
			TreeLinkNode* pre = child.front();
			parent.push(pre);
			child.pop();
			while (!child.empty())
			{
				pre->next = child.front();
				parent.push(child.front());
				pre = child.front();
				child.pop();
			}
		}
	}
}