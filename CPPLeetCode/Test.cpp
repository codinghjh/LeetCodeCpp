#include <iostream>
#include <vector>
#include <set>
#include "Solutions.h"
using namespace std;

int main()
{
	TreeLinkNode* root = new TreeLinkNode(0);
	TreeLinkNode* t1 = new TreeLinkNode(1);
	TreeLinkNode* t2 = new TreeLinkNode(2);
	TreeLinkNode* t3 = new TreeLinkNode(3);
	TreeLinkNode* t4 = new TreeLinkNode(4);
	TreeLinkNode* t5 = new TreeLinkNode(5);
	TreeLinkNode* t6 = new TreeLinkNode(6);
	root->left = t1;
	root->right = t2;
	t1->left = t3;
	t1->right = t4;
	t2->left = t5;
	t2->right = t6;
	connect(root);
	return 0;
}